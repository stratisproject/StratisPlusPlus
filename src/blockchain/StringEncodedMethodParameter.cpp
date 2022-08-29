// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis Plugin for Unreal Engine. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include <blockchain/SmartContracts/MethodParameter.h>

#include <boost/algorithm/hex.hpp>
#include <boost/algorithm/string.hpp>


namespace stratis {
namespace smart_contracts {
namespace method_parameter {

std::unique_ptr<MethodParameter> parseFromString(const std::string& encodedValue)
{
    std::vector<std::string> tokens;
    boost::split(tokens, encodedValue, boost::is_any_of("#"));

    if (tokens.size() != 2) return nullptr;

    int32_t type = std::stoi(tokens[0]);

    switch (type) {
    case (int32_t)MethodParameter::Type::BOOL:
        if (boost::iequals(tokens[1], "true"))
            return convert(true);
        else
            return convert(false);

    case (int32_t)MethodParameter::Type::BYTE: {
        int32_t value = std::stoi(tokens[1]);
        return convert((uint8_t)value);
    }

    case (int32_t)MethodParameter::Type::CHAR:
        return convert((uint16_t)tokens[1][0]);

    case (int32_t)MethodParameter::Type::STRING:
        return convert(tokens[1]);

    case (int32_t)MethodParameter::Type::UINT: {
        int64_t value = std::stoul(tokens[1]);
        return convert((uint32_t)value);
    }

    case (int32_t)MethodParameter::Type::INT: {
        int32_t value = std::stol(tokens[1]);
        return convert((int32_t)value);
    }

    case (int32_t)MethodParameter::Type::ULONG: {
        uint64_t value = std::stoull(tokens[1]);
        return convert((uint64_t)value);
    }

    case (int32_t)MethodParameter::Type::LONG: {
        int64_t value = std::stoll(tokens[1]);
        return convert((int64_t)value);
    }
    case (int32_t)MethodParameter::Type::ADDRESS: {
        return convert(Address(std::move(tokens[1])));
    }
    case (int32_t)MethodParameter::Type::BYTE_ARRAY: {
        std::vector<uint8_t> bytes;
        boost::algorithm::unhex(tokens[1], std::back_inserter(bytes));
        return convert(std::move(bytes));
    }

    case (int32_t)MethodParameter::Type::UINT128:
        return convert(UInt128(tokens[1]));

    case (int32_t)MethodParameter::Type::UINT256:
        return convert(UInt256(tokens[1]));

    default:
        break;
    }

    return nullptr;
}

} // namespace method_parameter
} // namespace smart_contracts
} // namespace stratis