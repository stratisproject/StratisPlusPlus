// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis Plugin for Unreal Engine. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <memory>

#include "StratisNetwork.h"

namespace stratis {

class TransactionBuilder;

std::shared_ptr<TransactionBuilder>
createTransactionBuilder(const std::string& mnemonic,
                         const StratisNetwork& network);
} // namespace stratis