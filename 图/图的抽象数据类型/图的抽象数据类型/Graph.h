#pragma once
struct Edge{
	int fromVertex;
	int toVertex;
};
enum State{UNVISITED,VISITED,PUSHED};
class Graph
{
	int vertex;
	Edge edge;
public:
	Graph();
	~Graph();
	int VerticesNum();//返回图的顶点个数
	int EdgesNum();//返回图的边数
	Edge FirstEdge(int oneVertex);//返回与顶点oneVertex相关联的第一条边
	Edge NextEdge(Edge preEdge);//返回与边preEdge有相同关联顶点oneVertex的下一条边
	bool setEdge(int fromVertex, int toVertex, int weight);//添加一条边
	bool delEdge(int fromVertex, int toVertex);//删一条边
	bool isEdge(Edge oneEdge);//如果oneEdge是边则返回true，否则返回false
	int fromVertex(Edge oneEdge);//返回边oneEdge的始点
	int toVertex(Edge oneEdge);//返回边oneEdge的终点
	int Weight(Edge oneEdge);//返回边oneEdge的权
	State Mark(int V);//为顶点设置标志位
	int Indegree(int V);
	//图的周游
	void graph_traverse(Graph& G);
	//深度优先搜索
	void DFS(Graph& G, int V);
	//广度优先搜索
	void BFS(Graph& G, int V);
	//队列方式实现的拓扑排序
	void TopsortbyQueue(Graph& G);
	//深度优先搜索实现的拓扑排序--->只针对有向无环图
	int* TopsortbyDFS(Graph& G);
};

