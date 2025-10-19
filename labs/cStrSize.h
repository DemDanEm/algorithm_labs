#pragma once


int get_c_str_size(const char* c)
{
	int count = 0;
	while (c[count] != *"\0")
	{
		count++;
	}
	return count;
}