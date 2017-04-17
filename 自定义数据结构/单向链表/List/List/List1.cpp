#include "List1.h"
#include<iostream>
using namespace std;

CList1::CList1()
{
}


CList1::~CList1()
{
}


void CList1::addHead(DATA data)
{
	SNode* p = new SNode;
	p->data = data;
	p->pNext = m_pHead;
	m_pHead = p;
}


void CList1::addTail(DATA data)
{
	SNode* pNew = new SNode;
	pNew->data = data;
	pNew->pNext = NULL;
	if (!m_pHead){
		m_pHead = pNew;
	}
	else{
		SNode* p = m_pHead;
		while (p->pNext != NULL){
			p = p->pNext;
		}
		p->pNext = pNew;
	}
}


int CList1::getCount()
{
	int i = 0;
	SNode* p = m_pHead;
	while (p){
		p = p->pNext;
		i++;
	}
	return i;
}


void CList1::Print()
{
	SNode* p = m_pHead;
	while (p){
		cout << p->data << endl;
		p = p->pNext;
	}
}
