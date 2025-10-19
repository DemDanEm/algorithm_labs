#pragma once

#include <iostream>
#include <vector>
#include <string>

void print_vector(std::vector<int> vec)
{
	for (int i = 0; i < vec.size()-1; i++)
	{
		std::cout << vec[i] << ", ";
	}
	std::cout << vec[vec.size() - 1] << std::endl;
}


void print_vector(std::vector<std::string> vec)
{
	for (int i = 0; i < vec.size() - 1; i++)
	{
		std::cout << vec[i] << ", ";
	}
	std::cout << vec[vec.size() - 1] << std::endl;
}