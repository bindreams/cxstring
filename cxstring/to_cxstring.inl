#pragma once
#include <type_traits>
#include "cxstring.hpp"
#include "to_cxstring.hpp"

namespace zh {

template<auto X>
constexpr auto to_cxstring() {
	static_assert(std::is_integral_v<decltype(X)>, "to_cxstring: not integral");
	
	if constexpr (X < 0) {
		return cxstring("-") + to_cxstring<-X>();
	}
	else if constexpr (X >= 10) {
		return to_cxstring<X/10>() + to_cxstring<X%10>();
	}
	else {
		switch (X) {
			case 0: return cxstring("0");
			case 1: return cxstring("1");
			case 2: return cxstring("2");
			case 3: return cxstring("3");
			case 4: return cxstring("4");
			case 5: return cxstring("5");
			case 6: return cxstring("6");
			case 7: return cxstring("7");
			case 8: return cxstring("8");
			case 9: return cxstring("9");
		}
	}
}

} // namespace zh