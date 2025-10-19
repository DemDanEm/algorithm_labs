#pragma once


#include "Matrix.h"
#include "Matrix_print.h"

void ryme(std::string astr, std::string bstr)
{
	//Size of each side
	unsigned h = astr.length()+1;
	unsigned w = bstr.length()+1;


	// createing matrix
	Matrix mtrx(h, w);

	// Set default parts of matrix
	for (int i = 1; i < h;i++)
	{
		mtrx[0][i] = i;
	}

	for (int j = 1; j < w;j++)
	{
		mtrx[j][0] = j;
	}


	//Fill up matrix
	for (int ch = 1; ch < h; ch++)
	{
		for (int cw = 1; cw < w; cw++)
		{
			unsigned form1 = mtrx[cw][ch - 1] + 1;
			unsigned form2 = mtrx[cw-1][ch] + 1;
			unsigned form3 = mtrx[cw-1][ch-1] + !(astr[ch-1]==bstr[cw-1]);

			unsigned out = form1;
			if (form2 < out) out = form2;
			if (form3 < out) out = form3;

			mtrx[cw][ch] = out;
		}
	}


	matrix_out(mtrx);
}