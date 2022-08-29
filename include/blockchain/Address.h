// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis Plugin for Unreal Engine. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <string>

namespace stratis {

constexpr uint32_t ADDRESS_WIDTH = 20;

class Address
{
public:
    Address(const std::string& address);
    Address(std::string&& address);

    const std::string& value() const;

private:
    std::string storage_;
};

} // namespace stratis