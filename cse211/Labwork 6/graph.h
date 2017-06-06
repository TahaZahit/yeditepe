#pragma once

#include <vector>

class Graph{
private:
	std::vector< std::vector<int> > graph;

public:
	Graph(int *, int);
	
	int indegree(int);
	int outdegree(int);
	int num_edges();

	std::vector<int> dfs(int);
	std::vector<int> bfs(int);
	std::vector<int> shortest_path(int, int);
};