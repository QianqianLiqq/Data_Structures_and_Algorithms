#include "Graph.h"
#include<iostream>
#include<queue>
using namespace std;

Graph::Graph()
{
}


Graph::~Graph()
{
}

void Graph::BFSUtil(int V, vector<bool>& visited){
	visited[V] = true;
	queue<int> vertexQueue;
	vertexQueue.push(V);
	while (!vertexQueue.empty()){
		int temp = vertexQueue.front();
		cout << temp << endl;
		vertexQueue.pop();
		for (int i = 0; i < weights.size(); ++i){
			if (weights[temp][i] != 0 && weights[temp][i] != NO_EDGE && visited[i] == false){
				vertexQueue.push(i);
				visited[i] = true;
			}
		}
	}
}

void Graph::BFS(Graph& G){
	vector<bool> visited;
	for (int i = 0; i < weights.size(); ++i)
		visited.push_back(false);
	for (int i = 0; i < G.weights.size(); ++i){
		if (visited[i] == false)
			BFSUtil(i, visited);
	}
}

void Graph::DFSUtil(int V, vector<bool>& visited){
	cout << V << endl;
	visited[V] = true;
	for (int i = 0; i < weights.size(); ++i){
		if (weights[V][i] != 0 && weights[V][i] != NO_EDGE&&visited[i] == false){
			DFSUtil(i, visited);
		}
	}
}

void Graph::DFS(Graph& G){
	vector<bool> visited;
	for (int i = 0; i < weights.size(); ++i)
		visited.push_back(false);
	for (int i = 0; i < G.weights.size(); ++i){
		if (visited[i] == false)
			DFSUtil(i, visited);
	}
}