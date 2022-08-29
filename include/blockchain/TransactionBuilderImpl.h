// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis Plugin for Unreal Engine. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "blockchain/SmartContracts/SmartContractScriptFactory.h"
#include "blockchain/TransactionBuilder.h"

#include "engine/TWCoinType.h"
#include "engine/Wallet.h"
#include "engine/WalletUTXO.h"

namespace stratis {

class TransactionBuilderImpl : public TransactionBuilder
{
public:
    TransactionBuilderImpl(const std::string& mnemonic,
                           const StratisNetwork& network);
    virtual ~TransactionBuilderImpl() {}

    std::string generateMnemonic() override;

    void setMnemonic(const std::string& mnemonic) override;
    void setNetwork(const StratisNetwork& network) override;

    std::string paymentAddress() const override;

    Transaction buildSendTransaction(const std::string& destinationAddress,
                                     const std::vector<UTXO>& utxos, uint64_t amount) const override;

    Transaction buildOpReturnTransaction(const std::vector<uint8_t>& data,
                                         const std::vector<UTXO>& utxos) const override;

    Transaction buildCreateContractTransaction(
        const std::string& contractCode, const std::vector<UTXO>& utxos,
        uint64_t gasPrice, uint64_t gasLimit, uint64_t amount,
        std::shared_ptr<std::vector<std::unique_ptr<smart_contracts::method_parameter::MethodParameter>>> parameters) const override;

    Transaction buildCallContractTransaction(
        const std::string& methodName, const Address& contractAddress,
        const std::vector<UTXO>& utxos, uint64_t gasPrice, uint64_t gasLimit,
        uint64_t amount,
        std::shared_ptr<std::vector<std::unique_ptr<smart_contracts::method_parameter::MethodParameter>>> parameters) const override;

private:
    static TWCoinType coinType(StratisNetwork network);
    static engine::WalletUTXOs convertUTXOs(const std::vector<UTXO>& utxos);
    static Transaction convertTransaction(const engine::BuiltTransaction& transaction);

    std::shared_ptr<engine::Wallet> wallet_;

    std::unique_ptr<smart_contracts::SmartContractScriptFactory>
        smartContractScriptFactory_;
};

} // namespace stratis