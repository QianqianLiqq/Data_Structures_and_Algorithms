#pragma once
#include <afxtempl.h>

typedef struct SUser{
	int nNumb;
	char sName[20];
	float fMath;
} DATA;

typedef bool(*By_FUNC)(DATA &q, DATA &m);//Ö¸Õëº¯Êý

class CStudent
{	
private:
	CList<DATA> m_list;
	int Menu();
	int Input();
	bool Delete();
	bool Modify();
	bool Check(int nNumb);
	void ColorSet();
	void Welcome();
	void Print();
	void Save();
	int Sort(By_FUNC pFunc);
	int SortMenu();
	int FindMenu();
	bool FindByNumb();
	
public:
	CStudent();
	~CStudent();
	void Start();		
	void Load();

private:
	bool FindByMath();
};

