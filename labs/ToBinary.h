#pragma once

#include <bitset>
#include <vector>

std::bitset<8> to_8_binary(char c)
{
	return std::bitset<8>(c);
}

std::bitset<8> to_8_binary(int c)
{
	return std::bitset<8>(c);
}

// From stackoverflow
template <size_t s1, size_t s2>
std::bitset<s1 + s2> bit_combine(const std::bitset<s1>& bit1, const std::bitset<s2>& bit2)
{
	std::string str1 = bit1.to_string();
	std::string str2 = bit2.to_string();
	return std::bitset<s1 + s2>(str1 + str2);
}
