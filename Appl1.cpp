// Appl1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include "utilf.h"
#include "utilf.h"

#include <iostream>

template <class T>
T max(T x, T y)
{
	return (x > y) ? x : y;
}


int main()
{
	int V(9);
	Graph g(V);
	int source(0), dest(0);

	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 0, 1);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	if (g.is_connected())
	{
		std::cout << "connected." << std::endl;
	}
	else std::cout << "not connected." << std::endl;
	std::cin >> source >> dest;
	// We can access static variable without creating an instance.
	std::cout << "Min is " << utilf<int>::min(source, dest) << std::endl;

    if (g.is_path(source, dest))
	{
		std::cout << "There is a path." << std::endl;
	}
	else std::cout << "no path found." << std::endl;
	
	g.shortest_pfrom(source);
    return 0;
}