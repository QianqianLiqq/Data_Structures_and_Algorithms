#pragma once
#include"ListEx.h"
#include"Admin.h"

struct SUser{
	int nType;//类型 0代表文科，1代表理科
	int nNumb;
	char sName[20];
	char cSex[4];//男女
	virtual void Input();
	virtual void Print();
	virtual void Release(){
		delete this;
	}
	virtual void Write(FILE *pf){
		fwrite(&nType, 1, sizeof(SUser)-sizeof(void*), pf);
	}
	virtual void Read(FILE *pf){
		fread(&nNumb, 1, sizeof(SUser) - sizeof(nType) - sizeof(void*), pf);
	}
};

struct SArt :SUser{ //派生,默认public
	float fHist;//历史
	float fChin;//汉语
	float fEngl;//英语
	float fGeog;//地理
	void Input();
	void Print();
	void Release(){
		delete this;
	}
	void Write(FILE *pf){
		fwrite(&nType, 1, sizeof(SArt) - sizeof(void*), pf);
	}
	void Read(FILE *pf){
		fread(&nNumb, 1, sizeof(SArt) - sizeof(nType) - sizeof(void*), pf);
	}
};

struct SScn :SUser{
	float fmath;
	float fChem;
	float fPhys;
	void Input();
	void Print();
	void Release(){
		delete this;
	}
	void Write(FILE *pf){
		fwrite(&nType, 1, sizeof(SScn) - sizeof(void*), pf);
	}
	void Read(FILE *pf){
		fread(&nNumb, 1, sizeof(SScn) - sizeof(nType) - sizeof(void*), pf);
	}
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

