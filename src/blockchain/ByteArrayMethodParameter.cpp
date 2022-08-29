// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis Plugin for Unreal Engine. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "blockchain/SmartContracts/ByteArrayMethodParameter.h"

namespace stratis {
namespace smart_contracts {
namespace method_parameter {

ByteArrayMethodParameter::ByteArrayMethodParameter(const std::vector<uint8_t>& value)
    : value_(value)
{
}

ByteArrayMethodParameter::ByteArrayMethodParameter(std::vector<uint8_t>&& value)
    : value_(std::move(value))
{
}

std::vector<uint8_t> ByteArrayMethodParameter::serialize() const
{
    std::vector<uint8_t> result(value_.size() + 1);

    result[0] = (uint8_t)MethodParameter::Type::BYTE_ARRAY;

    for (size_t i = 0; i < value_.size(); i++) {
        result[i + 1] = value_[i];
    }

    return result;
}

MethodParameter::Type ByteArrayMethodParameter::type() const
{
    return MethodParameter::Type::BYTE_ARRAY;
}

} // namespace method_parameter
} // namespace smart_contracts
} // namespace stratis