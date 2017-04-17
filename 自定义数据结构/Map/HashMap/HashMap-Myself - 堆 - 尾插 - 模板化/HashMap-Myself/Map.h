#pragma once
typedef struct SData{
	int nNumb;
	char sName[20];
	float fMath;
}DATA;
template<typename KEY,typename VALUE,typename ARG_VALUE=const VALUE&>//传参的地方为ARG_VALUE
class CMap //字典  映射
{
	struct SNode{
		KEY key;
		VALUE value;
		SNode* pNext;
	};
	int m_nCount;
	SNode** m_pHash;
public:
	CMap(int nCount=17);
	~CMap();
	void SetAt(KEY key, ARG_VALUE value);
	bool Lookup(KEY key, VALUE& rValue)const;
	VALUE& operator[](KEY key);
	bool RemoveKey(KEY key);
	void RemoveAll();
};

template<typename KEY, typename VALUE, typename ARG_VALUE = const VALUE&>
CMap<KEY,VALUE,ARG_VALUE>::CMap(int nCount)
{
	m_pHash = new SNode*[nCount];//堆内
	memset(m_pHash, '\0', sizeof(SNode*)*nCount);
	m_nCount = nCount;
}

template<typename KEY, typename VALUE, typename ARG_VALUE = const VALUE&>
CMap<KEY, VALUE, ARG_VALUE>::~CMap()
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
template<typename KEY, typename VALUE, typename ARG_VALUE = const VALUE&>
void CMap<KEY, VALUE, ARG_VALUE>::SetAt(KEY key, ARG_VALUE value){
	//两种方法调用下标
	//operator[](key) = value;
	(*this)[key] = value;
}
template<typename KEY, typename VALUE, typename ARG_VALUE = const VALUE&>
bool CMap<KEY, VALUE, ARG_VALUE>::Lookup(KEY key, VALUE& rValue)const{ //rValu为输出型参数
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
template<typename KEY, typename VALUE, typename ARG_VALUE = const VALUE&>
VALUE& CMap<KEY, VALUE, ARG_VALUE>::operator[](KEY key){
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
template<typename KEY, typename VALUE, typename ARG_VALUE = const VALUE&>
bool CMap<KEY, VALUE, ARG_VALUE>::RemoveKey(KEY key){
	int n = key%m_nCount;
	SNode* p = m_pHash[n], *p1 = NULL;
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
template<typename KEY, typename VALUE, typename ARG_VALUE = const VALUE&>
void CMap<KEY, VALUE, ARG_VALUE>::RemoveAll(){
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