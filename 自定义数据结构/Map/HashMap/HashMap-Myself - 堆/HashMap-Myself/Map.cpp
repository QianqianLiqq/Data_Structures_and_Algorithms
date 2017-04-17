#include "Map.h"
#include<iostream>

CMap::CMap(int nCount)
{
	m_pHash=new SNode*[nCount];//堆内
	memset(m_pHash, '\0', sizeof(SNode*)*nCount);
	m_nCount = nCount;
}


CMap::~CMap()
{
}

void CMap::SetAt(KEY key, VALUE& value){
	int n = key%m_nCount;
	SNode *p = new SNode;
	p->key = key;
	p->value = value;
	p->pNext = m_pHash[n];
	m_pHash[n] = p;
}

bool CMap::Lookup(KEY key, VALUE& rValue)const{ //rValu为输出型参数
	int n = key%m_nCount;
	SNode* p = m_pHash[n];
	while (p){
		if (p->key == key){
			rValue = p->value;
			return true;
		}
		p = p->pNext;
	}
	return false;
}