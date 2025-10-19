#pragma once
#include <vector>
#include <map>

#include "Bubble.h"

// Check if number is in vector
bool is_in_vec(int num, std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == num)
		{
			return true;
		}
	}
	return -1;
}

// Main algorithm
std::vector<int> am_sort(std::vector<int> ray)
{
	// Sort array with bubble sort
	bubble(ray);

	// Array sort
	unsigned aSize = ray.size();

	std::map<int, int> countMap;
	std::vector<int> uniques;

	for (int i = 0; i < aSize; i++)
	{
		if (uniques.empty() or is_in_vec(ray[i], uniques))
		{
			uniques.push_back(ray[i]);
			countMap[i] = 1;
		}
		else
		{
			countMap[i] += 1;
		}
	}

	std::vector<int> output;

	bubble(uniques); // Not needed but cool for lulz

	for (int i = 0; i < uniques.size(); i++)
	{

		for (int j = 0; j < countMap[uniques[i]];j++)
		{
			output.push_back(uniques[i]);
		}

	}

	return output;
}