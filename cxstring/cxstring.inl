#pragma once
#include "cxstring.hpp"

namespace zh {

namespace detail {
	constexpr std::size_t strlen(const char* str) {
		std::size_t result = 0;
		for (; str[result] != 0; ++result);
		return result;
	}
}

template<size_t N>
constexpr cxstring<N> cxstring<N>::blank() {
	return cxstring{{}};
}

template<size_t N>
constexpr typename cxstring<N>::iterator
cxstring<N>::begin() noexcept {
	return &m_data[0];
}

template<size_t N>
constexpr typename cxstring<N>::const_iterator
cxstring<N>::begin() const noexcept {
	return &m_data[0];
}

template<size_t N>
constexpr typename cxstring<N>::const_iterator
cxstring<N>::cbegin() const noexcept {
	return &m_data[0];
}

template<size_t N>
constexpr typename cxstring<N>::iterator
cxstring<N>::end() noexcept {
	return &m_data[N];
}

template<size_t N>
constexpr typename cxstring<N>::const_iterator
cxstring<N>::end() const noexcept {
	return &m_data[N];
}

template<size_t N>
constexpr typename cxstring<N>::const_iterator
cxstring<N>::cend() const noexcept {
	return &m_data[N];
}

template<size_t N>
constexpr typename cxstring<N>::reverse_iterator
cxstring<N>::rbegin() noexcept {
	return reverse_iterator(end());
}

template<size_t N>
constexpr typename cxstring<N>::const_reverse_iterator
cxstring<N>::rbegin() const noexcept {
	return const_reverse_iterator(end());
}

template<size_t N>
constexpr typename cxstring<N>::const_reverse_iterator
cxstring<N>::crbegin() const noexcept {
	return const_reverse_iterator(cend());
}

template<size_t N>
constexpr typename cxstring<N>::reverse_iterator
cxstring<N>::rend() noexcept {
	return reverse_iterator(begin());
}

template<size_t N>
constexpr typename cxstring<N>::const_reverse_iterator
cxstring<N>::rend() const noexcept {
	return const_reverse_iterator(begin());
}

template<size_t N>
constexpr typename cxstring<N>::const_reverse_iterator
cxstring<N>::crend() const noexcept {
	return const_reverse_iterator(cbegin());
}

template<size_t N>
constexpr char& cxstring<N>::at(std::size_t index) {
	if(index >= N) throw std::out_of_range("at: cxstring index out of range");
	return m_data[index];
}

template<size_t N>
constexpr const char& cxstring<N>::at(std::size_t index) const {
	if(index >= N) throw std::out_of_range("at: cxstring index out of range");
	return m_data[index];
}

template<size_t N>
constexpr char&
cxstring<N>::operator[](std::size_t index) noexcept {
	return m_data[index];
}

template<size_t N>
constexpr const char&
cxstring<N>::operator[](std::size_t index) const noexcept {
	return m_data[index];
}

template<size_t N>
constexpr char& cxstring<N>::front() noexcept {
	return m_data[0];
}

template<size_t N>
constexpr const char& cxstring<N>::front() const noexcept {
	return m_data[0];
}

template<size_t N>
constexpr char& cxstring<N>::back() noexcept {
	return m_data[N-1];
}

template<size_t N>
constexpr const char& cxstring<N>::back() const noexcept {
	return m_data[N-1];
}

template<size_t N>
constexpr typename cxstring<N>::data_type&
cxstring<N>::data() noexcept {
	return m_data;
}

template<size_t N>
constexpr typename cxstring<N>::const_data_type&
cxstring<N>::data() const noexcept {
	return m_data;
}

template<size_t N>
constexpr const char* cxstring<N>::c_str() const noexcept {
	return data();
}

template<size_t N>
template<size_t N2>
constexpr cxstring<N>&
cxstring<N>::assign(
	const cxstring<N2>& other, std::size_t pos, std::size_t count) noexcept {
	return assign(other.data(), pos, count);
}

template<size_t N>
constexpr cxstring<N>&
cxstring<N>::assign(
	const char* other, std::size_t pos, std::size_t count) noexcept {
	for (std::size_t i = 0; other[i] != 0 && i < count && pos+i < N; ++i) {
		(*this)[pos+i] = other[i];
	}
}

template<size_t N>
constexpr cxstring<N>& cxstring<N>::assign(const cxstring& other) noexcept {
	return (*this = other);
}

template <std::size_t N>
template <std::size_t S>
constexpr cxstring<S> cxstring<N>::substr(std::size_t start) const {
	static_assert(S <= N,
		"cxstring::substr: substring is too long");
	
	if(start >= N) throw std::out_of_range(
		"cxstring::substr: substring start is out of range");
	if(N - start < S) throw std::out_of_range(
		"cxstring::substr: substring end is out of range");
	
	auto result = cxstring<S>::blank();
	for (std::size_t i = 0; i < S; ++i) {
		result[i] = (*this)[start+i];
	}
	return result;
}

template<size_t N>
constexpr cxstring<N>& cxstring<N>::operator=(const cxstring& other) {
	return (*this = other.data());
}

template<size_t N>
constexpr cxstring<N>& cxstring<N>::operator=(const_data_type& lit) {
	for (std::size_t i = 0; i < N; ++i) {
		(*this)[i] = lit[i];
	}
	return *this;
}

template<size_t N>
constexpr bool cxstring<N>::empty() const noexcept {
	return N == 0;
}

template<size_t N>
constexpr std::size_t cxstring<N>::size() const noexcept {
	return N;
}

template<size_t N>
constexpr std::size_t cxstring<N>::max_size() const noexcept {
	return N;
}

template<size_t N>
constexpr void cxstring<N>::fill(char value) noexcept {
	for (auto& elem : (*this)) {
		elem = value;
	}
}

template<size_t N>
constexpr void cxstring<N>::clear() noexcept {
	fill('\0');
}

template<size_t N>
constexpr void cxstring<N>::swap(cxstring& other) noexcept {
	using std::swap;
	
	for (std::size_t i = 0; i < N; ++i) {
		swap((*this)[i], other[i]);
	}
}

template<size_t N>
template<size_t N2>
constexpr std::size_t
cxstring<N>::find(const cxstring <N2>& key, std::size_t pos) const noexcept {
	return find(key.data(), pos);
}

template<size_t N>
template<size_t N2_PLUS_1>
constexpr std::size_t
cxstring<N>::find(const char (&lit)[N2_PLUS_1], std::size_t pos) const noexcept {
	constexpr std::size_t N2 = N2_PLUS_1 - 1;
	if constexpr(N2 > N) return npos;
	
	return find(static_cast<const char*>(lit), pos, N2);
}

template<size_t N>
constexpr std::size_t
cxstring<N>::find(const char* str, std::size_t pos) const noexcept {
	pos = find(str[0], pos);
	
	while (pos != npos) {
		bool matches = true;
		for (std::size_t i = 0; str[i] != 0 && pos+i < N; ++i) {
			if (str[i] != (*this)[pos+i]) {
				matches = false;
				break;
			}
		}
		
		if (matches) return pos;
		pos = find(str[0], pos+1);
	}
	
	return pos;
}

template<size_t N>
constexpr std::size_t
cxstring<N>::find(
	const char* str, std::size_t pos, std::size_t count) const noexcept {
	if(count > N) return npos;
	pos = find(str[0], pos);
	
	while (pos <= N - count) {
		bool matches = true;
		for (std::size_t i = 0; i < count; ++i) {
			if (str[i] != (*this)[pos+i]) {
				matches = false;
				break;
			}
		}
		
		if (matches) return pos;
		pos = find(str[0], pos+1);
	}
	
	return npos;
}

template<size_t N>
constexpr std::size_t
cxstring<N>::find(char ch, std::size_t pos) const noexcept {
	for (std::size_t i = pos; i < N; ++i) {
		if ((*this)[i] == ch) return i;
	}
	return npos;
}

template<size_t N>
template<size_t N2>
constexpr std::size_t
cxstring<N>::rfind(const cxstring <N2>& key, std::size_t pos) const noexcept {
	return rfind(key.data(), pos);
}

template<size_t N>
template<size_t N2_PLUS_1>
constexpr std::size_t
cxstring<N>::rfind(const char (&lit)[N2_PLUS_1], std::size_t pos) const noexcept {
	constexpr std::size_t N2 = N2_PLUS_1 - 1;
	if constexpr (N2 > N) return npos;
	
	return rfind(static_cast<const char*>(lit), pos, N2);
}

template<size_t N>
constexpr std::size_t
cxstring<N>::rfind(const char* str, std::size_t pos) const noexcept {
	return rfind(str, pos, detail::strlen(str));
}

template<size_t N>
constexpr std::size_t
cxstring<N>::rfind(
	const char* str, std::size_t pos, std::size_t count) const noexcept {
	if(count > N) return npos;
	
	pos = rfind(str[0], pos);
	
	while (pos <= N - count) {
		bool matches = true;
		for (std::size_t i = 0; i < count; ++i) {
			if (str[i] != (*this)[pos+i]) {
				matches = false;
				break;
			}
		}
		
		if (matches) return pos;
		pos = rfind(str[0], pos-1);
	}
	
	return npos;
}

template<size_t N>
constexpr std::size_t
cxstring<N>::rfind(char ch, std::size_t pos) const noexcept {
	// Employ well-defined uint underflow
	for (std::size_t i = (pos == npos ? N-1 : pos-1); i != npos; --i) {
		if ((*this)[i] == ch) return i;
	}
	return npos;
}

template<size_t N>
template<size_t N2>
constexpr cxstring<N>::cxstring(
	const cxstring<N2>& first,
	const cxstring<N - N2>& second) :
	m_data{} {
	std::size_t i = 0;
	
	for (auto elem : first)  (*this)[i++] = elem;
	for (auto elem : second) (*this)[i++] = elem;
}

template<size_t N>
constexpr cxstring<N>::cxstring(typename cxstring<N>::const_data_type& lit) :
	m_data{} {
	for (std::size_t i = 0; i < N; ++i) {
		m_data[i] = lit[i];
	}
}

// Non-member functions ========================================================

template <std::size_t N1, std::size_t N2>
constexpr cxstring<N1 + N2> operator+(
	const cxstring<N1>& lhs, const cxstring<N2>& rhs) {
	return cxstring<N1 + N2>(lhs, rhs);
}

template<size_t N>
template<size_t N2>
constexpr bool
cxstring<N>::starts_with(const cxstring<N2>& prefix) const noexcept {
	static_assert(N <= N2, "cxstring::starts_with: prefix too long");
	
	for (std::size_t i = 0; i < N2; ++i) {
		if (prefix[i] != (*this)[i]) return false;
	}
	return true;
}

template<size_t N>
constexpr bool
cxstring<N>::starts_with(const char* prefix) const {
	std::size_t i = 0;
	for (; i < N && prefix[i] != 0; ++i) {
		if (prefix[i] != (*this)[i]) return false;
	}
	
	if (i == N)
		throw std::out_of_range("cxstring::starts_with: prefix too long");
	return true;
}

template<size_t N>
constexpr bool
cxstring<N>::starts_with(char ch) const noexcept {
	return front() == ch;
}

template<size_t N>
template<size_t N2>
constexpr bool
cxstring<N>::ends_with(const cxstring <N2>& prefix) const noexcept {
	return ends_with(prefix.data());
}

template<size_t N>
template<size_t N2_PLUS_1>
constexpr bool
cxstring<N>::ends_with(const char (&prefix)[N2_PLUS_1]) const noexcept {
	constexpr std::size_t N2 = N2_PLUS_1 - 1;
	static_assert(N <= N2, "cxstring::ends_with: prefix too long");
	
	for (std::size_t i = 0; i < N2; ++i) {
		if (prefix[i] != (*this)[N - N2 + i]) return false;
	}
	return true;
}

template<size_t N>
constexpr bool cxstring<N>::ends_with(const char* prefix) const {
	std::size_t len = detail::strlen(prefix);
	if (len >= N)
		throw std::out_of_range("cxstring::ends_with: prefix too long");
	
	for (std::size_t i = 0; i < len; ++i) {
		if (prefix[i] != (*this)[N - len + i]) return false;
	}
	return true;
}

template<size_t N>
constexpr bool cxstring<N>::ends_with(char ch) const noexcept {
	return back() == ch;
}

template <std::size_t N>
inline std::ostream& operator<<(std::ostream& os, const cxstring<N>& obj) {
	return (os << obj.data());
}

} // namespace zh