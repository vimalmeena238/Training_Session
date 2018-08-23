#include "stdafx.h"
#include "KTproblem.h"
#include<iostream>

KT::KT(): x(0), y(0)
{
	//solveKT();
	bool xz = Warnsdorffnextmove();
}
KT::KT(int i, int j, int z): x(i), y(j)
{
	//solveKT();
	if (z == 1)
	{
		Warnsdorffnextmove();
	}
	else solveKT();
}
bool KT::isEmpty(int p, int q, int** arr)
{
	if(inlimit(p,q))
		if (arr[p][q] == -1) return true;
	return false;
}
bool KT::inlimit(int i, int j)
{
	if ((i >= 0 && i < 8) && (j >= 0 && j < 8))
		return true;
	return false;
}
bool KT::nextmove(int x, int y, int  count, int** ans,const int* cx, const int* cy)
{
	if (count == 64 && inlimit(x, y)) return true;
	for (int i = 0; i < 8; i++)
	{
		if (isEmpty(x + cx[i], y + cy[i], ans))
		{
			ans[x + cx[i]][y + cy[i]] = count+1;
			if (nextmove(x + cx[i], y + cy[i], count + 1, ans, cx, cy) == true)
				return true;
		}
	}
	ans[x][y] = -1;
	return false;
}

bool KT::Warnsdorffnextmove()
{
	int** soln = new int*[8];
	for (int i = 0; i < 8; i++)
	{
		soln[i] = new int[8];
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			soln[i][j] = -1;
		}

	}
	int cx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int cy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int curr_x(this->x), curr_y(this->y);
	soln[x][y] = 0;
	int mindof_ind(-1);
	for (int k = 1; k < 64; k++)
	{
		mindof_ind = -1;
		if (inlimit(curr_x, curr_y)==true)
		{
			int mindof(8), ct(0),start,i;
			start = 0;
			i = 0;
			start = rand() % 8;
			for (int nn = 0; nn < 8; nn++)
			{

				i = (start + nn) % 8;
				if (isEmpty(curr_x + cx[i], curr_y + cy[i], soln)==true)
				{
					for (int j = 0; j < 8; j++)
					{
						if (isEmpty(curr_x + cx[i] + cx[j], curr_y + cy[i] + cy[j], soln))
							ct++;
					}
					if (ct <= mindof)
					{
						mindof = ct;
						mindof_ind = i;
					}
					ct = 0;
				}
			}
			
			if (mindof_ind == -1) return false;
			
			curr_x = curr_x + cx[mindof_ind];
			curr_y = curr_y + cy[mindof_ind];
			soln[curr_x][curr_y] = k;

		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << soln[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return true;

}
void KT::solveKT()
{
	int** soln = new int*[8];
	for (int i = 0; i < 8; i++)
	{
		soln[i] = new int[8];
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			soln[i][j] = -1;
		}

	}
	int cx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int cy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	int count = 1;
	soln[this->x][this->y] = count;
	bool z = nextmove(this->x, this->y, count, soln, cx, cy);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << soln[i][j] << " ";
		}
		std::cout << std::endl;
	}


}