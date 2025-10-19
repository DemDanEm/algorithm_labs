#pragma once

#include <memory>

#include "Randomizer.h"
#include "Population.h"

class WorldObject
{

	std::shared_ptr<Randomizer> rnd;
	std::shared_ptr<Population> pop;

	WorldObject()
	{
		rnd = std::make_shared<Randomizer>(new Randomizer());

		pop = std::make_shared<Population>(new Population(rnd.get()));

	}


	void next_gen()
	{
		Population midGen = pop.get()->tournament();

		std::vector<OneGuy> nextGenVec;

		for (int i = 0; i < POPULATION_SIZE; i++)
		{
			nextGenVec.push_back(midGen.get_child());
		}
		

		pop = std::make_shared<Population>(new Population(nextGenVec));

		pop->mutate();

	}
};