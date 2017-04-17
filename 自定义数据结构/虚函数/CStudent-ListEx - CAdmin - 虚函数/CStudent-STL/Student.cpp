#define  _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include<iostream>
#include<conio.h>
using namespace std;

CStudent::CStudent()
{
}


CStudent::~CStudent()
{
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		DATA * pData = m_list.GetNext(pos);
		pData->Release();
	}
}


void CStudent::Start()
{
	m_admin.Load();
	if (m_admin.Login()){
		Load();
		while (Menu());
	}
}

int CStudent::Menu()
{
	system("cls");
	cout << "\n\t\t�˻���" << m_admin.GetName() << "\t";
	cout << "Ȩ�ޣ�" << (m_admin.GetPriority() ? "��ͨ�û�" : "����Ա") << endl;
	puts("\n\t\t1�����������Ϣ");
	puts("\t\t2�������Ϣ");
	puts("\t\t3��ɾ����Ϣ");
	puts("\t\t4���޸���Ϣ");
	puts("\t\t5��������Ϣ");
	if (m_admin.GetPriority())
		puts("\t\t6���޸�����");
	else
		puts("\t\t6���˻�����");
	puts("\t\t0���˳�");
	int i;
	cin >> i;
	switch (i){
	case 1:	while(SortMenu());
		break;
	case 2:while(Input());
		break;
	case 3:while(Delete());
		break;
	case 4:while (Modify());
		break;
	case 5:while (FindMenu());
		break;
	case 6:m_admin.Start();
		break;
	case 0:
		break;
	}
	return i;
}


int CStudent::SortMenu()
{
	system("cls");
	puts("\n\t\t1����ѧ������");
	puts("\t\t2������������");
	puts("\t\t3������������");
	puts("\t\t4��������ֱ�������");
	puts("\t\t0���������˵���");
	int i;
	CListEx<DATA*>::SORT_FUNC ps[] = { ByNumb, ByName, ByType };
	cin >> i;
	switch (i){
	case 1:
	case 2:
	case 3:
		PrintPS(m_list.Sort2(ps[i - 1]));
		system("pause");
		break;
	case 4:Print();
		system("pause");
		break;
	case 0:
		break;
	}
	return i;
}


void CStudent::PrintPS(POSITION *ps){
	int i = 0;
	while (i < m_list.GetSize()){
		SUser* pData = m_list.GetAt(ps[i]);
		pData->Print();
		++i;
	}
	delete[]ps;
}

int CStudent::Check(int numb)
{
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		DATA *d = m_list.GetAt(pos);
		if (d->nNumb == numb)
			return true;
		m_list.GetNext(pos);
	}
	return false;
}

int CStudent::Input()
{ 
	DATA *pData = NULL;
	while (!(pData = InputData()));
	m_list.AddTail(pData);
	Save();
	Print();
	cout << "\n�Ƿ�������[y/n]:";
	char c = _getch();
	putchar(c);
	return c == 'y' || c == 'Y';
}

CStudent::DATA* CStudent::InputData(){
	cout << "\n��ѡ���Ŀƻ������[0�����Ŀƣ�1�������]:";
	int i;
	cin >> i;
	SUser *pData = NULL;
	if (i == 0)
		pData = new SArt;	
	if (i == 1)
		pData = new SScn;	
	if (pData)
		pData->Input();
	return pData;
}

int CStudent::Delete()
{
	Print();
	//_getch();
	cout << "\n������Ҫɾ����ѧ�ţ�";
	DATA d;
	cin >> d.nNumb;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		DATA* pData = m_list.GetAt(pos);
		if (pData->nNumb == d.nNumb){
			m_list.RemoveAt(pos);
			delete pData;
			cout << "ɾ���ɹ�" << endl;
			Save();
			Print();
			system("pause");
			return false;
		}
		m_list.GetNext(pos);
	}
	cout << "�������ѧ�Ų����ڣ��Ƿ���������[y/n]:";
	char c = _getch();
	putchar(c);
	puts("");
	return c == 'y' || c == 'Y';
}


int CStudent::Modify()
{
/*	Print();
	system("pause");
	cout << "������Ҫ�޸ĵ�ѧ�ţ�";
	DATA d;
	cin >> d.nNumb;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		if (m_list.GetAt(pos)->nNumb == d.nNumb){
			cout << "\n��������������ѧ�ɼ����ÿո�������";
			cin >> d.sName >> d.fMath;
			strcpy(m_list.GetAt(pos).sName, d.sName);
			m_list.GetAt(pos).fMath = d.fMath;
			cout << "�޸ĳɹ���" << endl;
			Save();
			Print();
			system("pause");
			return false;
		}
		m_list.GetNext(pos);
	}
	cout << "�������ѧ�Ų����ڣ��Ƿ���������[y/n]:";
	char c = _getch();
	putchar(c);
	puts("");
	return c == 'y' || c == 'Y';*/
	return true;
}


int CStudent::FindMenu()
{
	system("cls");
	puts("\n\t\t1����ѧ�Ų��ң�");
	puts("\t\t2�����������ң�");
	puts("\t\t3�������Ͳ��ң�");
	puts("\t\t0���������˵���");
	int i;
	cin >> i;
	switch (i){
	case 1:while(FindByNumb());
		break;
	case 2:while (FindByName());
		break;
	case 3:FindByType();
		break;
	case 0:
		break;
	}
	return i;
}

int CStudent::FindByNumb()
{
	int nNumb;
	cout << "������ѧ�Ų��ң�";
	cin >> nNumb;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		SUser* pData = m_list.GetAt(pos);
		if (pData->nNumb == nNumb){
			pData->Print();
			system("pause");
			return false;
		}
		m_list.GetNext(pos);
	}
	cout << "�������ѧ�Ų����ڣ��Ƿ���������[y/n]:";
	char c = _getch();
	putchar(c);
	puts("");
	return c == 'y' || c == 'Y';
}

int CStudent::FindByName()
{
	char sName[20];
	cout << "�������������ң�";
	cin >> sName;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		SUser* pData = m_list.GetAt(pos);
		if (!strcmp(pData->sName , sName)){
			pData->Print();
			system("pause");
			return false;
		}
		m_list.GetNext(pos);
	}
	cout << "����������������ڣ��Ƿ���������[y/n]:";
	char c = _getch();
	putchar(c);
	puts("");
	return c == 'y' || c == 'Y';
}

void  CStudent::FindByType(){
	int i = 0;
	do{
		cout << "��������Ҫ���ҵ����ͣ�0�����Ŀƣ�1������ƣ���";
		cin >> i;
	} while (i != 0 && i != 1);
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		SUser* pData = m_list.GetAt(pos);
		if (pData->nType == i&&i==1){
			pData->Print();
		}
		if (pData->nType == i&&i==0){
			pData->Print();
		}
		m_list.GetNext(pos);
	}
	system("pause");
}

void CStudent::ColorSet()
{
}
/*
void CStudent::Load()
{
	FILE *pf = fopen("std.lv", "r");
	if (!pf)
		return;
	int nType = -1;
	DATA* pData = NULL;
	while (fread(&nType, 1, sizeof(nType), pf) == sizeof(nType)){
		if (nType == 1){
			SScn* p = new SScn;
			p->nType = 1;
			fread(&p->nNumb, 1, sizeof(SScn) - sizeof(nType) - sizeof(void*), pf);//���ļ��е�˳���ȡ����һ��������ʾ��ȡ֮��ŵ�����
			pData = p;
		}
		if (nType == 0){
			SArt* p = new SArt;
			p->nType = 0;
			fread(&p->nNumb, 1, sizeof(SArt) - sizeof(nType) - sizeof(void*), pf);
			pData = p;
		}
		if (pData)
			m_list.AddTail(pData);
	}
	fclose(pf);
}
*/
void CStudent::Load()
{
	FILE *pf = fopen("std.lv", "r");
	if (!pf)
		return;
	int nType = -1;
	DATA* pData = NULL;
	while (fread(&nType, 1, sizeof(nType), pf) == sizeof(nType)){
		if (nType == 1){
			pData = new SScn;
			pData->nType = 1;
		}
		if (nType == 0){
			pData = new SArt;
			pData->nType = 0;
		}
		if (pData){
			pData->Read(pf);
			m_list.AddTail(pData);
		}
	}
	fclose(pf);
}
/*
void CStudent::Save()
{
	FILE *pf = fopen("std.lv", "w");
	if (!pf){
		cout << "��������ʱ����" << endl;
		_getch;
		return;
	}
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		DATA* pData = m_list.GetNext(pos);
		if (pData->nType == 1)
			fwrite(&pData->nType, 1, sizeof(SScn)-sizeof(void*), pf);	//��һ��������ʾ���ĸ���ַ������д���ļ� //ͷ�����һ���麯��ָ��
		if(pData->nType == 0)
			fwrite(&pData->nType, 1, sizeof(SArt) - sizeof(void*), pf);
	}
	fclose(pf);
}
*/
void CStudent::Save()
{
	FILE *pf = fopen("std.lv", "w");
	if (!pf){
		cout << "��������ʱ����" << endl;
		_getch;
		return;
	}
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		DATA* pData = m_list.GetNext(pos);
		pData->Write(pf);
	}
	fclose(pf);
}

void CStudent::Print()
{
	int a = 0, s = 0;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		DATA *pData = m_list.GetNext(pos);
		pData->Print();						
	}
}

void SScn::Input(){
	nType = 1;
	SUser::Input();
	cout << "��������Ƴɼ�����ѧ��������ѧ��:";
	cin >> this->fmath >>fPhys>> fChem;
}

void SScn::Print(){
	SUser::Print();
	cout << "��Ƴɼ�����ѧ��������ѧ����" << endl;
	cout << fmath << "\t" << fPhys << "\t" << fChem << endl;
	cout << endl;
}

void SArt::Input(){
	nType = 0;
	SUser::Input();
	cout << "�������ĿƳɼ������ġ�Ӣ���ʷ��������";
	cin >> this->fChin >> fEngl >> fHist >> fGeog;
}

void SArt::Print(){
	SUser::Print();
	cout << "�ĿƳɼ������ġ�Ӣ���ʷ��������" << endl;
	cout << fChin << "\t" << fEngl << "\t" << fHist << "\t" << fGeog << endl;
	cout << endl;
}

void SUser::Input(){
	cout << "������ѧ�š��������Ա���/Ů��:";
	cin >> this->nNumb >> sName >> cSex;
}

void SUser::Print(){
	cout << "������Ϣ��ѧ�š��������Ա𣩣�"<<endl;
	cout << nNumb << "\t" << sName << "\t" << cSex << endl;
}