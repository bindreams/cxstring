#pragma once
#include <algorithm>
#include "compare_operators.hpp"

namespace zh {

template<std::size_t N1, std::size_t N2>
constexpr bool operator==(const cxstring<N1>& lhs, const cxstring<N2>& rhs) {
	// For a cxstring, being "blank" (filled with one or more '\0' chars) is not
	// a normal state. cxstring's size is defined by it's template parameter,
	// and not by contents. Thus, a half filled cxstring<6> that contains "fox"
	// is NOT equal to a proper cxstring<3> containing "fox".
	if constexpr (N1 != N2) return false;
	
	for (std::size_t i = 0; i < N1; ++i) {
		if (lhs[i] != rhs[i]) return false;
	}
	return true;
}

template<std::size_t N1, std::size_t N2>
constexpr bool operator!=(const cxstring<N1>& lhs, const cxstring<N2>& rhs) {
	return !(lhs == rhs);
}

template<std::size_t N1, std::size_t N2>
constexpr bool operator< (const cxstring<N1>& lhs, const cxstring<N2>& rhs) {
	for (std::size_t i = 0; i < std::min(N1, N2); ++i) {
		if (lhs[i] < rhs[i]) return true;
		if (lhs[i] > rhs[i]) return false;
	}
	
	if (N1 < N2) return true;
	return false;
}

template<std::size_t N1, std::size_t N2>
constexpr bool operator<=(const cxstring<N1>& lhs, const cxstring<N2>& rhs) {
	return !(lhs > rhs);
}

template<std::size_t N1, std::size_t N2>
constexpr bool operator> (const cxstring<N1>& lhs, const cxstring<N2>& rhs) {
	return rhs < lhs;
}

template<std::size_t N1, std::size_t N2>
constexpr bool operator>=(const cxstring<N1>& lhs, const cxstring<N2>& rhs) {
	return !(lhs < rhs);
}

} // namespace zh