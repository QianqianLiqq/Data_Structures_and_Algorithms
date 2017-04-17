#include "Map.h"


CMap::CMap()
{
	m_pRoot = nullptr;
}


CMap::~CMap()
{
	RemoveAll();
}

/*
void CMap::SetAt(KEY& key, VALUE& value)
{
	//SNode *pNew = new SNode(key, value);
	SNode *p = m_pRoot;
	if (!p){
		m_pRoot = new SNode(key, value);
		return;
	}
	while (p){
		if (p->key == key){
			p->value = value;
			return;
		}
		if (key < p->key){
			if (p->pLeft)
				p = p->pLeft;
			else{
				p->pLeft = new SNode(key, value);
				return;
			}
		}
		else{
			if (p->pRight)
				p = p->pRight;
			else{
				p->pRight = new SNode(key, value);
				return;
			}
		}
	}
}
*/

bool CMap::Lookup(KEY key, VALUE & rValue)const
{
	SNode *p = m_pRoot;
	while (p){
		if (key == p->key){
			rValue = p->value;
			return true;
		} 
		if (key < p->key)
			p = p->pLeft;
		else
			p = p->pRight;
	}
	return false;
}


VALUE& CMap::operator[](KEY key)
{//探索博大精深的算法
	SNode* p = m_pRoot;
	if (!p){
		m_pRoot = p = new SNode(key, VALUE());
		return p->value;
	}
	while (p){
		if (key == p->key)
			return p->value;
		if (key < p->key){
			if (p->pLeft)
				p = p->pLeft;
			else{
				p = p->pLeft = new SNode(key, VALUE());
				break;
			}
		}
		else{
			if (p->pRight)
				p = p->pRight;
			else{
				p = p->pRight = new SNode(key, VALUE());
				break;
			}
		}			
	}
	return p->value;
}


void CMap::RemoveAll()
{
	if (m_pRoot){
		RemoveKey(m_pRoot);
		m_pRoot = nullptr;
	}	   
}


void CMap::RemoveKey(SNode* p)
{
	if (p->pLeft)
		RemoveKey(p->pLeft);
	if (p->pRight)
		RemoveKey(p->pRight);
	delete p;
}
