// Algo1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KTproblem.h"
#include "nqueen.h"
#include "subsetprblm.h"
#include "Word_boggle.h"
#include <iostream>
#include <limits>
#include <list>
#include <deque>

int minimumnumberofcoins(int*, int, int);
int mncoinsdp(int*, int, int);
void insertion_sort(int*, int);
int binary_search(int*, int, int, int);

int main()
{
	//int p = 3499,ncoins;
	//std::cin >> ncoins;
	//int* coins = new int[ncoins];
	//for (int i = 0; i < ncoins; i++)
	//	std::cin >> coins[i];
	//std::cout << mncoinsdp(coins, p, ncoins);
	//insertion_sort(coins, ncoins);
	//int key = 12;
	//std::cout <<  binary_search(coins, 0, ncoins - 1, key);

	//Knight TOur Problem
	//int x(0), y(0), z(1);
	//while (x != -1)
	//{
	//	std::cin >> x >> y >> z;
	//	KT K1(x,y,z);
	//
	//}
	// Subset problem
	//int n, *nn;
	//std::cin >> n;
	//nn = new int[n];
	//for (int i = 0; i < n; i++)
	//{
	//	std::cin >> nn[i];
	//}
	//subset a(n, nn);
	//a.solveSubset();
	nqueen q(4);
	q.solvenq();
	std::vector<std::string> dict;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;
		dict.push_back(str);
	}
	std::cout << std::endl << "Enter size of boggle (r,c)" << std::endl;
	int r, c;
	std::cin >> r >> c;
	char** bg = new char*[r];
	for (int i = 0; i < r; i++)
	{
		bg[i] = new char[c];
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			std::cin >> bg[i][j];
		}
	}
	WB W(dict, bg,r,c);
	W.solveWB();

	std::cout << "done!";
    return 0;
}

int minimumnumberofcoins(int* coins, int p, int ncoins)
{
	if (p == 0) return 0;
	int res = INT_MAX;
	for (int i = 0 ; i < ncoins; i++)
	{
		if (coins[i] <= p)
		{
			int sub_res = minimumnumberofcoins(coins, p - coins[i], ncoins);
			if (sub_res != INT_MAX && sub_res+1 < res)
				res = sub_res+1;
		}
	}
	return res;
}

int mncoinsdp(int* coins, int p, int ncoins)
{
	int* Vres = new int[p+1];
	Vres[0] = 0;
	for (int i = 1; i < p+1; i++)
		Vres[i] = INT_MAX;
	for (int i = 1; i < p+1; i++)
	{
		for (int j = 0; j < ncoins; j++)
		{
			if (coins[j] <= i)
			{
				int sub_res = Vres[i - coins[j]];
				if (sub_res != INT_MAX && sub_res + 1 < Vres[i])
				{
					Vres[i] = sub_res+1;
				}
			}
		}
	}
	return Vres[p];
}

void insertion_sort(int* arr, int size)
{
	int j(0), key(0);
	for (int i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	return;
}

int binary_search(int* arr, int l, int r, int key)
{
	if (l>r) return -1;
	int mid = (l + r) / 2;
	if (arr[mid] == key) return mid;
	if (key > arr[mid])
	{
		return binary_search(arr, mid, r, key);
	}
	else
	{
		return binary_search(arr, l, mid, key);
	}
}


