#pragma once

#include <string>

double compare_equal_length_string(std::string stra, std::string strb)
{
	unsigned al = stra.length();
	unsigned bl = strb.length();

	if (al != bl)
	{
		return 0;
	}

	double equalityPercent = 0;
	double fragment = double(1) / double(al);

	for (int i = 0; i < al; i++)
	{
		if (stra[i] == strb[i])
		{
			equalityPercent += fragment;
		}
	}

	return equalityPercent;
}