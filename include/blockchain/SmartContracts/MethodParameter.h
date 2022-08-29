// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis Plugin for Unreal Engine. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "blockchain/Address.h"
#include "blockchain/UIntTypes.h"

#include <memory>
#include <type_traits>
#include <vector>

namespace stratis {
namespace smart_contracts {
namespace method_parameter {

class MethodParameter
{
public:
    enum class Type : uint8_t {
        BOOL = 1,
        BYTE = 2,
        CHAR = 3,
        STRING = 4,
        UINT = 5,
        INT = 6,
        ULONG = 7,
        LONG = 8,
        ADDRESS = 9,
        BYTE_ARRAY = 10,
        UINT128 = 11,
        UINT256 = 12
    };

    virtual ~MethodParameter(){};

    virtual std::vector<uint8_t> serialize() const = 0;
    virtual Type type() const = 0;
};

std::unique_ptr<MethodParameter> convert(bool value);

std::unique_ptr<MethodParameter> convert(uint8_t value);
std::unique_ptr<MethodParameter> convert(uint16_t value);
std::unique_ptr<MethodParameter> convert(uint32_t value);
std::unique_ptr<MethodParameter> convert(int32_t value);
std::unique_ptr<MethodParameter> convert(uint64_t value);
std::unique_ptr<MethodParameter> convert(int64_t value);

std::unique_ptr<MethodParameter> convert(const UInt128& value);
std::unique_ptr<MethodParameter> convert(UInt128&& value);
std::unique_ptr<MethodParameter> convert(const UInt256& value);
std::unique_ptr<MethodParameter> convert(UInt256&& value);

std::unique_ptr<MethodParameter> convert(const char* value);
std::unique_ptr<MethodParameter> convert(const std::string& value);
std::unique_ptr<MethodParameter> convert(std::string&& value);

std::unique_ptr<MethodParameter> convert(const Address& value);
std::unique_ptr<MethodParameter> convert(Address&& value);

std::unique_ptr<MethodParameter> convert(const std::vector<uint8_t>& value);
std::unique_ptr<MethodParameter> convert(std::vector<uint8_t>&& value);

std::unique_ptr<MethodParameter> parseFromString(const std::string& encodedValue);

} // namespace method_parameter

} // namespace smart_contracts

} // namespace stratis