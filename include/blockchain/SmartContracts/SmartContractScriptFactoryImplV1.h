// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis++ SDK. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "blockchain/SmartContracts/MethodParameter.h"
#include "blockchain/SmartContracts/SmartContractScriptFactory.h"


namespace stratis {
namespace smart_contracts {

class SmartContractScriptFactoryImplV1 : public SmartContractScriptFactory
{
public:
    std::vector<uint8_t> makeCreateSmartContractScript(const CreateContractData& data) const override;
    std::vector<uint8_t> makeCallSmartContractScript(const CallContractData& data) const override;

private:
    std::vector<uint8_t> makePrefix(uint8_t op, uint64_t gasPrice, uint64_t gasLimit) const;
    std::vector<std::vector<uint8_t>> unwrapMethodParameters(const std::vector<std::unique_ptr<method_parameter::MethodParameter>>& methodParameters) const;
};

} // namespace smart_contracts
} // namespace stratis