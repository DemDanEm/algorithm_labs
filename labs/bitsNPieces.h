#pragma once

#include <vector>
#include <bitset>

int right_rotate32(int n, int d)
{
	return (n >> d) | (n << (32 - d));
}

uint32_t C0(uint32_t word)
{
	return right_rotate32(word, 7) ^ right_rotate32(word, 18) ^ (word >> 3);
}

uint32_t C1(uint32_t word)
{
	return right_rotate32(word, 17) ^ right_rotate32(word, 19) ^ (word >> 10);
}

void expension_bloke(std::vector<std::bitset<32>>& bloke)
{
	for (int i = 0; i < 64; i++)
	{
		bloke[i] = std::bitset<32>(bloke[i - 16].to_ulong() +
			C0(bloke[i - 15].to_ulong()) +
			bloke[i - 7].to_ulong() +
			C1(bloke[i - 2].to_ulong()));
	}
}
