#pragma once
#include"ListEx.h"
#include"Admin.h"

struct SUser{
	int nType;//类型 0代表文科，1代表理科
	int nNumb;
	char sName[20];
	char cSex[4];//男女
	void Input();
	void Print();
};

struct SArt :SUser{ //派生,默认public
	float fHist;//历史
	float fChin;//汉语
	float fEngl;//英语
	float fGeog;//地理
	void Input();
	void Print();
};

struct SScn :SUser{
	float fmath;
	float fChem;
	float fPhys;
	void Input();
	void Print();
};

class CStudent
{
	typedef SUser DATA;
/*	typedef union SData{ //联合体或共用体,其长度取决于最大的结构体的长度
		SArt a;
		SScn s;
	}DATA;
*/
	CListEx<DATA*> m_list;
	CAdmin m_admin;
public:
	CStudent();
	~CStudent();
	static bool ByNumb(DATA* const&p1, DATA* const&p2){
		return p1->nNumb < p2->nNumb;
	}

	static bool ByName(DATA* const&p1, DATA* const&p2){
		return strcmp(p1->sName, p2->sName) < 0;
	}

	static bool ByType(DATA* const&p1, DATA* const&p2){
		return p1->nType > p2->nType;
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
	void FindByType();
	void PrintPS(POSITION *ps);
	DATA* InputData();
};

