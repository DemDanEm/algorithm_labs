#pragma once

#include <vector>

template <typename T>
T sum_vector (std::vector<T> v)
{
	T S;
	for (T i = 0; i < v.size();i++)
	{
		S += v[i];
	}
	return S;

}
