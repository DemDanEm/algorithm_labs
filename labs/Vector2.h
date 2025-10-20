#pragma once

#include <math.h>

struct Vector2
{
	int x;
	int y;
	Vector2() {}
	Vector2(int a, int b) 
	{
		x = a;
		y = b;
	}

	double to(Vector2 dst)
	{
		return sqrt(
			pow(
				this->x - dst.x
				, 2
			) +
			pow(
				this->y - dst.y
				, 2
			)
		);
	}



};