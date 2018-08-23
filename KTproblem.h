#pragma once

class KT
{
private:
	int x, y;

public:
	KT();
	KT(int, int, int);
	bool isEmpty(int, int, int**);
	bool inlimit(int, int);
	void solveKT();
	bool nextmove(int, int, int, int**,const int*,const int*);
	bool Warnsdorffnextmove();

};
