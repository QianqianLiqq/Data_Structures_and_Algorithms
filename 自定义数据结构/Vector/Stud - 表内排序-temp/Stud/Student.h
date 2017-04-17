#pragma once
#include<vector>

typedef struct SUser{
	int nNumb;
	char sName[20];
	float fMath;
} DATA;

typedef bool(*By_FUNC)(DATA &q, DATA &m);//Ö¸Õëº¯Êý


class CStudent
{	
private:
	std::vector<DATA> m_arr;
	int Menu();
	int Input();
	bool Delete();
	bool Modify();
	bool Check(int nNumb);
	void ColorSet();
	void Welcome();
	void Print(std::vector<DATA> &cl);
	void Save();
	int FindMenu();
	void FindByNumb();
	void FindByName();
	void FindByMath();
	//int Sort(By_FUNC pFunc);
	
public:
	CStudent();
	~CStudent();
	void Start();		
	void Load();
	int SortMenu();
	void PrintPS(std::vector<DATA> *ps);
};

