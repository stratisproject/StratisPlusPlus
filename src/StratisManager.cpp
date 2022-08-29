#include "StratisManager.h"

#include "pplx/pplx_utils.h"

#include <boost/algorithm/hex.hpp>

#include <memory>

namespace {

constexpr uint64_t DEFAULT_GAS_PRICE = 100;
constexpr uint64_t DEFAULT_GAS_LIMIT = 150000;
constexpr uint64_t DEFAULT_FEE = 10000;

} // namespace

namespace stratis {

StratisManager::StratisManager(
    std::shared_ptr<stratis::api::UnrealApi> unrealApi,
    std::shared_ptr<TransactionBuilder> transactionBuilder)
    : StratisManager(
          unrealApi,
          transactionBuilder,
          DEFAULT_GAS_PRICE,
          DEFAULT_GAS_LIMIT,
          DEFAULT_FEE)
{
}

StratisManager::StratisManager(
    std::shared_ptr<stratis::api::UnrealApi> unrealApi,
    std::shared_ptr<TransactionBuilder> transactionBuilder,
    uint64_t gasPrice,
    uint64_t gasLimit,
    uint64_t defaultFee)
    : unrealApi(unrealApi),
      transactionBuilder(transactionBuilder),
      gasPrice(gasPrice),
      gasLimit(gasLimit),
      defaultFee(defaultFee)
{
}

std::string StratisManager::generateMnemonic() const
{
    return transactionBuilder->generateMnemonic();
}

std::string StratisManager::getAddress() const
{
    return transactionBuilder->paymentAddress();
}

pplx::task<uint64_t> StratisManager::getBalance()
{
    return unrealApi->unity3dGetaddressbalanceGet(this->getAddress())
        .then([](std::shared_ptr<api::model::GetBalanceResponseModel> model) {
            return (uint64_t)model->getBalance();
        });
}

pplx::task<std::shared_ptr<std::vector<UTXO>>> StratisManager::getCoins()
{
    return unrealApi->unity3dGetutxosforaddressGet(this->getAddress())
        .then([](std::shared_ptr<api::model::GetUTXOsResponseModel> model) {
            const auto& utxos = model->getUTXOs();

            std::shared_ptr<std::vector<UTXO>> result(std::make_shared<std::vector<UTXO>>());
            result->reserve(utxos.size());

            for (std::shared_ptr<api::model::UTXOModel> utxo : utxos) {
                result->push_back({utxo->getHash(),
                                   (uint32_t)utxo->getN(),
                                   (uint64_t)utxo->getSatoshis()});
            }

            return result;
        });
}

pplx::task<std::string> StratisManager::sendRawTransaction(
    const std::string& transactionID,
    const std::string& transactionHex)
{
    auto request = std::make_shared<api::model::SendTransactionRequest>();
    request->setHex(transactionHex);

    return unrealApi->unity3dSendTransactionPost(request)
        .then([](std::shared_ptr<api::model::WalletSendTransactionModel> model) {
            return model->getTransactionId();
        });
}

pplx::task<std::string> StratisManager::sendCoinsTransaction(
    const Address& address,
    uint64_t money)
{
    return this->getCoins()
        .then([this, address, money](std::shared_ptr<std::vector<UTXO>> utxos) {
            const std::vector<UTXO>& constRefUtxos = *utxos;
            Transaction transaction(this->transactionBuilder->buildSendTransaction(
                address.value(), constRefUtxos, money));

            return this->sendRawTransaction(
                transaction.transactionId,
                transaction.transactionHex);
        });
}

pplx::task<std::string> StratisManager::sendOpReturnTransaction(
    const std::string& hexData)
{
    std::vector<uint8_t> data;
    boost::algorithm::unhex(hexData, std::back_inserter(data));

    return this->sendOpReturnTransaction(data);
}

pplx::task<std::string> StratisManager::sendOpReturnTransaction(
    const std::vector<uint8_t>& data)
{
    return this->getCoins()
        .then([this, data](std::shared_ptr<std::vector<UTXO>> utxos) {
            const std::vector<UTXO>& constRefUtxos = *utxos;
            Transaction transaction(this->transactionBuilder->buildOpReturnTransaction(
                data, constRefUtxos));

            return this->sendRawTransaction(
                transaction.transactionId,
                transaction.transactionHex);
        });
}

pplx::task<std::string> StratisManager::sendCreateContractTransaction(
    const std::string& contractCode,
    const std::vector<std::string>& parameters,
    uint64_t money)
{
    std::vector<std::unique_ptr<smart_contracts::method_parameter::MethodParameter>> parsedParameters;
    parsedParameters.reserve(parameters.size());

    for (const std::string& parameter : parameters) {
        parsedParameters.push_back(smart_contracts::method_parameter::parseFromString(parameter));
    }

    return this->sendCreateContractTransaction(
        contractCode, std::move(parsedParameters), money);
}

pplx::task<std::string> StratisManager::sendCreateContractTransaction(
    const std::string& contractCode,
    std::vector<std::unique_ptr<smart_contracts::method_parameter::MethodParameter>>&& parameters,
    uint64_t money)
{
    auto params = std::make_shared<std::vector<std::unique_ptr<smart_contracts::method_parameter::MethodParameter>>>(std::move(parameters));

    return this->getCoins()
        .then(
            [this, params, contractCode, money](std::shared_ptr<std::vector<UTXO>> utxos) {
                const std::vector<UTXO>& constRefUtxos = *utxos;
                Transaction transaction(this->transactionBuilder->buildCreateContractTransaction(
                    contractCode, constRefUtxos,
                    this->gasPrice, this->gasLimit,
                    money, params));

                return this->sendRawTransaction(
                    transaction.transactionId,
                    transaction.transactionHex);
            });
}

pplx::task<std::string> StratisManager::sendCallContractTransaction(
    const Address& contractAddress,
    const std::string& methodName,
    const std::vector<std::string>& parameters,
    uint64_t money)
{
    std::vector<std::unique_ptr<smart_contracts::method_parameter::MethodParameter>> parsedParameters;
    parsedParameters.reserve(parameters.size());

    for (const std::string& parameter : parameters) {
        parsedParameters.push_back(smart_contracts::method_parameter::parseFromString(parameter));
    }

    return this->sendCallContractTransaction(
        contractAddress, methodName, std::move(parsedParameters), money);
}

pplx::task<std::string> StratisManager::sendCallContractTransaction(
    const Address& contractAddress,
    const std::string& methodName,
    std::vector<std::unique_ptr<smart_contracts::method_parameter::MethodParameter>>&& parameters,
    uint64_t money)
{
    auto params = std::make_shared<std::vector<std::unique_ptr<smart_contracts::method_parameter::MethodParameter>>>(std::move(parameters));
    return this->getCoins()
        .then([this, params, methodName, contractAddress, money](std::shared_ptr<std::vector<UTXO>> utxos) mutable {
            const std::vector<UTXO>& constRefUtxos = *utxos;
            Transaction transaction(this->transactionBuilder->buildCallContractTransaction(
                methodName, contractAddress, constRefUtxos,
                this->gasPrice, this->gasLimit,
                money, params));

            return this->sendRawTransaction(
                transaction.transactionId,
                transaction.transactionHex);
        });
}

pplx::task<std::string> StratisManager::makeLocalCall(
    const LocalCallData& data)
{
    std::shared_ptr<api::model::LocalCallContractRequest> requestPtr(
        std::make_shared<api::model::LocalCallContractRequest>());

    if (data.blockHeight.has_value()) {
        requestPtr->setBlockHeight((int64_t)data.blockHeight.get());
    }

    if (data.gasLimit.has_value()) {
        requestPtr->setGasLimit((int64_t)data.gasLimit.get());
    }

    if (data.gasPrice.has_value()) {
        requestPtr->setGasPrice((int64_t)data.gasPrice.get());
    }

    requestPtr->setContractAddress(data.contractAddress);
    requestPtr->setMethodName(data.methodName);
    requestPtr->setAmount(data.amount);
    requestPtr->setSender(data.sender);
    requestPtr->setParameters(data.parameters);

    return this->unrealApi->unity3dLocalCallPost(std::move(requestPtr))
        .then([](std::shared_ptr<api::model::ILocalExecutionResult> model) {
            auto returnValuePtr = model->getRReturn();
            if (returnValuePtr != nullptr) {
                auto value = returnValuePtr->toJson();
                if (!value.is_null()) {
                    std::string stringValue(value.as_string());
                    return stringValue;
                }
            }
            std::string value("");
            return value;
        });
}

pplx::task<void> StratisManager::waitForReceipt(
    const std::string& transactionID)
{
    return this->unrealApi->unity3dReceiptGet(transactionID)
        .then([transactionID, this](std::shared_ptr<api::model::ReceiptResponse> response) {
            if (!response->transactionHashIsSet()) {
                return pplx::do_while([transactionID, this]() {
                    return pplx::complete_after(5000)
                        .then([transactionID, this]() {
                            return this->unrealApi->unity3dReceiptGet(transactionID)
                                .then([](std::shared_ptr<api::model::ReceiptResponse> response) {
                                    return !response->transactionHashIsSet();
                                });
                        });
                });
            }
        });
}

pplx::task<void> StratisManager::watchNFTContract(
    const Address& contractAddress)
{
    return unrealApi->unity3dWatchNftContractGet(contractAddress.value());
}

pplx::task<std::shared_ptr<OwnedNFTs>> StratisManager::getOwnedNFTs(
    const Address& address)
{
    return unrealApi->unity3dGetOwnedNftsGet(address.value())
        .then([](std::shared_ptr<api::model::OwnedNFTsModel> model) {
            model->getOwnedIDsByContractAddress();
            std::shared_ptr<OwnedNFTs> ownedNFTs(std::make_shared<OwnedNFTs>());
            return ownedNFTs;
        });
}

} // namespace stratis