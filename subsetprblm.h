#pragma once

#include<vector>
class subset
{
private:
	int n;
	int* arr;
public:
	subset();
	subset(int, int*);
	void solveSubsetUtil(int, std::vector<int>&, std::vector<std::vector<int>>&);
	void solveSubset();
};
