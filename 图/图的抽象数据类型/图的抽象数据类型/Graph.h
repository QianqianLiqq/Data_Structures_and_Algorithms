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
	int VerticesNum();//����ͼ�Ķ������
	int EdgesNum();//����ͼ�ı���
	Edge FirstEdge(int oneVertex);//�����붥��oneVertex������ĵ�һ����
	Edge NextEdge(Edge preEdge);//�������preEdge����ͬ��������oneVertex����һ����
	bool setEdge(int fromVertex, int toVertex, int weight);//���һ����
	bool delEdge(int fromVertex, int toVertex);//ɾһ����
	bool isEdge(Edge oneEdge);//���oneEdge�Ǳ��򷵻�true�����򷵻�false
	int fromVertex(Edge oneEdge);//���ر�oneEdge��ʼ��
	int toVertex(Edge oneEdge);//���ر�oneEdge���յ�
	int Weight(Edge oneEdge);//���ر�oneEdge��Ȩ
	State Mark(int V);//Ϊ�������ñ�־λ
	int Indegree(int V);
	//ͼ������
	void graph_traverse(Graph& G);
	//�����������
	void DFS(Graph& G, int V);
	//�����������
	void BFS(Graph& G, int V);
	//���з�ʽʵ�ֵ���������
	void TopsortbyQueue(Graph& G);
	//�����������ʵ�ֵ���������--->ֻ��������޻�ͼ
	int* TopsortbyDFS(Graph& G);
};

