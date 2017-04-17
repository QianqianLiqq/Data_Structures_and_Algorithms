#include<iostream>
#include<vector>
#include<queue>
#include"Graph.h"
using namespace std;

int main(){
	Graph graph;
	graph.weights.push_back(vector<int>{ 0, 4, 6, 6, NO_EDGE, NO_EDGE, NO_EDGE });
	graph.weights.push_back(vector<int>{ NO_EDGE, 0, 1, NO_EDGE, 7, NO_EDGE, NO_EDGE });
	graph.weights.push_back(vector<int>{ NO_EDGE, NO_EDGE, 0, NO_EDGE, 6, 4, NO_EDGE });
	graph.weights.push_back(vector<int>{ NO_EDGE, NO_EDGE, 2, 0, NO_EDGE, 5, NO_EDGE });
	graph.weights.push_back(vector<int>{ NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, 0, NO_EDGE, 6 });
	graph.weights.push_back(vector<int>{ NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, 1, 0, 8 });
	graph.weights.push_back(vector<int>{ NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, 0 });
	//graph.BFS(graph);
	graph.DFS(graph);
	system("pause");
	return 0;
}