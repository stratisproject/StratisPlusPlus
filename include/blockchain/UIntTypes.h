// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis++ SDK. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <boost/multiprecision/cpp_int.hpp>

namespace stratis {

template <int32_t BITS>
class UIntType
{
public:
    UIntType(const boost::multiprecision::number<boost::multiprecision::cpp_int_backend<BITS, BITS, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>& data)
        : data_(data)
    {
    }

    UIntType(boost::multiprecision::number<boost::multiprecision::cpp_int_backend<BITS, BITS, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>&& data)
        : data_(std::move(data))
    {
    }

    UIntType(const std::string& encoded) : data_(encoded)
    {
    }

    const boost::multiprecision::number<boost::multiprecision::cpp_int_backend<BITS, BITS, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>& value() const
    {
        return data_;
    }

private:
    boost::multiprecision::number<boost::multiprecision::cpp_int_backend<BITS, BITS, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>> data_;
};

using UInt128 = UIntType<128>;
using UInt256 = UIntType<256>;

} // namespace stratis