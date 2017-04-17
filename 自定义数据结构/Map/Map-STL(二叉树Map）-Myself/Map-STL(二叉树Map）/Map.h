#pragma once
struct SStud{
	int nNumb;
	char sName[20];
	float fMath;
};
typedef int KEY;
typedef SStud VALUE;
struct SNode{
	KEY key;
	VALUE value;
	SNode *pLeft, *pRight;
	SNode(const KEY& k, const VALUE& v):key(k),value(v){
		pLeft = pRight = nullptr;
	}
};
class CMap
{
	SNode *m_pRoot;
public:
	CMap();
	virtual ~CMap();
	
	void SetAt(const KEY& key, const VALUE& value){
		(*this)[key] = value;
	}
	bool Lookup(KEY key, VALUE & rValue)const;
	VALUE& operator[](KEY key);
	void RemoveAll();
	void RemoveKey(SNode* p);
};

