#pragma once
typedef struct SData{
	int nNumb;
	char sName[20];
	float fMath;
}DATA;
typedef int KEY;
typedef DATA VALUE;
struct SNode{
	KEY key;
	VALUE value;
	SNode* pNext;
};
class CMap
{
	enum{ COUNT = 101 };
	SNode* m_hash[COUNT];//Õ»ÄÚ
public:
	CMap(int nCount=101);
	~CMap();
	void SetAt(KEY key, VALUE& value);
	bool Lookup(KEY key, VALUE& rValue)const;
};

