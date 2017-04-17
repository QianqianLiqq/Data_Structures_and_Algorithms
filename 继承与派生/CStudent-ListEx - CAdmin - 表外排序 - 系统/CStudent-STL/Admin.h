#pragma once
#include<afxtempl.h>
struct SAdmin{
	char sName[20];
	char sPass[20];
	int nPrior;
};

class CAdmin
{
	typedef SAdmin DATA;
	typedef bool(*BY_FUNC)(int d1, int d2);
	static CArray<DATA> m_arr;
	DATA m_data;
public:
	CAdmin();
	~CAdmin();
	int GetPriority() const{
		return m_data.nPrior;
	}
	const char * GetName() const{
		return m_data.sName;
	}
	bool Login();
	void Load();
	void Save();
	bool Try();
	void Start();
	int Menu();
	void ChangePass();
	void Print();
	void Input();
	int Delete();
	int Check(const char * pName);
	void Change(const char * sPass);
	int SortMenu();
	static bool byName(int d1, int d2){
		return strcmp(m_arr[d1].sName, m_arr[d2].sName) < 0;
	}
	static bool byPriority(int d1, int d2){
		return m_arr[d1].nPrior < m_arr[d2].nPrior;
	}
	void Sort(BY_FUNC pFunc);
	void PrintPS(int* ps);
};

