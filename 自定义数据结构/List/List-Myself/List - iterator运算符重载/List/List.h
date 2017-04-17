#pragma once

typedef struct SUser{
	int nNumb;
	char sName[20];
	float fMath;
} DATA;

//typedef CList::iterator POSITION;

struct SNode{
	DATA data;
	SNode *pPrev, *pNext;
};
class CList
{
	SNode *m_pHead, *m_pTail;
	int m_nCount;
public:
	class iterator{
		SNode *p;
	public:
		iterator(SNode *p){
			this->p = p;
		}
		DATA & operator*(){
			return p->data;
		}
		operator SNode*(){
			return p;
		}
		iterator& operator++(){ //++it
			p= p->pNext;
			return *this;//返回自身，使它可以连续做下一步操作
		}
		iterator operator++(int){ //it++
			iterator it = p;
			p = p->pNext;
			return it;
		}
		iterator& operator--(){
			p= p->pPrev;
			return *this;
		}
		iterator operator--(int ){
			iterator it = p;
			p = p->pPrev;
			return it;
		}
		DATA* operator->(){
			return &(p->data);
		}
	};
	CList();
	~CList();
	iterator begin(){
		return m_pHead;
	}
	iterator end(){
		return m_pTail;
	}
	int size(){
		return m_nCount;
	}
	
	void clear();
	
	void push_front(DATA data);
	void push_back(DATA data);
	void erase(iterator it);
};

