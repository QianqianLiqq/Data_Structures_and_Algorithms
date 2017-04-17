#pragma once
#include"Array.h"

typedef struct SUser{
	int nNumb;
	char sName[20];
	float fMath;
} DATA;

typedef bool(*By_FUNC)(DATA &q, DATA &m);//Ö¸Õëº¯Êý


class CStudent
{	
private:
	CArray<DATA> m_arr;
	int Menu();
	int Input();
	bool Delete();
	bool Modify();
	bool Check(int nNumb);
	void ColorSet();
	void Welcome();
	void Print(CArray<DATA> &cl);
	void Save();
	int FindMenu();
	void FindByNumb();
	void FindByName();
	void FindByMath();
	int Sort(By_FUNC pFunc);
	
public:
	CStudent();
	~CStudent();
	void Start();		
	void Load();
	int SortMenu();
	void PrintPS(int *ps);
};

