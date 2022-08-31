// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis++ SDK. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include <boost/optional.hpp>

namespace stratis {

struct LocalCallData {
    std::string contractAddress;
    std::string methodName;

    boost::optional<uint64_t> gasPrice;
    boost::optional<uint64_t> gasLimit;

    std::string amount;
    std::string sender;

    boost::optional<uint64_t> blockHeight;

    std::vector<std::string> parameters;
};

} // namespace stratis