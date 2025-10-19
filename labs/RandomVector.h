#pragma once

#include <random>
#include <vector>

class Randomizer
{
	std::random_device dev;
	std::mt19937 gen;

	std::uniform_int_distribution<> dst;
	bool dstFlag = false;

public:
	Randomizer()
	{
		gen = std::mt19937(dev());
	}

	void set_dst(int l, int r)
	{
		dst = std::uniform_int_distribution<>(l, r);
	}

	std::vector<int> get_dst_vector(unsigned size)
	{
		std::vector<int> vec;
		vec.reserve(size);

		for (int i = 0; i < size; i++)
		{
			vec.push_back(dst(gen));
		}

		return vec;
	}

	std::vector<int> get_generic_vector(unsigned size)
	{
		std::vector<int> vec;
		vec.reserve(size);

		for (int i = 0; i < size; i++)
		{
			vec.push_back(gen());
		}

		return vec;
	}


};