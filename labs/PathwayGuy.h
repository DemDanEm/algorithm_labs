#pragma once

#include <vector>


class PathwayGuy
{

	std::vector<unsigned> path;

	PathwayGuy(std::vector<unsigned> p)
	{
		path = p;
	}


public:

	PathwayGuy(unsigned pathSize)
	{
		for (unsigned i = 0; i < pathSize; i++)
		{
			path.push_back(i);
		}
	}

	std::vector<unsigned> get_path()
	{
		return path;
	}


	void mutation_swap(unsigned idxA, unsigned idxB)
	{
		if (idxA == idxB or idxA >= path.size() or idxB >= path.size())
		{
			return;
		}

		unsigned valA = path[idxA];
		unsigned valB = path[idxB];

		path[idxA] = valB;
		path[idxB] = valA;

	}
	
};