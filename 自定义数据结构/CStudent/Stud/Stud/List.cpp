#include "List.h"

CList::CList()
{
	m_pHead = m_pTail = nullptr;
	m_nCount = 0;
}


CList::~CList()//析构函数只能删除类对象本身，还要delete掉类对象之外额外申请的堆空间
{
	clear();
}


void CList::clear()
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




void CList::push_front(DATA data)
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


void CList::push_back(DATA data)
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




void CList::erase(iterator it)
{ 
	SNode *p = (SNode *)it;
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
