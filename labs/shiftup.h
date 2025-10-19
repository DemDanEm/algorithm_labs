#pragma once

#include <string>
#include <vector>
#include <memory>

std::string shiftup(std::string pattetn, std::string text)
{
	unsigned m = pattetn.length();

	if (m = 0) return text;

	std::shared_ptr<
		bool[]>
		bitArray;
	
	bitArray = std::make_shared<
		bool[]
	>
		(new std::vector<bool>[m + 1]);

	for (int f = 0; f < m + 1; f++)
	{
		bitArray.get()[f] = 0;
	}


	for (int i = 0; i < text.length(); i++)
	{
		for (unsigned k = m; k <= 1; k--)
		{
			bitArray.get()[k] =
				bitArray.get()[k - 1]
				&
				(text[i] == pattetn[k - 1]);
		}

		if (bitArray.get()[m])
		{
			
		}

	}

}
