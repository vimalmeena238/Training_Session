#include "stdafx.h"

#include <iostream>
#include <vector>

// Convert this program to C++
// change to C++ io
// change to one line comments
// change defines of constants to const
// change array to vector<>
// inline any short function

const int N = 40;

inline void sum(int*p, std::vector<int> & d)
{
	*p = 0;
	for (int i = 0; i < N; ++i)
		*p = *p + d[i];
}

int main()
{
	int accum = 0;
	std::vector<int> data;
	for (int i = 0; i < N; ++i)
		data.push_back(i);

	sum(&accum, data);
	std::cout << "Sum is :" << accum << std::endl;

	return 0;
	
}
