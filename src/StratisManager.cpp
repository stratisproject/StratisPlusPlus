#include "StratisManager.h"

#include "pplx/pplx_utils.h"

#include <boost/algorithm/hex.hpp>

namespace stratis {

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
        .then([](std::shared_ptr<GetBalanceResponseModel> model) {
            return (uint64_t)model->getBalance();
        });
}

pplx::task<std::shared_ptr<std::vector<UTXO>>> StratisManager::getCoins()
{
    return unrealApi->unity3dGetutxosforaddressGet(this->getAddress())
        .then([](std::shared_ptr<GetUTXOsResponseModel> model) {
            const auto& utxos = model->getUTXOs();

            std::shared_ptr<std::vector<UTXO>> result(std::make_shared());
            result->reserve(utxos.size());

            for (std::shared_ptr<UTXOModel> utxo : utxos) {
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
    auto request = make_shared<SendTransactionRequest>();
    request->setHex(transactionHex);

    return unrealApi->unity3dSendTransactionPost(request)
        .then([](std::shared_ptr<WalletSendTransactionModel> model) {
            return model->getTransactionId();
        });
}

pplx::task<std::string> StratisManager::sendCoinsTransaction(
    const Address& address,
    uint64_t money)
{
    return this->getCoins()
        .then([this, address](std::shared_ptr<std::vector<UTXO>> utxos) {
            Transaction transaction(this->transactionBuilder->buildSendTransaction(
                address->value(), utxos, money));

            return this->sendRawTransaction(
                transaction.transactionId,
                transaction.transactionHex);
        });
}

pplx::task<std::string> StratisManager::sendOpReturnTransaction(
    const std::string& hexData)
{
    std::vector<uint8_t> data;
    boost::unhex(hexData, std::back_inserter(data));

    return this->sendOpReturnTransaction(data);
}

pplx::task<std::string> StratisManager::sendOpReturnTransaction(
    const std::vector<uint8_t>& data)
{
    return this->getCoins()
        .then([this, data](std::shared_ptr<std::vector<UTXO>> utxos) {
            Transaction transaction(this->transactionBuilder->buildOpReturnTransaction(
                data, utxos));

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
    return this->getCoins()
        .then([this, parameters = std::move(parameters), contractCode, money] mutable(std::shared_ptr<std::vector<UTXO>> utxos) {
            Transaction transaction(this->transactionBuilder->buildCreateContractTransaction(
                contractCode, mappedUTXOs,
                this->gasPrice, this->gasLimit,
                money, std::move(parameters)));

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
    return this->getCoins()
        .then([this, parameters = std::move(parameters), methodName, contractAddress, money] mutable(std::shared_ptr<std::vector<UTXO>> utxos) {
            Transaction transaction(this->transactionBuilder->buildCallContractTransaction(
                methodName, contractAddress, utxos,
                this->gasPrice, this->gasLimit,
                money, std::move(parameters)));

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
        requestPtr->setBlockHeight(data.blockHeight);
    }

    if (data.gasLimit.has_value()) {
        requestPtr->setGasLimit(data.gasLimit);
    }

    if (data.gasPrice.has_value()) {
        requestPtr->setGasPrice(data.gasPrice);
    }

    requestPtr->setContractAddress(data.contractAddress);
    requestPtr->setMethodName(data.methodName);
    requestPtr->setAmount(data.amount);
    requestPtr->setSender(data.sender);
    requestPtr->setParameters(data.parameters);

    return this->unrealApi->unity3dLocalCallPost(std::move(requestPtr))
        .then([](std::shared_ptr<api::model::ILocalExecutionResult> model) {
            auto returnValuePtr = model->getRReturn();
            if (returnValuePtr != nullptr && !returnValuePtr->is_null()) {
                return returnValuePtr->as_string();
            } else {
                return "";
            }
        });
}

pplx::task<void> StratisManager::waitForReceipt(
    const std::string& transactionID){
    return this->unrealApi->unity3dReceiptGet(transactionID)
        .then([transactionID, this](std::shared_ptr<ReceiptResponse> response) {
            if (response->transactionHashIsSet()) {
                return;
            } else {
                return pplx::do_while([transactionID, this]() {
                    return pplx::complete_after(5000)
                        .then([transactionID, this]() {
                            return this->unrealApi->unity3dReceiptGet(transactionID)
                                .then([](std::shared_ptr<ReceiptResponse> response) {
                                    return !response->transactionHashIsSet();
                                });
                        });
                });
            }
        })};

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
            return std::make_shared<OwnedNFTs>({model->getOwnedIDsByContractAddress()});
        });
}

} // namespace stratis