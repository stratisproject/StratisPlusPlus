// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis Plugin for Unreal Engine. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "blockchain/SmartContracts/MethodParameter.h"

namespace stratis {
namespace smart_contracts {
namespace method_parameter {

class StringMethodParameter : public MethodParameter
{
public:
    StringMethodParameter(const std::string& value);
    StringMethodParameter(std::string&& value);

    std::vector<uint8_t> serialize() const override;
    MethodParameter::Type type() const override;

private:
    std::string value_;
};

} // namespace method_parameter
} // namespace smart_contracts
} // namespace stratis