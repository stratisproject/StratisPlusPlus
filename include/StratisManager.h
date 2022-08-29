#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include <pplx/pplxtasks.h>

#include "blockchain/Address.h"
#include "blockchain/LocalCallData.h"
#include "blockchain/OwnedNFTs.h"
#include "blockchain/TransactionBuilder.h"
#include "blockchain/UTXO.h"

#include "lightweightapi/api/UnrealApi.h"

namespace stratis {

class StratisManager
{
public:
    StratisManager(
        std::shared_ptr<stratis::api::UnrealApi> unrealApi,
        std::shared_ptr<TransactionBuilder> transactionBuilder);

    StratisManager(
        std::shared_ptr<stratis::api::UnrealApi> unrealApi,
        std::shared_ptr<TransactionBuilder> transactionBuilder,
        uint64_t gasPrice,
        uint64_t gasLimit,
        uint64_t defaultFee);

    std::string generateMnemonic() const;
    std::string getAddress() const;

    pplx::task<uint64_t> getBalance();

    pplx::task<std::shared_ptr<std::vector<UTXO>>> getCoins();

    pplx::task<std::string> sendRawTransaction(
        const std::string& transactionID,
        const std::string& transactionHex);

    pplx::task<std::string> sendCoinsTransaction(
        const Address& address,
        uint64_t money);

    pplx::task<std::string> sendOpReturnTransaction(
        const std::string& hexData);

    pplx::task<std::string> sendOpReturnTransaction(
        const std::vector<uint8_t>& data);

    pplx::task<std::string> sendCreateContractTransaction(
        const std::string& contractCode,
        const std::vector<std::string>& parameters,
        uint64_t money);

    pplx::task<std::string> sendCreateContractTransaction(
        const std::string& contractCode,
        std::vector<std::unique_ptr<smart_contracts::method_parameter::MethodParameter>>&& parameters,
        uint64_t money);

    pplx::task<std::string> sendCallContractTransaction(
        const Address& contractAddress,
        const std::string& methodName,
        const std::vector<std::string>& parameters,
        uint64_t money);

    pplx::task<std::string> sendCallContractTransaction(
        const Address& contractAddress,
        const std::string& methodName,
        std::vector<std::unique_ptr<smart_contracts::method_parameter::MethodParameter>>&& parameters,
        uint64_t money);

    pplx::task<std::string> makeLocalCall(
        const LocalCallData& data);

    pplx::task<void> waitForReceipt(
        const std::string& transactionID);

    pplx::task<void> watchNFTContract(
        const Address& contractAddress);

    pplx::task<std::shared_ptr<OwnedNFTs>> getOwnedNFTs(
        const Address& address);

private:
    uint64_t gasPrice;
    uint64_t gasLimit;
    uint64_t defaultFee;

    std::shared_ptr<TransactionBuilder> transactionBuilder;
    std::shared_ptr<stratis::api::UnrealApi> unrealApi;
};

} // namespace stratis