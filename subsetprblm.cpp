
#include "stdafx.h"
#include "subsetprblm.h"
#include <iostream>
#include<vector>
subset::subset(): n(0), arr(nullptr)
{}

subset::subset(int nn, int* a): n(nn), arr(a)
{}

void subset::solveSubset()
{
	std::vector<int> subset;
	std::vector<std::vector<int>>res;
	solveSubsetUtil(0, subset, res);
	for (auto i = 0; i < res.size(); i++)
	{
		for (auto j = 0; j < res[i].size(); j++)
		{
			std::cout << res[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return;
}
void subset::solveSubsetUtil(int i, std::vector<int>& subset, std::vector<std::vector<int>>& res)
{
	for (int k = i; k < n; k++)
	{
		subset.push_back(arr[k]);
		res.push_back(subset);
		solveSubsetUtil(k + 1, subset, res);
		subset.pop_back();
	}
	return;
}