#pragma once
#include <iostream>  
#include<string>
#include<vector>
using namespace std;

#define MAXVEX 10           //最大顶点数，应由用户定义
#define INFINITY 0XFFFFFFFF //代表无穷大 
#define SUCCESS 1  
#define UNSUCCESS 0         
typedef int DATA; 
typedef int EdgeWeight;
typedef int Status;
enum Status { DISCOVERED, UNDISCOVERED };
typedef struct Vertex{
	DATA data;
	int inDegree, outDegree;
	Status status;
	Vertex(DATA const& d){
		data = d;
		inDegree = outDegree = 0;
		status = UNDISCOVERED;
	}
};
typedef struct Edge{
	DATA data;
	EdgeWeight weight;
	Status status;
	Edge(DATA const& d, EdgeWeight const& w){
		data = d;
		weight = w;
		status = UNDISCOVERED;
	}
};
class Graph
{ 
	vector<Vertex> V;
	vector<vector<Edge>> E;
	int vexnum, edgenum;
public:
	Graph();
	~Graph();
};

