// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis++ SDK. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once


#include "blockchain/Address.h"
#include "blockchain/SmartContracts/MethodParameter.h"

namespace stratis {
namespace smart_contracts {

struct CallContractData {
    uint64_t gasPrice;
    uint64_t gasLimit;

    Address contractAddress;
    std::string methodName;

    std::shared_ptr<std::vector<std::unique_ptr<method_parameter::MethodParameter>>> methodParameters;
};

} // namespace smart_contracts
} // namespace stratis