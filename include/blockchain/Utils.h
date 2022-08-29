// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis Plugin for Unreal Engine. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Address.h"
#include "Transaction.h"

#include "engine/AddressUtils.h"
#include "engine/Data.h"
#include "engine/HexCoding.h"

#include <string>
#include <vector>

#include <boost/algorithm/hex.hpp>

namespace stratis {
namespace utils {

inline std::vector<uint8_t> unhex(const std::string& value)
{
    std::vector<uint8_t> data;
    boost::algorithm::unhex(value, std::back_inserter(data));
    return data;
}

inline std::vector<uint8_t> asBytes(const Address& value)
{
    return TW::addressToHex(value.value());
}

inline std::vector<uint8_t> asBytes(const std::string& value)
{
    std::vector<uint8_t> bytes(value.size());
    for (size_t i = 0; i < bytes.size(); i++) {
        bytes[i] = value[i];
    }

    return bytes;
}

template <typename Integer,
          std::enable_if_t<std::is_integral<Integer>::value, bool> = true>
inline std::vector<uint8_t> asBytes(Integer value)
{
    std::vector<uint8_t> result(sizeof(Integer));

    for (size_t i = 0; i < sizeof(Integer); i++) {
        result[i] = (value >> (i * 8)) & 0xFF;
    }

    return result;
}

template <typename Integer,
          std::enable_if_t<std::is_integral<Integer>::value, bool> = true>
inline void asBytes(std::vector<uint8_t>& output, Integer value)
{
    size_t initialSize = output.size();

    output.resize(initialSize + sizeof(Integer));

    for (size_t i = 0; i < sizeof(Integer); i++) {
        output[i + initialSize] = (value >> (i * 8)) & 0xFF;
    }
}

} // namespace utils
} // namespace stratis