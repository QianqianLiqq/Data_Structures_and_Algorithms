#pragma once
#include<vector>

typedef struct SUser{
	int nNumb;
	char sName[20];
	float fMath;
} DATA;

typedef bool(*By_FUNC)(int q, int m);//Ö¸Õëº¯Êý


class CStudent
{	
private:
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
	int Sort(By_FUNC pFunc);
	
public:
	static std::vector<DATA> m_arr;
	CStudent();
	~CStudent();
	void Start();		
	void Load();
	int SortMenu();
	void PrintPS(int *ps);
};

