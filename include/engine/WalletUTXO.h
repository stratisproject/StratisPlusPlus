// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis++ SDK. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace stratis {
namespace engine {

struct WalletUTXO {
    std::string hash;
    uint32_t n;
    uint64_t satoshis;
};

class WalletUTXOs : public std::vector<WalletUTXO>
{
public:
    WalletUTXOs() = default;
    WalletUTXOs(const std::vector<WalletUTXO>& vector) : std::vector<WalletUTXO>(vector) {}
    WalletUTXOs(WalletUTXO utxo) : std::vector<WalletUTXO>({utxo}) {}
};

} // namespace engine
} // namespace stratis