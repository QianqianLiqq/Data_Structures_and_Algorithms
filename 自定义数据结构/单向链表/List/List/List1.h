#pragma once
typedef int DATA;
struct SNode{
	DATA data;
	SNode* pNext;
};
class CList1
{
	SNode* m_pHead;
public:
	CList1();
	~CList1();
	void addHead(DATA data);
	void addTail(DATA data);
	int getCount();
	void Print();
};

