#pragma once

#include <iostream>
#include "Matrix.h"

void matrix_out(Matrix m)
{
	for (int i = 0; i < m.h; i++)
	{
		for (int j = 0; j < m.w; j++)
		{
			std::cout << m[j][i] << " ";
		}
		std::cout<<std::endl;
	}
}