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
}


void CStudent::Start()
{
	Load();
	while (Menu());
}


void CStudent::Load()
{
	FILE *pf = fopen("std.lv", "r");
	if (!pf)
		return;
	DATA d;
	while (fread(&d, 1, sizeof(d), pf) == sizeof(d))
		m_list.AddTail(d);
	fclose(pf);
}


int CStudent::Menu()
{
	system("cls");
	puts("\n\t\t1�����������Ϣ");
	puts("\t\t2�������Ϣ");
	puts("\t\t3��ɾ����Ϣ");
	puts("\t\t4���޸���Ϣ");
	puts("\t\t5��������Ϣ");
	puts("\t\t6����ɫ����");
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
	puts("\t\t3������ѧ�ɼ�����");
	puts("\t\t4��������ֱ�������");
	puts("\t\t0���������˵���");
	int i;
	cin >> i;
	CListEx<DATA>::SORT_FUNC ps[] = { ByNumb, ByName, ByMath };
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
		DATA d = m_list.GetAt(ps[i]);
		cout << d.nNumb << "\t" << d.sName << "\t" << d.fMath << endl;
		++i;
	}
	delete[]ps;
}

int CStudent::Check(int numb)
{
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		DATA &d = m_list.GetAt(pos);
		if (d.nNumb == numb)
			return true;
		m_list.GetNext(pos);
	}
	return false;
}

int CStudent::Input()
{
	cout << "\n";
	Print();
	cout << "\n������ѧ�ţ�";
	DATA d;
	while (true){
		cin >> d.nNumb;
		if (Check(d.nNumb))
			cout << "�������ѧ���Ѵ��ڣ�����������ѧ��:";
		else
			break;
	}
	cout << "��������������ѧ�ɼ����ÿո�������";
	cin >> d.sName >> d.fMath;
	m_list.AddTail(d);
	Save();
	Print();
	cout << "�Ƿ�������[y/n]:";
	char c = _getch();
	putchar(c);
	return c == 'y' || c == 'Y';
}


int CStudent::Delete()
{
	Print();
	//system("pause");
	_getch();
	cout << "\n������Ҫɾ����ѧ�ţ�";
	DATA d;
	cin >> d.nNumb;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		if (m_list.GetAt(pos).nNumb == d.nNumb){
			m_list.RemoveAt(pos);
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
	Print();
	system("pause");
	cout << "������Ҫ�޸ĵ�ѧ�ţ�";
	DATA d;
	cin >> d.nNumb;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		if (m_list.GetAt(pos).nNumb == d.nNumb){
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
	return c == 'y' || c == 'Y';
}


int CStudent::FindMenu()
{
	system("cls");
	puts("\n\t\t1����ѧ�Ų��ң�");
	puts("\t\t2�����������ң�");
	puts("\t\t3������ѧ�ɼ����ң�");
	puts("\t\t0���������˵���");
	int i;
	cin >> i;
	switch (i){
	case 1:while(FindByNumb());
		break;
	case 2:while (FindByName());
		break;
	case 3:FindByMath();
		break;
	case 0:
		break;
	}
	return i;
}

int CStudent::FindByNumb()
{
	DATA d;
	cout << "������ѧ�Ų��ң�";
	cin >> d.nNumb;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		if (m_list.GetAt(pos).nNumb == d.nNumb){
			cout << m_list.GetAt(pos).nNumb << "\t" << m_list.GetAt(pos).sName << "\t" << m_list.GetAt(pos).fMath << endl;
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
	DATA d;
	cout << "�������������ң�";
	cin >> d.sName;
	int count = 0;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		if (strcmp(m_list.GetAt(pos).sName, d.sName) == 0){//strchr:���ҵ����ַ�  strpbrk�����Ҷ���ַ�  strstr������һ���Ӵ�
			count++;
			cout << m_list.GetAt(pos).nNumb << "\t" << m_list.GetAt(pos).sName << "\t" << m_list.GetAt(pos).fMath << endl;
		}
		m_list.GetNext(pos);
	}
	system("pause");
	if (count != 0)
		return false;
	cout << "����������������ڣ��Ƿ���������[y/n]:";
	char c = _getch();
	putchar(c);
	puts("");
	return c == 'y' || c == 'Y';
}

void  CStudent::FindByMath(){
	cout << "��������Ҫ���ҵķ����Σ�2����������";
	float fMin, fMax;
	cin >> fMin >> fMax;
	if (fMin > fMax)
		swap(fMin, fMax);
	CListEx<DATA> cl;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		if (m_list.GetAt(pos).fMath >= fMin && m_list.GetAt(pos).fMath <= fMax)
			cl.AddTail(m_list.GetAt(pos));
		m_list.GetNext(pos);
	}
	if (cl.GetSize()){
		POSITION pos = cl.GetHeadPosition();
		while (pos){
			DATA &d=cl.GetAt(pos);
			cout << d.nNumb << "\t" << d.sName << "\t" << d.fMath << endl;
			cl.GetNext(pos);
		}
		cout << "����" << cl.GetSize() << "����¼��" << endl;
	}
	system("pause");
}

void CStudent::ColorSet()
{
}





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
		DATA d = m_list.GetAt(pos);
		fwrite(&d, 1, sizeof(d), pf);
		m_list.GetNext(pos);
	}
	fclose(pf);
}


void CStudent::Print()
{
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		DATA &d = m_list.GetAt(pos);
		cout << d.nNumb << "\t" << d.sName << "\t" << d.fMath << endl;
		m_list.GetNext(pos);
	}
	//system("pause");
}






