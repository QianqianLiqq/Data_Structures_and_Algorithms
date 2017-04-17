#pragma once
//#include <afxtempl.h>
#include "List.h"

typedef bool(*By_FUNC)(DATA &q, DATA &m);//Ö¸Õëº¯Êý

class CStudent
{	
private:
	CList m_list;
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
	void FindByMath();
	void FindByName();
public:
	CStudent();
	~CStudent();
	void Start();		
	void Load();

};

