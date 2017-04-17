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
	RemoveAll();
}
/*
void CMap::SetAt(KEY key, VALUE& value){
	int n = key%m_nCount;
	SNode *p = m_pHash[n],*p1=p;
	if (!p){
		SNode *pData = new SNode;
		pData->key = key;
		pData->value = value;
		pData->pNext = NULL;
		m_pHash[n] = pData;
		return;
	}
	while (p){
		if (p->key == key){
			p->value = value;
			return;
		}
		p1 = p;
		p = p->pNext;
	}
	SNode *pData = new SNode;
	pData->key = key;
	pData->value = value;
	pData->pNext = NULL;
	p1->pNext = pData;
}
*/
void CMap::SetAt(KEY key, VALUE& value){
	//两种方法调用下标
	//operator[](key) = value;
	(*this)[key] = value;
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
/*
VALUE& CMap::operator[](KEY key){
	int n = key%m_nCount;
	SNode* p = m_pHash[n],*p1=p;
	if (!p){
		SNode*pData = new SNode;
		pData->key = key;
		pData->pNext = NULL;
		m_pHash[n] = pData;
		return pData->value;
	}
	while (p){
		if (p->key == key)
			return p->value;
		p1 = p;
		p = p->pNext;
	}
	SNode*pData = new SNode;
	pData->key = key;
	pData->pNext = NULL;
	p1->pNext = pData;
	return pData->value;
}
*/
//微软的写法
VALUE& CMap::operator[](KEY key){
	int n = key%m_nCount;
	SNode** p = &m_pHash[n];	
	while (*p){
		if ((*p)->key == key)
			return (*p)->value;
		p = &((*p)->pNext);
	}
	SNode*pData = new SNode;
	pData->key = key;
	pData->pNext = NULL;
	*p = pData;
	return pData->value;
}
/*
bool CMap::RemoveKey(KEY key){
	int n = key%m_nCount;
	SNode* p = m_pHash[n],*p1=NULL;
	if (!p)
		return false;
	if (p->key == key){
		m_pHash[n] = p->pNext;
		delete p;
		return true;
	}
	while (p){
		if (p->key == key){
			p1->pNext = p->pNext;
			delete p;
			return true;
		}
		p1 = p;
		p = p->pNext;
	}
	return false;
}
*/
bool CMap::RemoveKey(KEY key){
	int n = key%m_nCount;
	if (!m_pHash[n])
		return false;
	SNode** p = &m_pHash[n];
	while (*p){
		if ((*p)->key == key)
			break;
		p = &((*p)->pNext);
	}
	if (!*p)
		return false;
	SNode *p1 = *p;
	*p = (*p)->pNext;
	delete []p1;
	return true;
}

void CMap::RemoveAll(){
	int i = 0;
	while (i < m_nCount){
		SNode *p = m_pHash[i], *p1 = p;
		while (p){
			p1 = p;
			p = p->pNext;
			delete p1;
		}
		m_pHash[i] = NULL;
		++i;
	}
}