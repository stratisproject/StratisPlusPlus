// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "engine/Data.h"

#include <algorithm>
namespace TW {

Data subData(const Data& data, size_t startIndex, size_t length)
{
    size_t subLength = length;
    if (startIndex + subLength > data.size()) {
        subLength = data.size() - startIndex;
    } // guard against over-length
    return TW::data(data.data() + startIndex, subLength);
}

Data subData(const Data& data, size_t startIndex)
{
    size_t subLength = data.size() - startIndex;
    return TW::data(data.data() + startIndex, subLength);
}

Data reverse(const Data& data)
{
    Data buffer(data);
    std::reverse(buffer.begin(), buffer.end());
    return buffer;
}

} // namespace TW
