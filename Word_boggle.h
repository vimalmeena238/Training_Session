#pragma once

#include<iostream>

#include<vector>
#include<string>

class WB
{
private:
	std::vector<std::string> dict;
	char** boggle;
	int b_r, b_c;
	int cx[8] = { 0,0,1,1,1,-1,-1,-1 };
	int cy[8] = { 1,-1,1,0,-1,1,0,-1 };
public:
	WB();
	WB(std::vector<std::string>, char**, int , int);
	bool inlimit(int, int);
	bool solveWBUtil(int, int, int, int);
	void solveWB();
};