// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis Plugin for Unreal Engine. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "blockchain/SmartContracts/SmartContractScriptFactoryImplV1.h"
#include "blockchain/SmartContracts/MethodParameter.h"
#include "blockchain/SmartContracts/RLP.h"
#include "blockchain/SmartContracts/SmartContractScriptFactoryProvider.h"


#include "blockchain/Utils.h"

namespace stratis {
namespace smart_contracts {

namespace {

const uint8_t OP_CREATECONTRACT = 0xc0;
const uint8_t OP_CALLCONTRACT = 0xc1;

} // namespace

std::vector<uint8_t> SmartContractScriptFactoryImplV1::makeCreateSmartContractScript(const CreateContractData& data) const
{
    std::vector<uint8_t> dataSegment(
        RLP::encodeListAndItems({data.contractCode,
                                 RLP::encodeListAndItems(unwrapMethodParameters(*data.methodParameters))}));

    std::vector<uint8_t> result(makePrefix(OP_CREATECONTRACT, data.gasPrice, data.gasLimit));
    result.reserve(result.size() + dataSegment.size());

    result.insert(result.end(), dataSegment.begin(), dataSegment.end());

    return result;
}

std::vector<uint8_t> SmartContractScriptFactoryImplV1::makeCallSmartContractScript(const CallContractData& data) const
{
    std::vector<uint8_t> address(utils::asBytes(data.contractAddress));

    std::vector<uint8_t> dataSegment(
        RLP::encodeListAndItems({utils::asBytes(data.methodName),
                                 RLP::encodeListAndItems(unwrapMethodParameters(*data.methodParameters))}));

    std::vector<uint8_t> result(makePrefix(OP_CALLCONTRACT, data.gasPrice, data.gasLimit));
    result.reserve(result.size() + address.size() + dataSegment.size());

    result.insert(result.end(), address.begin(), address.end());
    result.insert(result.end(), dataSegment.begin(), dataSegment.end());

    return result;
}

std::vector<uint8_t> SmartContractScriptFactoryImplV1::makePrefix(uint8_t op, uint64_t gasPrice, uint64_t gasLimit) const
{
    std::vector<uint8_t> result{op};

    std::vector<uint8_t> vmVersionBytes(utils::asBytes(1));
    std::vector<uint8_t> gasPriceBytes(utils::asBytes(gasPrice));
    std::vector<uint8_t> gasLimitBytes(utils::asBytes(gasLimit));

    result.insert(result.end(), vmVersionBytes.begin(), vmVersionBytes.end());
    result.insert(result.end(), gasPriceBytes.begin(), gasPriceBytes.end());
    result.insert(result.end(), gasLimitBytes.begin(), gasLimitBytes.end());

    return result;
}

std::vector<std::vector<uint8_t>> SmartContractScriptFactoryImplV1::unwrapMethodParameters(const std::vector<std::unique_ptr<method_parameter::MethodParameter>>& methodParameters) const
{
    std::vector<std::vector<uint8_t>> result(methodParameters.size());

    for (size_t i = 0; i < result.size(); i++) {
        result[i] = methodParameters[i]->serialize();
    }

    return result;
}

std::unique_ptr<SmartContractScriptFactory> createSmartContractScriptFactory()
{
    return std::make_unique<SmartContractScriptFactoryImplV1>();
}

} // namespace smart_contracts
} // namespace stratis