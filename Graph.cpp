#include "stdafx.h"
#include "Graph.h"

#include <iostream>
#include <list>
#include <queue>
#include <utility>
#include <limits>
#include <functional>

Graph::Graph(int v)
{
	this->V = v;
	adj = new std::list<std::pair<int,int>>[V];
}
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(std::make_pair(w, 1));
}
void Graph::addEdge(int v, int w, int wt)
{
	adj[v].push_back(std::make_pair(w, wt));
}
bool Graph::is_connected()
{
	bool* visited = new bool[V];
	int count = 0;
	std::list<int> q;
	for (int i = 0; i < V; i++)
		visited[i] = false;
	visited[0] = true;
	count++;
	q.push_back(0);
	std::list<std::pair<int,int>>::iterator i;
	int temp;
	while (!q.empty())
	{
		temp = q.front();
		q.pop_front(); 
			for (i = adj[temp].begin(); i != adj[temp].end(); ++i)
				if (!visited[i->first])
				{
					q.push_back(i->first);
					visited[i->first] = true;
					count++;
				}
	}
	if (count != V) return false;
	return true;
}
bool Graph::is_path(int s, int d)
{
	//To avoid loops flag the visited nodes.
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	visited[s] = true;

	std::list<int> q;
	std::list<std::pair<int,int>>::iterator i;
	q.push_back(s);
	int temp(0);
	while (!q.empty()&& !visited[d])
	{
		temp = q.front();
		q.pop_front();

		for (i = adj[temp].begin(); i != adj[temp].end(); i++)
		{
			if (visited[d]) break;
			if (!visited[i->first])
			{
				q.push_back(i->first);
				visited[i->first] = true;
			}
		}

	}
	if (visited[d]) return true;
	return false;
}
void Graph::shortest_pfrom(int s)
{
	int* dist = new int[V];
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	bool* sptSet = new bool[V];
	for (int i = 0; i < V; i++)
		sptSet[i] = false;

	dist[s] = 0;
	sptSet[s] = true;

	std::priority_queue < std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	pq.push(std::make_pair(0, s));
	dist[s] = 0;
	std::list<std::pair<int, int>>::iterator i;
	while (!pq.empty())
	{
		
		int u = pq.top().second;
		pq.pop();

		for (i = adj[u].begin(); i != adj[u].end(); i++)
		{
			int v = (*i).first;
			int weight = (*i).second;

			if (dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				pq.push(std::make_pair(dist[v], v));
			}
		}
	}
	for (int i = 0; i < V; i++)
	{
		std::cout << "Distance from source to vertex " << i << "  " << dist[i]<<std::endl;
	}
}
Graph::~Graph()
{
	std::cout << "Graph is deleted.";
}


