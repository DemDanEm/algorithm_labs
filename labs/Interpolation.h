#pragma once
#include <vector>



int interpolation_search(int target, std::vector<int> ray)
{
	unsigned lf = (target - ray[0]) / (ray.back());
	unsigned pos = lf * (ray.size() - ray.back());

	return pos;
}
