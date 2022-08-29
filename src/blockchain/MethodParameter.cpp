// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis Plugin for Unreal Engine. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "blockchain/SmartContracts/AddressMethodParameter.h"
#include "blockchain/SmartContracts/BoolMethodParameter.h"
#include "blockchain/SmartContracts/ByteArrayMethodParameter.h"
#include "blockchain/SmartContracts/IntegerMethodParameter.h"
#include "blockchain/SmartContracts/LargeUintMethodParameter.h"
#include "blockchain/SmartContracts/StringMethodParameter.h"
#include <blockchain/SmartContracts/MethodParameter.h>

namespace stratis {
namespace smart_contracts {
namespace method_parameter {

std::unique_ptr<MethodParameter> convert(bool value)
{
    return std::make_unique<BoolMethodParameter>(value);
}

std::unique_ptr<MethodParameter> convert(uint8_t value)
{
    return std::make_unique<IntegerMethodParameter<uint8_t>>(value);
}

std::unique_ptr<MethodParameter> convert(uint16_t value)
{
    return std::make_unique<IntegerMethodParameter<uint16_t>>(value);
}

std::unique_ptr<MethodParameter> convert(uint32_t value)
{
    return std::make_unique<IntegerMethodParameter<uint32_t>>(value);
}

std::unique_ptr<MethodParameter> convert(int32_t value)
{
    return std::make_unique<IntegerMethodParameter<int32_t>>(value);
}

std::unique_ptr<MethodParameter> convert(uint64_t value)
{
    return std::make_unique<IntegerMethodParameter<uint64_t>>(value);
}

std::unique_ptr<MethodParameter> convert(int64_t value)
{
    return std::make_unique<IntegerMethodParameter<int64_t>>(value);
}

std::unique_ptr<MethodParameter> convert(const UInt128& value)
{
    return std::make_unique<LargeUintMethodParameter<128>>(value);
}

std::unique_ptr<MethodParameter> convert(UInt128&& value)
{
    return std::make_unique<LargeUintMethodParameter<128>>(std::move(value));
}

std::unique_ptr<MethodParameter> convert(const UInt256& value)
{
    return std::make_unique<LargeUintMethodParameter<256>>(value);
}

std::unique_ptr<MethodParameter> convert(UInt256&& value)
{
    return std::make_unique<LargeUintMethodParameter<256>>(std::move(value));
}

std::unique_ptr<MethodParameter> convert(const char* value)
{
    return std::make_unique<StringMethodParameter>(value);
}

std::unique_ptr<MethodParameter> convert(const std::string& value)
{
    return std::make_unique<StringMethodParameter>(value);
}

std::unique_ptr<MethodParameter> convert(std::string&& value)
{
    return std::make_unique<StringMethodParameter>(std::move(value));
}

std::unique_ptr<MethodParameter> convert(const Address& value)
{
    return std::make_unique<AddressMethodParameter>(value);
}

std::unique_ptr<MethodParameter> convert(Address&& value)
{
    return std::make_unique<AddressMethodParameter>(std::move(value));
}

std::unique_ptr<MethodParameter> convert(const std::vector<uint8_t>& value)
{
    return std::make_unique<ByteArrayMethodParameter>(value);
}

std::unique_ptr<MethodParameter> convert(std::vector<uint8_t>&& value)
{
    return std::make_unique<ByteArrayMethodParameter>(std::move(value));
}

} // namespace method_parameter
} // namespace smart_contracts
} // namespace stratis