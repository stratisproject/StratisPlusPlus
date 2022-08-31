// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis++ SDK. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once


#include "MethodParameter.h"

namespace stratis {
namespace smart_contracts {

struct CreateContractData {
    uint64_t gasPrice;
    uint64_t gasLimit;

    std::vector<uint8_t> contractCode;

    std::shared_ptr<std::vector<std::unique_ptr<method_parameter::MethodParameter>>> methodParameters;
};

} // namespace smart_contracts
} // namespace stratis