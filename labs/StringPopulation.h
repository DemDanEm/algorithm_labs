#pragma once

#include <vector>
#include <string>

#include "Randomizer.h"
#include "StringConsts.h"
#include "StringCompare.h"

class StringPopulation
{
	std::vector<std::string>ppl;
	std::string goal;

	Randomizer* rnd = nullptr;
	unsigned genCount = 0;

public:

	double get_highest_equality(std::vector<std::string> vec)
	{
		double highest = 0;

		for (int i = 0; i < vec.size(); i++)
		{
			double curEquality = compare_equal_length_string(vec[i], goal);

			if (curEquality > highest)
			{
				highest = curEquality;
			}
		}

		return highest;
	}




	StringPopulation(Randomizer* ran, std::vector<std::string> gen1, std::string goal)
	{
		rnd = ran;

		this->goal = goal;

		unsigned highestIdx = 0;
		double highestEquality = 0;

		for (int i = 0; i < gen1.size();i++)
		{
			double curEquality = compare_equal_length_string(gen1[i], goal);
			if (curEquality > highestEquality)
			{
				highestIdx = i;
				highestEquality = curEquality;
			}
		}

		for (int i = 0; i < GEN_SIZE; i++)
		{
			ppl.push_back(gen1[highestIdx]);
		}
	}

	void mutate()
	{
		for (int i = 0; i < ppl.size();i++)
		{
			rnd->set_dst(0, ppl[i].size());

			unsigned idx = rnd->get_dst();

			rnd->set_dst(ASKII_LOWEST, ASKII_HIGHEST);

			ppl[i][idx] = rnd->get_dst();
		}
	}

	void next_gen()
	{
		double highestEquality = get_highest_equality(ppl);
		std::vector<std::string> midGen;
		std::vector<std::string> nextGen;

		// Fill Mid Gen with highest equality specimen
		for (int i = 0; i < ppl.size(); i++)
		{
			if (compare_equal_length_string(ppl[i], goal) == highestEquality)
			{
				midGen.push_back(ppl[i]);
			}
		}

		if (midGen.size() - 1 > 0)
		{
			rnd->set_dst(0, midGen.size() - 1);

			for (int i = 0; i < ppl.size() ;i++)
			{
				nextGen.push_back(midGen[rnd->get_dst()]);
			}
		}
		else {
			for (int i = 0; i < ppl.size(); i++)
			{
				nextGen.push_back(ppl[i]);
			}
		}
		genCount++;
		ppl = nextGen;

	}
	
	std::vector<std::string>* confirm_end()
	{
		if (get_highest_equality(ppl) == 1)
		{
			return &ppl;
		}
		return nullptr;
	}

	std::vector<std::string> get_ppl()
	{
		return ppl;
	}


	unsigned get_gen_count()
	{
		return genCount;
	}

};