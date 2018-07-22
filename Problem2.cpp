#include "stdafx.h"
#include "Graph.h"
#include "Shortestpath.h"
#include <iostream>
int main()
{
	Graph g(9);
	g.add(g,0, 1);
	g.add(g,0, 7);
	g.add(g,1, 2);
	g.add(g,1, 7);
	g.add(g,2, 3);
	g.add(g,2, 8);
	g.add(g,2, 5);
	g.add(g,3, 4);
	g.add(g,3, 5);
	g.add(g,4, 5);
	g.add(g,5, 6);
	g.add(g,6, 7);
	g.add(g,6, 8);
	g.add(g,7, 8);
	g.set_edge_value(g,0 ,1 , 4);
	g.set_edge_value(g, 0, 7, 8);
	g.set_edge_value(g, 1, 2, 8);
	g.set_edge_value(g, 1, 7, 11);
	g.set_edge_value(g, 2, 3, 7);
	g.set_edge_value(g, 2, 8, 2);
	g.set_edge_value(g, 2, 5, 4);
	g.set_edge_value(g, 3, 4, 9);
	g.set_edge_value(g, 3, 5, 14);
	g.set_edge_value(g, 4, 5, 10);
	g.set_edge_value(g, 5, 6, 2);
	g.set_edge_value(g, 6, 7, 1);
	g.set_edge_value(g, 6, 8, 6);
	g.set_edge_value(g, 7, 8, 7);
	Shortestpath Shortestpath(0,g);

    return 0;
}

