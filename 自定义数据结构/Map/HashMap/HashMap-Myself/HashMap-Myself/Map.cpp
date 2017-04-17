#include "Map.h"
#include<iostream>

CMap::CMap(int nCount)
{
	memset(m_hash, '\0', sizeof(m_hash));
	//new SNode*[nCount];//堆内
}


CMap::~CMap()
{
}

void CMap::SetAt(KEY key, VALUE& value){
	int n = key%COUNT;
	SNode *p = new SNode;
	p->key = key;
	p->value = value;
	p->pNext = m_hash[n];
	m_hash[n] = p;
}

bool CMap::Lookup(KEY key, VALUE& rValue)const{ //rValu为输出型参数
	int n = key%COUNT;
	SNode* p = m_hash[n];
	while (p){
		if (p->key == key){
			rValue = p->value;
			return true;
		}
		p = p->pNext;
	}
	return false;
}