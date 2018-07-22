#include "stdafx.h"
#include "Graph.h"

#include <iostream>
#include <list>
#include <utility>

Graph::Graph(){
	this->Vert = 0;
}
Graph::Graph(int V)
{
	this->Vert = V;
	this->adj = new std::list <std::pair<int,int>>[V];
}
Graph::~Graph()
{
	std::cout << "Graph is deleted." << std::endl;
}
int Graph::V(Graph& G)
{
	return G.Vert;
}
int Graph::E(Graph& G)
{
	int numedge = 0;
	for (int i = 0; i < G.Vert; i++)
	{
		numedge += G.adj[i].size();
	}
	return numedge;
}
void Graph::add(Graph& G, int x, int y)
{
	G.adj[x].push_back(std::make_pair(y,1));
}
void Graph::deletee(Graph& G, int x, int y)
{
	for (std::list<std::pair<int,int>>::iterator it = G.adj[x].begin(); it != G.adj[x].end(); it++)
	{
		if (it->first == y)
		{
			G.adj[x].erase(it);
		}
	}
}
bool Graph::adjacent(Graph& G, int x, int y)
{
	for (std::list<std::pair<int, int>>::iterator it = G.adj[x].begin(); it != G.adj[x].end(); it++)
	{
		if (it->first == y)
		{
			return true;
		}
	}
	return false;
}
int Graph::get_edge_value(Graph& G, int x, int y)
{
	for (std::list<std::pair<int, int>>::iterator it = G.adj[x].begin(); it != G.adj[x].end(); it++)
	{
		if (it->first == y)
		{
			return it->second;
		}
	}
	return 0;
}
void Graph::set_edge_value(Graph& G, int x, int y, int a)
{
	for (std::list<std::pair<int, int>>::iterator it = G.adj[x].begin(); it != G.adj[x].end(); it++)
	{
		if (it->first == y)
		{
			it->second = a;
		}
	}
}
std::list<std::pair<int, int>>* Graph::neighbors(int x)
{
	return adj;
}

