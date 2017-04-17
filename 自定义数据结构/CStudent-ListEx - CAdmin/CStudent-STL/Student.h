#pragma once
#include"ListEx.h"
#include"Admin.h"

struct SUser{
	int nType;//���� 0�����Ŀƣ�1�������
	int nNumb;
	char sName[20];
	char cSex[4];//��Ů
	void Input();
	void Print();
};

struct SArt :SUser{ //����,Ĭ��public
	float fHist;//��ʷ
	float fChin;//����
	float fEngl;//Ӣ��
	float fGeog;//����
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
/*	typedef union SData{ //�����������,�䳤��ȡ�������Ľṹ��ĳ���
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

