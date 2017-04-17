#pragma once
#include<list>

typedef struct Student{
	int nNumb;
	char sName[20];
	float fMath;
}DATA;

typedef bool(*BY_FUNC)(DATA &q, DATA &m);

class CStudent
{
	std::list<DATA> m_list;
public:
	CStudent();
	~CStudent();
	static bool ByNumb(DATA &d1, DATA &d2){
		return d1.nNumb < d2.nNumb;
	}

	static bool ByName(DATA &d1, DATA &d2){
		return strcmp(d1.sName, d2.sName) < 0;
	}

	static bool ByMath(DATA &d1, DATA &d2){
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
	void Sort(BY_FUNC pFunc);
	void PrintPS(std::list<DATA>::iterator* ps, int n);
};

