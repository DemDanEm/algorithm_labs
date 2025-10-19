#pragma once

#include <vector>

// Output structure
struct mSumOutput
{
	int sum;
	std::vector<int> array;
};

// For getting a subvector in main algorithm
std::vector<int> subvector(unsigned l, unsigned r, std::vector<int> ray)
{
	//check for valid arguments
	if (l >= r-1)
	{
		return {};
	}

	if (r - l == ray.size())
	{
		return ray;
	}

	std::vector<int> out;

	for (int i = l; i <= r-1; i++)
	{
		out.push_back(ray[i]);
	}

	return out;
}

// For getting a sum of vectors' values
int vec_sum(std::vector<int> vec)
{
	int sum = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		sum += vec[i];
	}
	return sum;
}

// Main algorithm
mSumOutput msum_algorithm(std::vector<int> ray)
{
	unsigned subSize = 1; // Sub array size
	unsigned subShift = 1; // Step from left of the main array

	// Output structure
	mSumOutput out;

	// Get first values (first two nubers in the main array)
	out.array = std::vector<int>{ ray[0], ray[1] };
	out.sum = ray[0] + ray[1];

	// Going through the entire main array until we have tried each combination
	while (subSize != ray.size())
	{
		// check if we have tried all arrays of the given size
		if (subShift + subSize >= ray.size())
		{
			// Increase array size and reset shift if so
			subSize++;
			subShift = 0;
		}

		// Geting curent subvector and sum of its' values
		std::vector<int> subVec = subvector(subShift, subShift + subSize, ray);
		int vsum = vec_sum(subVec);

		// Check if current subvector is "bigger"
		if (vsum > out.sum)
		{
			// If so replace the output value 
			out.array = subVec;
			out.sum = vsum;

		}
		
		// Shift up and go next
		subShift++;
	}

	return out;
}
