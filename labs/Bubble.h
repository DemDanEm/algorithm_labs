#pragma once

#include <vector>

void bubble(std::vector<int>& vc)
{
	int sz = vc.size();
	for (int i = 0; i < sz - 1;i++)
	{
		for (int j = 0; j < sz - i - 1;j++)
		{
			if (vc[j] > vc[j + 1])
			{
				std::swap(vc[j], vc[j + 1]);
			}
		}
	}
}