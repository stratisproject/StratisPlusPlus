// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis++ SDK. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "blockchain/SmartContracts/StringMethodParameter.h"

#include "blockchain/Utils.h"

namespace stratis {
namespace smart_contracts {
namespace method_parameter {

StringMethodParameter::StringMethodParameter(const std::string& value)
    : value_(value)
{
}

StringMethodParameter::StringMethodParameter(std::string&& value)
    : value_(std::move(value))
{
}

std::vector<uint8_t> StringMethodParameter::serialize() const
{
    std::vector<uint8_t> bytes(utils::asBytes(value_));

    std::vector<uint8_t> result{(uint8_t)MethodParameter::Type::STRING};
    result.insert(result.end(), bytes.begin(), bytes.end());

    return result;
}

MethodParameter::Type StringMethodParameter::type() const
{
    return MethodParameter::Type::STRING;
}

} // namespace method_parameter
} // namespace smart_contracts
} // namespace stratis