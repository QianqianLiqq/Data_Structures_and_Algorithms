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
	//��ͼ���ж���ı�־λ���г�ʼ��
	for (int i = 0; i < G.VerticesNum(); ++i)
		G.Mark[i] = UNVISITED;
	//���ͼ�����ж����Ƿ񱻱�ǹ������δ����ǣ���Ӹ�δ����ǵĶ��㿪ʼ��������
	//do_traverse������������Ȼ��߹������
	for (int i = 0; i < G.VerticesNum(); ++i)
		if (G.Mark[i] == UNVISITED)
			//do_traverse(G, i);
			DFS(G, i);//�����������
}

void Graph::DFS(Graph& G, int V){
	G.Mark[V] = VISITED;//���ʶ���V����������־λ
	//PreVisit(G, V);//����V
	for (Edge e = G.FirstEdge(V); G.isEdge(e); e = G.NextEdge(e))
		//����V�ڽӵ���δ�����ʹ��Ķ��㣬���ݹ鰴��������ȵķ�ʽ��������
		if (G.Mark[G.toVertex(e)] == UNVISITED)
			DFS(G, G.toVertex(e));
	//PostVisited(G, V);//����V
}

void Graph::BFS(Graph& G, int V){
	//��ʼ�������������Ҫ�õ��Ķ���
	queue<int> q;
	//���ʶ���V����������־λ��V���
	G.Mark[V] = VISITED;
	//Visit(G,V);
	q.push(V);
	while (!q.empty()){
		int V = q.front();//����Ԫ��
		q.pop();
		//����ĵ����ڵ�ÿһ��δ���ʵ㶼���
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
		G.Mark[i] = UNVISITED;//��ʼ���������
	queue<int> q;
	for (int i = 0; i < G.VerticesNum(); ++i){
		if (G.Indegree[i] == 0)
			q.push(i);//ͼ�����Ϊ0�Ķ������
	}
	while (!q.empty()){//��������л���ͼ����
		int V = q.front();
		q.pop();
		//Visit(G,V);
		G.Mark[V] = VISITED;
		//��e���յ�����ֵ��1��
		for (Edge e = G.FirstEdge(V); G.isEdge(e); e = G.NextEdge(e)){
			G.Indegree[G.toVertex(e)]--;
			if (G.Indegree[G.toVertex(e)] == 0)
				q.push(G.toVertex(e));//���Ϊ0�ĵ����
		}
	}
	for (int i = 0; i < G.VerticesNum(); ++i)
		if (G.Mark[i] == UNVISITED){
			std::cout << "ͼ�л�" << std::endl;
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
			do_topsort(G, i, result, tag);//���õݹ麯��
	for (int i = G.VerticesNum() - 1; i >= 0; --i)//�������
		//Visit(G, result[i]);
	return result;
}

void do_topsort(Graph& G, int V, int* result, int& tag){
	G.Mark[V] = VISITED;
	for (Edge e = G.FirstEdge(V); G.isEdge(e); e = G.NextEdge(e)){
		//����V�ڽӵ�������δ�����ʹ��Ķ���
		if (G.Mark[G.toVertex(e)] == UNVISITED)
			do_topsort(G, G.toVertex(e), result, tag);
	}
	//�൱�ں���
	result[tag++] = V;
}
