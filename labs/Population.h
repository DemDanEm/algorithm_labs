#pragma once

#include "OneGuy.h"
#include "Randomizer.h"

#include "VectorSum.h"

struct Population 
{
	std::vector<OneGuy> ppl;
	Randomizer* ran = nullptr;


	Population(Randomizer* rnd)
	{
		ran = rnd;
		ran->reset_dst();
		for (int i = 0; i < POPULATION_SIZE; i++)
		{
			
			std::vector<int> genome;

			for (int j = 0; j < GENOME_SIZE; j++)
			{
				genome.push_back(ran->get_dst());
			}
			ppl.push_back(OneGuy(genome));

			genome.clear();

		}
	}

	Population(std::vector<OneGuy> pop)
	{
		ppl = pop;
	}

	void mutate()
	{
		ran->set_dst(0, MUTATION_POOL);
		for (int i = 0; i < ppl.size(); i++)
		{
			for (int j = 0; j < GENOME_SIZE;j++)
			{
				if (ran->get_dst() < MUTATION_CHANCE)
				{
					ran->reset_dst();
					ppl[i].genes[j] = ran->get_dst();
					ran->set_dst(0, MUTATION_POOL);
				}
				
			}
		}

		

	}
	int size()
	{
		return ppl.size();
	}

	// TO DO: Could be repeating
	OneGuy get_child()
	{
		ran->set_dst(0, GENOME_SIZE - 1);
		int cutoff = ran->get_dst();

		ran->set_dst(0, size() - 1);

		OneGuy Dad = ppl[ran->get_dst()];
		OneGuy Mom = ppl[ran->get_dst()];


		return Dad.combine(Mom, cutoff);
	}


	Population tournament()
	{
		std::vector<OneGuy> newPop;

		ran->set_dst(0, size() - 1);

		std::vector<OneGuy> tournamentRound;

		for (int i = 0; i < TOURNAMENT_REPEATS; i++)
		{

			for (int j = 0; j < TOURNAMENT_SIZE; j++)
			{
				unsigned conId = ran->get_dst();

				tournamentRound.push_back(ppl[conId]);
			}

			int minId = 0;
			int minSum = RANGE_RIGHT;
			for (int r = 0; r < tournamentRound.size() - 1; r++)
			{
				int summ = sum_vector(tournamentRound[i].genes);
				if (summ <= minSum)
				{
					minSum = summ;
					minId = r;
				}
			}

			newPop.push_back(tournamentRound[minId]);
			tournamentRound.clear();
		}

		return Population(newPop);
	}

};