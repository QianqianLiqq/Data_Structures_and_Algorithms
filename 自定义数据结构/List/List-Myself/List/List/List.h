#pragma once

typedef int DATA;
typedef void *POSITION;
struct SNode{
	DATA data;
	SNode *pPrev, *pNext;
};
class CList
{
	SNode *m_pHead, *m_pTail;
	int m_nCount;
public:
	CList();
	~CList();
	POSITION GetHeadPosition(){
		return m_pHead;
	}
	POSITION GetTailPosition(){
		return m_pTail;
	}
	int GetCount(){
		return m_nCount;
	}
	DATA GetAt(POSITION pos){
		return ((SNode*)pos)->data;
	}
	void RemoveAll();
	DATA GetNext(POSITION &pos);
	DATA GetPrev(POSITION &pos);
	void AddHead(DATA data);
	void AddTail(DATA data);
	void SetAt(POSITION pos, DATA data);
	void RemoveAt(POSITION pos);
};

