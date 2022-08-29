// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis Plugin for Unreal Engine. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "blockchain/Address.h"

namespace stratis {

Address::Address(const std::string& address) : storage_(address)
{
}

Address::Address(std::string&& address) : storage_(std::move(address))
{
}

const std::string& Address::value() const
{
    return storage_;
}

} // namespace stratis