#pragma once
#include <iostream>
#include <list>
#include <vector>
class Graph
{
private:
	int V;
	std::list<std::pair<int,int>>* adj;
public:
	Graph(int);
    void addEdge(int, int);
	void addEdge(int, int, int);
	void shortest_pfrom(int);
	bool is_connected();
	bool is_path(int, int);
	~Graph();
};
