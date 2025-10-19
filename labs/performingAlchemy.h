#pragma once

#include <vector>
#include <string>


#include "ToBinary.h"
#include "bitsNPieces.h"
#include "cStrSize.h"

#define str "hello world"



std::vector<std::bitset<32>> get_w(const char* c)
{
	std::string bitStr;
	int cSize = get_c_str_size(c);

	for (int i = 0; i < cSize;i++)
	{
		bitStr.append(std::bitset<8>(c[i]).to_string());
	}
	bitStr.append("1");
	while (bitStr.length() != 448)
	{
		bitStr.append("0");
	}
	// Got to 448, now adding end

	std::string end;
	while (end.length() != 64 - 8) //PROBLEMATIC
 	{
		end.append(std::string("0"));
	}
	end.append(
		to_8_binary(cSize).to_string()
	);

	bitStr.append(end);

	std::vector<std::bitset<32>> W;

	for (int i = 0; i < (512 / 32); i++)
	{
		W.push_back(
			std::bitset<32>
			(
				bitStr.substr(i * 32, (i + 1) * 32)
			)
		);
	}

	while (W.size() != 64)
	{
		W.push_back(
			std::bitset<32>()
		);
	}


	return W;


	//for (int h = 0; h < W.size(); h++)
	//{
	//	std::cout << W[h].to_string() << std::endl;
	//}
	//std::cout<< W.size()<< std::endl;

	//std::cout << bitStr << "\n" << bitStr.length();
}


std::vector<std::bitset<32>> alchemy(std::vector<std::bitset<32>> w)
{
	std::vector<std::pair<int, int>> Ss;

	for (int i = 16; i < w.size(); i++)
	{
		Ss[i].first = (right_rotate32(w[i-15].to_ulong(), 7))^
			(right_rotate32(w[i - 15].to_ulong(), 18)^ 
				(right_rotate32(w[i - 15].to_ulong(), 3)));
		Ss[i].second = (right_rotate32(w[i - 2].to_ulong(), 7)) ^
			(right_rotate32(w[i - 2].to_ulong(), 18) ^
				(right_rotate32(w[i - 2].to_ulong(), 3)));
		w[i] = std::bitset<32>(
			w[i - 16].to_ullong() + Ss[i].first +
			w[i - 7].to_ullong() + Ss[i].second);
	}

	return w;
}


void fairy(std::vector<std::bitset<32>> w)
{
	uint32_t h0 = 0x6a09e667;
	uint32_t h1 = 0xbb67ae85;
	uint32_t h2 = 0x3c5ef372;
	uint32_t h3 = 0xa54ff53a;
	uint32_t h4 = 0x510e527f;
	uint32_t h5 = 0x9b05588c;
	uint32_t h6 = 0x1f83d9ab;
	uint32_t h7 = 0x5be0cd19;
	uint32_t s1 = (right_rotate32(h4, 6) xor right_rotate32(h4, 11) xor right_rotate32(h4, 25));

	uint32_t ch = (h4 & h7) xor ((~h4) & h5);


	uint32_t temp1 = h6 + s1 + ch +k[i]
}