#pragma once

#include<iostream>
#include <list>

class Graph
{
private:
	int  Vert;
	std::list <std::pair <int, int>> *adj;
public:
	Graph(int V);
	Graph();
	~Graph();
	int V(Graph& G);
	int E(Graph& G);
	bool adjacent(Graph& G,int x,int y);
	std::list<std::pair<int, int>>* neighbors(int );
	void add(Graph& G, int x, int y);
	void deletee(Graph& G,int x,int y);
	//int get_node_value(Graph& G, int x);
	//void set_node_value(Graph& G,int x,int a);
	int get_edge_value(Graph& G,int x,int y);
	void set_edge_value(Graph& G, int x,int y, int v);
};

