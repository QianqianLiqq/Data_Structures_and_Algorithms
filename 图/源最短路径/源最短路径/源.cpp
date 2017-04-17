#include<iostream>
#include<vector>
using namespace std;

const int NO_EDGE = 10000000;

struct MatrixGraph{
	vector<vector<int>> weights;
	int vertexNum; //其实定义了邻接矩阵，这个也可以省
};

void displayPath(vector<int> distance, vector<int> path, int startNode);
vector<int> getVisitPath(vector<int> path, int startNode, int endNode);

void dijkstra(vector<vector<int>> weights,int startNode){
	vector<int> distance;//源点到每个点的直接可达路径（距离）
	for (int j = 0; j < weights.size(); ++j)
		distance.push_back(weights[startNode][j]);

	vector<int> S;//被访问的点为1，未被访问的为0
	for (int j = 0; j < weights.size(); ++j)
		S.push_back(0);
	S[startNode] = 1;

	vector<int> path;//访问路径
	for (int j = 0; j < weights.size(); ++j){
		if (weights[startNode][j] == NO_EDGE)
			path.push_back(-1);
		else
			path.push_back(startNode);
	}
	path[startNode] = startNode;

	int minDistance;
	int k;//最近的点
	for (int i = 0; i < weights.size(); ++i){
		minDistance = NO_EDGE;
		for (int j = 0; j < weights.size(); ++j){
			if (S[j] == 0 && distance[j] < minDistance){
				minDistance = distance[j];
				k = j;
			}
		}
		S[k] = 1;
		for (int j = 0; j < weights.size(); ++j){
			if (distance[k] + weights[k][j] < distance[j]){
				distance[j] = distance[k] + weights[k][j];
				path[j] = k;
			}
		}
	}
	displayPath(distance, path, startNode);
}

void displayPath(vector<int> distance, vector<int> path, int startNode){
	for (int i = 0; i < distance.size(); ++i){
		if (distance[i] != NO_EDGE&&i != startNode){//排除自己以及不可达路径
			vector<int> visitPath = getVisitPath(path, startNode, i);
			cout << "From " << startNode << " To " << i << " || ";
			cout << "Distance: " << distance[i] << " || path: ";
			for (int j = 0; j < visitPath.size() - 1; ++j){
				cout << visitPath[j] << "->";
			}
			cout << visitPath[visitPath.size() - 1] << endl;
		}
	}
}

// 路径格式转换(从点对链接式转换到序列式)
vector<int> getVisitPath(vector<int> path, int startNode, int endNode){
	vector<int> visitPath;
	visitPath.push_back(endNode);
	if (path[endNode] != -1){
		while (path[endNode] != startNode){
			visitPath.insert(visitPath.begin(), path[endNode]);
			endNode = path[endNode];
		}
	}
	visitPath.insert(visitPath.begin(), startNode);
	return visitPath;
}

int main(){
	MatrixGraph graph;
	graph.weights.push_back(vector<int>{ 0, 4, 6, 6, NO_EDGE, NO_EDGE, NO_EDGE });
	graph.weights.push_back(vector<int>{ NO_EDGE, 0, 1, NO_EDGE, 7, NO_EDGE, NO_EDGE });
	graph.weights.push_back(vector<int>{ NO_EDGE, NO_EDGE, 0, NO_EDGE, 6, 4, NO_EDGE });
	graph.weights.push_back(vector<int>{ NO_EDGE, NO_EDGE, 2, 0, NO_EDGE, 5, NO_EDGE });
	graph.weights.push_back(vector<int>{ NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, 0, NO_EDGE, 6 });
	graph.weights.push_back(vector<int>{ NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, 1, 0, 8 });
	graph.weights.push_back(vector<int>{ NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, 0 });
	dijkstra(graph.weights, 1);
	system("pause");
	return 0;
}