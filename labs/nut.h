#pragma once

#include <string>


int tri_search(std::string str, std::string substr)
{
	// String lengths, so we dont have to call length() every time
	unsigned mLen = str.length();
	unsigned sLen = substr.length();

	// main string shift 
	unsigned shift = 0;

	// Main loop: going through main string
	for (int i = 0; i < mLen; i++)
	{
		bool skipFlag = false; 

		// if current letter equals first letter of the substring
		if (str[shift] == substr[0])
		{
			//check for the substring
			for (int j = 0; j < sLen; j++)
			{
				if (str[shift + j] != substr[j])
				{
					// if not substring return to main loop
					skipFlag = true;
					break;
				}
			}
			if (skipFlag)
			{
				continue;
			}
			return shift;
		}

		shift++;
	}
	return -1;
}