#pragma once

#include <string>

#include "Vector2.h"


struct PathPoint
{
	//unsigned pid;

	// Безполезно, но прикольно
	std::string name = "Null";

	Vector2 cord;

	PathPoint() {}
	PathPoint(Vector2 cords)
	{
		cord = cords;
	}

	PathPoint(Vector2 cords, std::string name)
	{
		cord = cords;
		this->name = name;
	}
};