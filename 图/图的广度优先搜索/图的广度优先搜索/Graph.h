#pragma once
#include<vector>
using namespace std;

const int NO_EDGE = 10000000;
class Graph
{
	void BFSUtil(int V, vector<bool>& visited);
	void DFSUtil(int V, vector<bool>& visited);
public:
	vector<vector<int>> weights;

	Graph();
	~Graph();
	void BFS(Graph& G);
	void DFS(Graph& G);
};

