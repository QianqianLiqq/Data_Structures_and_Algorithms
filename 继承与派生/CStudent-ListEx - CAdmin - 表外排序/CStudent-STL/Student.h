#pragma once
#include"ListEx.h"
#include"Admin.h"

typedef struct Student{
	int nNumb;
	char sName[20];
	float fMath;
}DATA;

class CStudent
{
	CListEx<DATA> m_list;
	CAdmin m_admin;
public:
	CStudent();
	~CStudent();
	static bool ByNumb(const DATA &d1, const DATA &d2){
		return d1.nNumb < d2.nNumb;
	}

	static bool ByName(const DATA &d1, const DATA &d2){
		return strcmp(d1.sName, d2.sName) < 0;
	}

	static bool ByMath(const DATA &d1, const DATA &d2){
		return d1.fMath > d2.fMath;
	}
	void Start();
	void Load();
	int Menu();
	int SortMenu();
	int Input();
	int Delete();
	int Modify();
	int FindMenu();
	void ColorSet();
	int Check(int numba);
	void Save();
	void Print();
	int FindByNumb();
	int FindByName();
	void FindByMath();
	void PrintPS(POSITION *ps);
};

