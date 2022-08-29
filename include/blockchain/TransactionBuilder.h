// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis Plugin for Unreal Engine. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "StratisNetwork.h"
#include "Transaction.h"
#include "UTXO.h"
#include "blockchain/SmartContracts/MethodParameter.h"

namespace stratis {

class TransactionBuilder
{
public:
    virtual ~TransactionBuilder() = 0;

    virtual std::string generateMnemonic() = 0;

    virtual void setMnemonic(const std::string& mnemonic) = 0;
    virtual void setNetwork(const StratisNetwork& network) = 0;

    virtual std::string paymentAddress() const = 0;

    virtual Transaction buildSendTransaction(const std::string& destinationAddress,
                                             const std::vector<UTXO>& utxos,
                                             uint64_t amount) const = 0;

    virtual Transaction buildOpReturnTransaction(const std::vector<uint8_t>& data,
                                                 const std::vector<UTXO>& utxos) const = 0;

    virtual Transaction buildCreateContractTransaction(
        const std::string& contractCode, const std::vector<UTXO>& utxos,
        uint64_t gasPrice, uint64_t gasLimit, uint64_t amount = 0,
        std::shared_ptr<std::vector<std::unique_ptr<smart_contracts::method_parameter::MethodParameter>>> parameters = nullptr) const = 0;

    virtual Transaction buildCallContractTransaction(
        const std::string& methodName, const Address& contractAddress,
        const std::vector<UTXO>& utxos, uint64_t gasPrice, uint64_t gasLimit,
        uint64_t amount = 0,
        std::shared_ptr<std::vector<std::unique_ptr<smart_contracts::method_parameter::MethodParameter>>> parameters = nullptr) const = 0;
};

} // namespace stratis