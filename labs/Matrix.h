#pragma once

#include <memory>

struct Matrix
{

	std::shared_ptr<std::shared_ptr<unsigned[]>[]> grid;
	unsigned w;
	unsigned h;


//Bad idea, but i have no better solution, be very careful when using
	Matrix() {}

// By default Matrix is filled with 0
	Matrix(unsigned size)
	{
		grid = std::shared_ptr<std::shared_ptr<unsigned[]>[]>(new std::shared_ptr<unsigned[]>[size]);
		for (int i = 0; i < size; i++) {
			grid[i] = std::shared_ptr<unsigned[]>(new unsigned[size]);
			for (int j = 0; j < size; j++)
			{
				grid[i][j] = 0;
			}
		}
		h = size;
		w = size;
	}

	Matrix(unsigned h, unsigned w)
	{
		grid = std::shared_ptr<std::shared_ptr<unsigned[]>[]>(new std::shared_ptr<unsigned[]>[w]);
		for (int i = 0; i < w; i++) {
			grid[i] = std::shared_ptr<unsigned[]>(new unsigned[h]);
			for (int j = 0; j < h; j++)
			{
				grid[i][j] = 0;
			}
		}
		this->h = h;
		this->w = w;
	}

	std::shared_ptr<unsigned[]> operator[] (unsigned row)
	{
		return grid[row];
	}
};