#include "graph.h"
#include <stack>
#include <queue>

Graph::Graph(int * data, int num_vertices) {
	graph.resize(num_vertices);
	for (int i = 0; i < num_vertices; i++) {
		graph[i].resize(num_vertices);
	}

	for (int i = 0; i < num_vertices; i++) {
		for (int j = 0; j < num_vertices; j++) {
			graph[i][j] = data[i * num_vertices + j];
		}
	}
}

std::vector<int> Graph::dfs(int v) {
	std::stack<int> stack;
	std::vector<bool> visited;
	std::vector<int> path;

	visited.resize(graph.size(), false);

	visited[v] = true;
	stack.push(v);

	while (!stack.empty()) {
		int node = stack.top();
		stack.pop();

		path.push_back(node);
		
		for (int i = 0; i < graph.size(); i++) {
			if (graph[node][i] && !visited[i]) {
				stack.push(i);
				visited[i] = true;
			}
		}
	}

	return path;
}

std::vector<int> Graph::bfs(int v) {
	std::queue<int> q;
	std::vector<bool> visited;
	std::vector<int> path;

	visited.resize(graph.size(), false);

	visited[v] = true;
	q.push(v);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		path.push_back(node);

		for (int i = 0; i < graph.size(); i++) {
			if (graph[node][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}

	return path;
}

std::vector<int> Graph::shortest_path(int start, int end) {
	std::queue<int> q;
	std::queue<int> level;
	std::vector<int> visited;
	std::vector<int> path;

	visited.resize(graph.size(), -1);

	visited[start] = 0;
	level.push(0);
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		int step = level.front();
		level.pop();

		if (node == end)
			break;

		for (int i = 0; i < graph.size(); i++) {
			if (graph[node][i] && visited[i] == -1) {
				q.push(i);
				level.push(step + 1);
				visited[i] = step + 1;
			}
		}
	}

	if (visited[end] != -1) {
		int node = end;
		int step = visited[end];
		path.resize(step + 1);
		path[step] = end;

		while (step != 0) {
			for (int i = 0; i < graph.size(); i++) {
				if (graph[i][node] && visited[i] == step - 1) {
					path[step - 1] = i;
					node = i;
					step--;
					break;
				}
			}
		}
	}
	return path;
}