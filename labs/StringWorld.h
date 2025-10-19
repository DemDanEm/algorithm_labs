#pragma once

#include <memory>
#include <iostream>

#include "StringPopulation.h"
#include "VectorPrint.h"

class StringWorld
{
	std::shared_ptr<Randomizer> rnd;
	std::shared_ptr < StringPopulation> pop;

public:

	StringWorld(std::string goal, std::vector<std::string> gen1)
	{
		rnd = std::make_shared<Randomizer>();
		pop = std::make_shared<StringPopulation>(rnd.get(), gen1, goal);
	}

	void loop()
	{
		while (true)
		{
			std::cout << pop->get_gen_count() << std::endl;
			std::cout << pop->get_highest_equality(pop->get_ppl()) << std::endl;
			print_vector(pop->get_ppl());

			if (pop->get_highest_equality(pop->get_ppl()) == double(1))
			{
				break;
			}

			pop->next_gen();
			pop->mutate();
		}

		print_vector(*(pop->confirm_end()));
		std::cout << pop->get_gen_count() << std::endl;
	}

};