#pragma once

#include <vector>

double vector_avg(std::vector<int> v)
{
	int S;
	for (int i = 0; i < v.size();i++)
	{
		S += v[i];
	}
	return S / v.size();
}