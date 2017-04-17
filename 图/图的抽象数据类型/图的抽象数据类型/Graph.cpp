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

void Graph::graph_traverse(Graph& G){
	//对图所有顶点的标志位进行初始化
	for (int i = 0; i < G.VerticesNum(); ++i)
		G.Mark[i] = UNVISITED;
	//检查图的所有顶点是否被标记过，如果未被标记，则从该未被标记的顶点开始继续周游
	//do_traverse函数用深度优先或者广度优先
	for (int i = 0; i < G.VerticesNum(); ++i)
		if (G.Mark[i] == UNVISITED)
			//do_traverse(G, i);
			DFS(G, i);//深度优先搜索
}

void Graph::DFS(Graph& G, int V){
	G.Mark[V] = VISITED;//访问顶点V，并标记其标志位
	//PreVisit(G, V);//访问V
	for (Edge e = G.FirstEdge(V); G.isEdge(e); e = G.NextEdge(e))
		//访问V邻接到的未被访问过的顶点，并递归按照深度优先的方式进行周游
		if (G.Mark[G.toVertex(e)] == UNVISITED)
			DFS(G, G.toVertex(e));
	//PostVisited(G, V);//访问V
}

void Graph::BFS(Graph& G, int V){
	//初始化广度优先周游要用到的队列
	queue<int> q;
	//访问顶点V，并标记其标志位，V入队
	G.Mark[V] = VISITED;
	//Visit(G,V);
	q.push(V);
	while (!q.empty()){
		int V = q.front();//顶部元素
		q.pop();
		//将与改点相邻的每一个未访问点都入队
		for (Edge e = G.FirstEdge(V); G.isEdge(e); e = G.NextEdge(e)){
			if (G.Mark[G.toVertex(e)] == UNVISITED){
				G.Mark[G.toVertex(e)] = VISITED;
				//Visit(G, G.toVertex(e));
				q.push(G.toVertex(e));
			}
		}
	}
}

void Graph::TopsortbyQueue(Graph& G){
	for (int i = 0; i < G.VerticesNum(); ++i)
		G.Mark[i] = UNVISITED;//初始化标记数组
	queue<int> q;
	for (int i = 0; i < G.VerticesNum(); ++i){
		if (G.Indegree[i] == 0)
			q.push(i);//图中入度为0的顶点入队
	}
	while (!q.empty()){//如果队列中还有图顶点
		int V = q.front();
		q.pop();
		//Visit(G,V);
		G.Mark[V] = VISITED;
		//边e的终点的入度值减1；
		for (Edge e = G.FirstEdge(V); G.isEdge(e); e = G.NextEdge(e)){
			G.Indegree[G.toVertex(e)]--;
			if (G.Indegree[G.toVertex(e)] == 0)
				q.push(G.toVertex(e));//入度为0的点入队
		}
	}
	for (int i = 0; i < G.VerticesNum(); ++i)
		if (G.Mark[i] == UNVISITED){
			std::cout << "图有环" << std::endl;
			break;
		}
}

int* Graph::TopsortbyDFS(Graph& G){
	for (int i = 0; i < G.VerticesNum(); ++i)
		G.Mark[i] = UNVISITED;
	int *result = new int[G.VerticesNum()];
	int tag = 0;
	for (int i = 0; i < G.VerticesNum(); ++i)
		if (G.Mark[i] == UNVISITED)
			do_topsort(G, i, result, tag);//调用递归函数
	for (int i = G.VerticesNum() - 1; i >= 0; --i)//逆序输出
		//Visit(G, result[i]);
	return result;
}

void do_topsort(Graph& G, int V, int* result, int& tag){
	G.Mark[V] = VISITED;
	for (Edge e = G.FirstEdge(V); G.isEdge(e); e = G.NextEdge(e)){
		//访问V邻接到的所有未被访问过的顶点
		if (G.Mark[G.toVertex(e)] == UNVISITED)
			do_topsort(G, G.toVertex(e), result, tag);
	}
	//相当于后处理
	result[tag++] = V;
}
