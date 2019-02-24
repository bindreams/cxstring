#pragma once
#include "cxstring.hpp"

namespace zh {

template<std::size_t N1, std::size_t N2>
constexpr bool operator==(const cxstring<N1>& lhs, const cxstring<N2>& rhs);
template<std::size_t N1, std::size_t N2>
constexpr bool operator!=(const cxstring<N1>& lhs, const cxstring<N2>& rhs);
template<std::size_t N1, std::size_t N2>
constexpr bool operator< (const cxstring<N1>& lhs, const cxstring<N2>& rhs);
template<std::size_t N1, std::size_t N2>
constexpr bool operator<=(const cxstring<N1>& lhs, const cxstring<N2>& rhs);
template<std::size_t N1, std::size_t N2>
constexpr bool operator> (const cxstring<N1>& lhs, const cxstring<N2>& rhs);
template<std::size_t N1, std::size_t N2>
constexpr bool operator>=(const cxstring<N1>& lhs, const cxstring<N2>& rhs);

} // namespace zh

#include "compare_operators.inl"