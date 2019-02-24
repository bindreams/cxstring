#pragma once
#include <cstdint>
#include <iterator>
#include <type_traits>
#include <iostream>

namespace zh {

template<std::size_t N>
class cxstring {
	char m_data[N+1];
	
public:
	// Static variables ========================================================
	constexpr static std::size_t npos = static_cast<std::size_t>(-1);
	
	// Public types ============================================================
	using value_type = char;
	using size_type = std::size_t;
	using difference_type = std::ptrdiff_t;
	using reference = char&;
	using const_reference = const char&;
	using pointer = char*;
	using const_pointer = const char*;
	
	using iterator = char*;
	using const_iterator = const char*;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;
	
	using data_type = char[N+1];
	using const_data_type = const char[N+1];
	
	// Public functions ========================================================
	// Constructors ------------------------------------------------------------
	
	// cxstrings are not supposed to be blank.
	// Warning: use this method only if you are going to fill it immediately.
	// Comparison operators, find functions all calculate cxstring size from the
	// template parameter, not from string contents.
	constexpr static cxstring blank();
	
	constexpr cxstring(const_data_type& lit);
	
	// Iterators ---------------------------------------------------------------
	constexpr iterator begin() noexcept;
	constexpr const_iterator begin() const noexcept;
	constexpr const_iterator cbegin() const noexcept;
	
	constexpr iterator end() noexcept;
	constexpr const_iterator end() const noexcept;
	constexpr const_iterator cend() const noexcept;
	
	constexpr reverse_iterator rbegin() noexcept;
	constexpr const_reverse_iterator rbegin() const noexcept;
	constexpr const_reverse_iterator crbegin() const noexcept;
	
	constexpr reverse_iterator rend() noexcept;
	constexpr const_reverse_iterator rend() const noexcept;
	constexpr const_reverse_iterator crend() const noexcept;
	
	// Element access ----------------------------------------------------------
	constexpr char& at(std::size_t index);
	constexpr const char& at(std::size_t index) const;
	
	constexpr char& operator[](std::size_t index) noexcept;
	constexpr const char& operator[](std::size_t index) const noexcept;
	
	constexpr char& front() noexcept;
	constexpr const char& front() const noexcept;
	
	constexpr char& back() noexcept;
	constexpr const char& back() const noexcept;
	
	constexpr data_type& data() noexcept;
	constexpr const_data_type& data() const noexcept;
	
	constexpr const char* c_str() const noexcept;
	
	// Capacity ----------------------------------------------------------------
	constexpr bool empty() const noexcept;
	constexpr size_type size() const noexcept;
	constexpr size_type max_size() const noexcept;
	
	// Operations --------------------------------------------------------------
	constexpr cxstring& operator=(const cxstring& other);
	constexpr cxstring& operator=(const_data_type& lit);
	
	template <std::size_t S>
	constexpr cxstring<S> substr(std::size_t start) const;
	
	constexpr cxstring& assign(
		const char* other,
		std::size_t pos,
		std::size_t count = npos) noexcept;
	template <std::size_t N2>
	constexpr cxstring& assign(
		const cxstring<N2>& other,
		std::size_t pos,
		std::size_t count = npos) noexcept;
	constexpr cxstring& assign(const cxstring& other) noexcept;
	
	constexpr void fill(char value) noexcept;
	constexpr void clear() noexcept;
	
	constexpr void swap(cxstring& other) noexcept;
	
	template <std::size_t N2>
	constexpr bool starts_with(const cxstring<N2>& prefix) const noexcept;
	constexpr bool starts_with(const char* prefix) const;
	constexpr bool starts_with(char ch) const noexcept;
	
	template <std::size_t N2>
	constexpr bool ends_with(const cxstring<N2>& prefix) const noexcept;
	template <std::size_t N2_PLUS_1>
	constexpr bool ends_with(const char (&prefix)[N2_PLUS_1]) const noexcept;
	constexpr bool ends_with(const char* prefix) const;
	constexpr bool ends_with(char ch) const noexcept;
	
	// Search ------------------------------------------------------------------
	template <std::size_t N2>
	constexpr std::size_t
	find(const cxstring<N2>& key, std::size_t pos = 0) const noexcept;
	
	template <std::size_t N2_PLUS_1>
	constexpr std::size_t
	find(const char (&lit)[N2_PLUS_1], std::size_t pos = 0) const noexcept;
	
	constexpr std::size_t
	find(const char* str, std::size_t pos = 0) const noexcept;
	
	constexpr std::size_t
	find(const char* str, std::size_t pos, std::size_t count) const noexcept;
	
	constexpr std::size_t
	find(char ch, std::size_t pos = 0) const noexcept;
	
	template <std::size_t N2>
	constexpr std::size_t
	rfind(const cxstring<N2>& key, std::size_t pos = npos) const noexcept;
	
	template<size_t N2_PLUS_1>
	constexpr std::size_t
	rfind(const char (&lit)[N2_PLUS_1], std::size_t pos) const noexcept;
	
	constexpr std::size_t
	rfind(const char* str, std::size_t pos = npos) const noexcept;
	
	constexpr std::size_t
	rfind(const char* str, std::size_t pos, std::size_t count) const noexcept;
	
	constexpr std::size_t
	rfind(char ch, std::size_t pos = npos) const noexcept;
	
	// Friends -----------------------------------------------------------------
	template <std::size_t N1, std::size_t N2>
	friend constexpr cxstring<N1 + N2> operator+(
		const cxstring<N1>& lhs, const cxstring<N2>& rhs);
	
private:
	template <std::size_t N2>
	constexpr cxstring(
		const cxstring<N2>& first,
		const cxstring<N-N2>& second);
};

template <std::size_t N_PLUS_1>
cxstring(const char (&lit)[N_PLUS_1]) -> cxstring<N_PLUS_1 - 1>;

template <std::size_t N>
inline std::ostream& operator<<(std::ostream& os, const cxstring<N>& obj);

} // namespace zh

#include "compare_operators.hpp"

#include "cxstring.inl"