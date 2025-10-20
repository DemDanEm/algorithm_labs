#pragma once


#include "Randomizer.h"

#include "PathwayGuy.h"
#include "PathwayConsts.h"
#include "PathPoint.h"

#include "VectorSum.h"
#include "Vector2.h"

struct PathPopulation
{
	std::vector<PathwayGuy> ppl;
	Randomizer* ran = nullptr;

	std::vector<PathPoint> ps;

	PathPopulation(std::vector<PathwayGuy> pop, std::vector<PathPoint> points)
	{
		ppl = pop;
		ps = points;
	}
	// !!!!!
	unsigned get_path_weight(unsigned pathIdx)
	{
		double wSum = 0;

		std::vector<unsigned> guyVec = ppl[pathIdx].get_path();
		unsigned guyVecSize = guyVec.size();

		// Костыль, но я не вижу лучшего решения
		PathPoint p0 = ps[
			guyVec[0]
		];


		for (int i = 1; i < guyVecSize; i++)
		{
			PathPoint pi = ps[
				guyVec[i]
			];

			wSum += p0.cord.to(
				pi.cord
			);

			p0 = pi;
		}


		wSum += p0.cord.to(
			ps[
				guyVec[0]
			].cord
		);

		return wSum;

	}





//public:

	// !!!!!!!!!
	unsigned get_lowest_weight()
	{
		unsigned w = get_path_weight(0);

		for (int i = 0; i < ppl.size(); i++)
		{
			unsigned cw = get_path_weight(i);
			if (cw < w)
			{
				w = cw;
			}
		}
		return w;
	}


	// !!!!
	unsigned get_lowest_weight_path()
	{
		unsigned lw = get_lowest_weight();
		for (int i = 0; i < ppl.size(); i++)
		{
			if (lw == get_path_weight(i))
			{
				return i;
			}
		}
	}

	PathPopulation(Randomizer * rnd, std::vector<PathPoint> points)
	{
		ran = rnd;
		ps = points;

		for (int i = 0; i < PATH_POPULATION_SIZE; i++)
		{
			ppl.push_back(PathwayGuy(ps.size()));
		}


	}






	void mutate()
	{
		ran->set_dst(0, ps.size() - 1);
		for (int i = 0; i < ppl.size(); i++)
		{
			ppl[i].mutation_swap(
				ran->get_dst(),
				ran->get_dst()
			);
		}
	}

	void next_gen()
	{
		std::vector<PathwayGuy> nextGen;

		unsigned lwpIDX = get_lowest_weight_path();
		for (int i = 0; i < PATH_POPULATION_SIZE; i++)
		{
			nextGen.push_back(ppl[lwpIDX]);
		}

		ppl = nextGen;
		this->mutate();
	}
};