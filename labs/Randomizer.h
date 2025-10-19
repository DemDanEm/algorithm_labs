#pragma once
#include <random>

#include "consts.h"

class Randomizer
{
	std::random_device dev;
	std::mt19937 gen;
	std::uniform_int_distribution<> dst;
public:
	Randomizer()
	{
		gen = std::mt19937(dev());
		dst = std::uniform_int_distribution<>(RANGE_LEFT, RANGE_RIGHT);
	}


	int get_range(int l, int r)
	{
		dst = std::uniform_int_distribution<>(l, r);

		int out = dst(gen);

		dst = std::uniform_int_distribution<>(RANGE_LEFT, RANGE_RIGHT);
	}


	int get_dst()
	{
		return dst(gen);
	}

	void set_dst(int l, int r)
	{
		dst = std::uniform_int_distribution<>(l, r);
	}

	void reset_dst()
	{
		dst = std::uniform_int_distribution<>(RANGE_LEFT, RANGE_RIGHT);

	}
};
