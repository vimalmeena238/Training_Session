#include "stdafx.h"
#include "Word_boggle.h"

#include<iostream>

#include<vector>
#include<string>

WB::WB(): dict(NULL), boggle(nullptr)
{}
WB::WB(std::vector<std::string> d, char** b, int r, int c): dict(d), boggle(b), b_r(r), b_c(c)
{}
bool WB::inlimit(int i, int j)
{
	return (i >= 0 && i < b_r) && (j >= 0 && j < b_c);
}
bool WB::solveWBUtil(int k, int l, int x, int y)
{
	if (l == dict[k].size()) return true;
	if (boggle[x][y] == dict[k][l])
	{
		for (int i = 0; i < 8; i++)
		{
			if (inlimit(x + cx[i], y + cy[i]))
			{
				if (solveWBUtil(k, l + 1, x + cx[i], y + cy[i]))
					return true;
			}
		}
	}
	return false;
}
void WB::solveWB()
{

	int* arr = new int[dict.size()];
	for (int i = 0; i < dict.size(); i++)
		arr[i] = 0;
	for (unsigned int k = 0; k < dict.size(); k++)
	{
		for (int i = 0; i < b_r; i++)
		{
			for (int j = 0; j < b_c; j++)
			{
				
				if (boggle[i][j] == dict[k][0])
				{
					if (solveWBUtil(k, 0, i, j))
					{
						
						arr[k] = 1;
					}

				}
			}
		}
	}
	for (unsigned int k = 0; k < dict.size(); k++)
	{
		std::cout << arr[k];
	}
}