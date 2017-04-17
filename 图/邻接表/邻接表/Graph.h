#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef int DATA;
const DATA INIT_DATA = -1;
const int NO_NODE = -1;
const int NO_EDGE = -2;

class VNode{
public:
	bool visited;				//访问标志
	DATA data;				    //顶点内的数据
	vector<int> e;				//邻接的边
	VNode(DATA val = INIT_DATA, bool flag = false) :data(val), visited(flag){}
	void Visit()
	{
		cout << data << "\t";
	}
	bool operator== (VNode &y){
		if (data == y.data && e == y.e)
			return true;
		else
			return false;
	}
};
class Graph
{
public:
	Graph();
	~Graph();
};

