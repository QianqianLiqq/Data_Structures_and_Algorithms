#include "List.h"

CList::CList()
{
	m_pHead = m_pTail = nullptr;
	m_nCount = 0;
}


CList::~CList()//析构函数只能删除类对象本身，还要delete掉类对象之外额外申请的堆空间
{
	RemoveAll();
}


void CList::RemoveAll()
{
	SNode *p = m_pHead, *q;
	while (p){
		q = p;
		p = p->pNext;
		delete q;
	}
	m_pHead = m_pTail = nullptr;
	m_nCount = 0;
}


DATA CList::GetNext(POSITION &pos)//返回当前节点的数据，并指向下一结点
{
	DATA d = ((SNode *)pos)->data;
	SNode *p = (SNode *)pos;
	pos = p->pNext;
	return d;
}


DATA CList::GetPrev(POSITION &pos)
{
	DATA d = ((SNode *)pos)->data;
	SNode *p = (SNode *)pos;
	pos = p->pPrev;
	return d;
}


void CList::AddHead(DATA data)
{
	SNode *p = new SNode;
	p->data = data;
	if (m_pHead)
		m_pHead->pPrev = p;
	else
		m_pTail = p;
	p->pNext = m_pHead;
	p->pPrev = nullptr;
	m_pHead = p;
	++m_nCount;
}


void CList::AddTail(DATA data)
{
	SNode *p = new SNode;
	p->data = data;
	if (m_pTail)
		m_pTail->pNext = p;
	else
		m_pHead = p;
	p->pPrev = m_pTail;
	p->pNext = nullptr;
	m_pTail = p;
	++m_nCount;
}


void CList::SetAt(POSITION pos, DATA data)
{
	((SNode *)pos)->data = data;
}


void CList::RemoveAt(POSITION pos)
{ 
	SNode *p = (SNode *)pos;
//	if (p == m_pHead){
//		m_pHead = p->pNext;
//	    p->pNext->pPrev = m_pHead;
//	}
//	else if (p == m_pTail){
//		m_pTail = p->pPrev;
//		p->pPrev->pNext = m_pTail;
//	}
//	else{
//		p->pPrev->pNext = p->pNext;
//		p->pNext->pPrev = p->pPrev;
//	}
	if (p == m_pHead)
		m_pHead = p->pNext;
	else
		p->pPrev->pNext = p->pNext;
	if (p == m_pTail)
		m_pTail = p->pPrev;
	else
		p->pNext->pPrev = p->pPrev;
	delete p;
	--m_nCount;
}

