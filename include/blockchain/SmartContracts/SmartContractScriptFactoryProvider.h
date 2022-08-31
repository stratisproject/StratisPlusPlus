// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis++ SDK. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once


#include "SmartContractScriptFactory.h"

namespace stratis {
namespace smart_contracts {

std::unique_ptr<SmartContractScriptFactory> createSmartContractScriptFactory();

} // namespace smart_contracts
} // namespace stratis