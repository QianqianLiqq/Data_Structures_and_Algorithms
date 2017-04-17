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
	int m_nCount;
	SNode** m_pHash;
public:
	CMap(int nCount=17);
	~CMap();
	void SetAt(KEY key, VALUE& value);
	bool Lookup(KEY key, VALUE& rValue)const;
};

