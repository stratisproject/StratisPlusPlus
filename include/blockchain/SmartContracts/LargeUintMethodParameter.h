// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis++ SDK. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "blockchain/SmartContracts/MethodParameter.h"

#include "blockchain/UIntTypes.h"

#include <iterator>

namespace stratis {
namespace smart_contracts {
namespace method_parameter {

template <int32_t BITS>
class LargeUintMethodParameter : public MethodParameter
{
public:
    static constexpr const int32_t BYTES = BITS / 8;

    LargeUintMethodParameter(const UIntType<BITS>& value) : value_(value) {}

    LargeUintMethodParameter(UIntType<BITS>&& value) : value_(std::move(value)) {}

    std::vector<uint8_t> serialize() const override
    {
        std::vector<uint8_t> result;
        result.reserve(1 + BYTES);
        result.push_back((uint8_t)type());

        boost::multiprecision::export_bits(value_.value(), std::back_inserter(result), 8);

        return result;
    }

    MethodParameter::Type type() const override;

private:
    UIntType<BITS> value_;
};

template <>
inline MethodParameter::Type LargeUintMethodParameter<128>::type() const
{
    return MethodParameter::Type::UINT128;
}

template <>
inline MethodParameter::Type LargeUintMethodParameter<256>::type() const
{
    return MethodParameter::Type::UINT256;
}

} // namespace method_parameter
} // namespace smart_contracts
} // namespace stratis