#pragma once
#include <iostream>
template <class T>
class utilf
{
public:
	T static min(T x, T y)
	{
		return (x > y) ? y : x;
	}
	
};