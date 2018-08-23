#pragma once

class nqueen
{
private:
	int N;
public:
	nqueen();
	nqueen(int);
	void solvenq();
	bool isSafe(int**, int, int);
	bool inlimit(int, int);
	bool solvenqUtil(int**, int, int, int);
};
