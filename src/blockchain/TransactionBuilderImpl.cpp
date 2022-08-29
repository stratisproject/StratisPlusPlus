// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis Plugin for Unreal Engine. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "blockchain/TransactionBuilderImpl.h"
#include "blockchain/SmartContracts/SmartContractScriptFactoryProvider.h"
#include "blockchain/TransactionBuilderFactory.h"
#include "blockchain/Utils.h"

#include <string>
#include <vector>

namespace stratis {

TransactionBuilderImpl::TransactionBuilderImpl(const std::string& mnemonic,
                                               const StratisNetwork& network)
    : wallet_(engine::createWallet(mnemonic, coinType(network))),
      smartContractScriptFactory_(
          smart_contracts::createSmartContractScriptFactory())
{
}

std::string TransactionBuilderImpl::generateMnemonic()
{
    return wallet_->generateMnemonic();
}

void TransactionBuilderImpl::setMnemonic(const std::string& mnemonic)
{
    wallet_->setMnemonic(mnemonic);
}

void TransactionBuilderImpl::setNetwork(const StratisNetwork& network)
{
    wallet_->setCoinType(coinType(network));
}

std::string TransactionBuilderImpl::paymentAddress() const
{
    return this->wallet_->getAddress();
}

Transaction
TransactionBuilderImpl::buildSendTransaction(const std::string& destinationAddress,
                                             const std::vector<UTXO>& utxos,
                                             uint64_t amount) const
{
    return convertTransaction(
        this->wallet_->createSendCoinsTransaction(convertUTXOs(utxos), destinationAddress, amount));
}

Transaction TransactionBuilderImpl::buildOpReturnTransaction(
    const std::vector<uint8_t>& data, const std::vector<UTXO>& utxos) const
{
    return convertTransaction(this->wallet_->createOpReturnTransaction(convertUTXOs(utxos), data));
}

Transaction TransactionBuilderImpl::buildCreateContractTransaction(
    const std::string& contractCode, const std::vector<UTXO>& utxos,
    uint64_t gasPrice, uint64_t gasLimit, uint64_t amount,
    std::shared_ptr<std::vector<std::unique_ptr<smart_contracts::method_parameter::MethodParameter>>> parameters) const
{
    std::vector<uint8_t> scriptBytes =
        smartContractScriptFactory_->makeCreateSmartContractScript(
            {gasPrice,
             gasLimit,
             utils::unhex(contractCode),
             parameters});

    return convertTransaction(this->wallet_->createCustomScriptTransaction(convertUTXOs(utxos), scriptBytes, amount, gasPrice, gasLimit));
}

Transaction TransactionBuilderImpl::buildCallContractTransaction(
    const std::string& methodName, const Address& contractAddress,
    const std::vector<UTXO>& utxos, uint64_t gasPrice, uint64_t gasLimit,
    uint64_t amount,
    std::shared_ptr<std::vector<std::unique_ptr<smart_contracts::method_parameter::MethodParameter>>> parameters) const
{
    std::vector<uint8_t> scriptBytes =
        smartContractScriptFactory_->makeCallSmartContractScript(
            {gasPrice,
             gasLimit,
             contractAddress,
             methodName,
             parameters});

    return convertTransaction(this->wallet_->createCustomScriptTransaction(convertUTXOs(utxos), scriptBytes, amount, gasPrice, gasLimit));
}

TWCoinType TransactionBuilderImpl::coinType(StratisNetwork network)
{
    switch (network) {
    case STRAX:
        return TWCoinType::TWCoinTypeStrax;
    case STRAX_TEST:
        return TWCoinType::TWCoinTypeStraxTest;
    case CIRRUS:
        return TWCoinType::TWCoinTypeCirrus;
    case CIRRUS_TEST:
        return TWCoinType::TWCoinTypeCirrusTest;
    default:
        return TWCoinType::TWCoinTypeStrax;
    }
}

engine::WalletUTXOs TransactionBuilderImpl::convertUTXOs(const std::vector<UTXO>& utxos)
{
    engine::WalletUTXOs convertedUTXOs;
    convertedUTXOs.reserve(utxos.size());

    for (const auto& utxo : utxos) {
        convertedUTXOs.push_back({utxo.hash, utxo.n, utxo.satoshis});
    }

    return convertedUTXOs;
}

Transaction TransactionBuilderImpl::convertTransaction(const engine::BuiltTransaction& transaction)
{
    return {transaction.transactionHex, transaction.transactionID};
}


std::shared_ptr<TransactionBuilder>
createTransactionBuilder(const std::string& mnemonic,
                         const StratisNetwork& network)
{
    return std::make_shared<TransactionBuilderImpl>(mnemonic, network);
}

} // namespace stratis