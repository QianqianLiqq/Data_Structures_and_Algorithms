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
	CArray<DATA> m_arr;
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
	static bool byName(const DATA& d1, const DATA& d2){
		return strcmp(d1.sName, d2.sName) < 0;
	}
	static bool byPriority(const DATA& d1, const DATA& d2){
		return d1.nPrior < d2.nPrior;
	}
};

