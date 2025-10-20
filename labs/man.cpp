
#include <iostream>
#include <memory>

#include "PathPopulation.h"
#include "VectorPrint.h"
#include "Vector2.h"


int main()
{
	
	std::shared_ptr<Randomizer> end = std::make_shared<Randomizer>();

	std::vector<PathPoint> points;

	points.push_back(PathPoint(Vector2(0, 0)));
	points.push_back(PathPoint(Vector2(0, 1)));
	points.push_back(PathPoint(Vector2(1, 1)));
	points.push_back(PathPoint(Vector2(1, 0)));


	PathPopulation pop(end.get(), points);

	for (int i = 0; i < 100; i++)
	{
		pop.next_gen();
	}

	for (int i = 0; i < pop.ppl.size(); i++)
	{
		for (int j = 0; j < pop.ppl[i].get_path().size(); j++)
		{
			std::cout << pop.ppl[i].get_path()[j]<< ", ";
		}
		std::cout << std::endl;
	}

	std::cout << pop.get_lowest_weight_path();

	return 0;
}