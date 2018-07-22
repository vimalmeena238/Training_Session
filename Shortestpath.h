#pragma once

#include"Graph.h"
#include <iostream>
#include <queue>
#include <vector>
class Shortestpath
{
private:
	int dest;
	int src;
public:
	Shortestpath(Graph& G);
	Shortestpath(int src,Graph& G);
	~Shortestpath();
};