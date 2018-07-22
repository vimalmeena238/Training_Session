#include "stdafx.h"
#include "Graph.h"
#include "Shortestpath.h"

#include <iostream>
#include <functional>
#include <limits>
#include <queue>

Shortestpath::Shortestpath(Graph& G)
{
	this->src = 0;
	this->dest = 0;

}

Shortestpath::Shortestpath(int src, Graph& G)
{
	this->src = src;
	{
		std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>> > pq;
		std::vector<int> dist(G.V(G), 1000);

		pq.push(std::make_pair(0, src));
		dist[src] = 0;
		std::list< std::pair<int, int> >*  adj = G.neighbors(0);
		while (!pq.empty())
		{
			int u = pq.top().second;
			pq.pop();
			std::list< std::pair<int, int> >::iterator i;
			
			for (i = adj[u].begin(); i != adj[u].end(); ++i)
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
		std::cout<< "Vertex   Distance from Source" <<std::endl;
		for (int i = 0; i < G.V(G); ++i)
			std::cout << i <<"    "<< dist[i] << std::endl;
	}
}
Shortestpath::~Shortestpath()
{
	std::cout << "Shortest path deleted." << std::endl;
}