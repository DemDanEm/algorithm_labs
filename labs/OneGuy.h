#pragma once

#include <vector>

struct OneGuy
{
	std::vector<int> genes;

	OneGuy(std::vector<int> gen)
	{
		genes = gen;
	}

	OneGuy combine(OneGuy& mate, unsigned cutoff)
	{

		std::vector<int> cutRight;
		std::vector<int> cutLeft;

		// Save first genome cut
		for (int i = cutoff; i < genes.size()-1;i++)
		{
			cutRight.push_back(mate.genes[i]);
		}

		for (int i = 0; i <= cutoff ;i++)
		{
			cutLeft.push_back(genes[i]);
		}
	

		std::vector<int> out;
		
		
		for (int i = 0; i < cutLeft.size(); i++)
		{
			out.push_back(cutLeft[i]);
		}

		for (int i = 0; i < cutRight.size(); i++)
		{
			out.push_back(cutRight[i]);
		}

		

		return OneGuy(out);
	}

};