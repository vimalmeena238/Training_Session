#include "stdafx.h"
#include "nqueen.h"

#include <iostream>

nqueen::nqueen(): N(4)
{}
nqueen::nqueen(int n): N(n)
{}
bool nqueen::inlimit(int i, int j)
{
	if ((i >= 0 && i < N) && (j >= 0 && j < N)) return true;
	return false;
}
bool nqueen::isSafe(int** M, int p, int q)
{
	if (M[p][q] == 1) return false;
	for (int i = 0; i < N; i++)
		if (M[i][q] == 1) return false;
	for (int j = 0; j < N; j++)
		if (M[p][j] == 1) return false;
	for (int i = 1-N; i < N; i++)
	{
		if (inlimit(p + i, q + i))
		{
			if (M[p+i][q+i] == 1) return false;
		}
		if (inlimit(p + i, q - i))
		{
			if (M[p + i][q - i] == 1) return false;
		}
	}
	return true;

}
bool nqueen::solvenqUtil(int** M, int p, int q, int count)
{
	if (count >= N) return true;
	for (int i = 0; i < N; i++)
	{
		if (isSafe(M, p,i))
		{
			M[p][i] = 1;
			if (solvenqUtil(M, p + 1, i,count+1))
				return true;
			M[p][i] = 0;
		}
	}
	return false;
}
void nqueen::solvenq()
{
	int** M = new int*[N];
	for (int i = 0; i < N; i++)
		M[i] = new int[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			M[i][j] = 0;
	solvenqUtil(M, 0, 0, 0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout << M[i][j];
		}
		std::cout << std::endl;
	}
	return;
}