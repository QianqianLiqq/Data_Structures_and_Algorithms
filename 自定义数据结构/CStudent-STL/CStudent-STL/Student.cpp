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
		m_list.push_back(d);
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
	BY_FUNC ps[] = { ByNumb, ByName, ByMath };
	switch (i){
	case 1:
		//m_list.sort(ps[i - 1]);
		//Print();
		Sort(ps[i - 1]);
		system("pause");
		break;
	case 2:
		//m_list.sort(ps[i - 1]);
		//Print();
		Sort(ps[i - 1]);
		system("pause");
		break;
	case 3:
		//m_list.sort(ps[i - 1]);
		//Print();
		Sort(ps[i - 1]);
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

int CStudent::Check(int numb)
{
	list<DATA>::iterator it = m_list.begin();
	while (it != m_list.end()){
		if (it->nNumb == numb)
			return true;
		++it;
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
	m_list.push_back(d);
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
	list<DATA>::iterator it = m_list.begin();
	while (it != m_list.end()){
		if (it->nNumb == d.nNumb){
			m_list.erase(it);
			cout << "ɾ���ɹ�" << endl;
			Save();
			Print();
			system("pause");
			return false;
		}
		++it;
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
	list<DATA>::iterator it = m_list.begin();
	while (it != m_list.end()){
		if (it->nNumb == d.nNumb){
			cout << "\n��������������ѧ�ɼ����ÿո�������";
			cin >> d.sName >> d.fMath;
			strcpy(it->sName, d.sName);
			it->fMath = d.fMath;
			cout << "�޸ĳɹ���" << endl;
			Save();
			Print();
			system("pause");
			return false;
		}
		++it;
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
	list<DATA>::iterator it = m_list.begin();
	while (it != m_list.end()){
		if (it->nNumb == d.nNumb){
			cout << it->nNumb << "\t" << it->sName << "\t" << it->fMath << endl;
			system("pause");
			return false;
		}
		++it;
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
	list<DATA>::iterator it = m_list.begin();
	while (it != m_list.end()){
		if (strcmp(it->sName,d.sName)==0){//strchr:���ҵ����ַ�  strpbrk�����Ҷ���ַ�  strstr������һ���Ӵ�
			count++;
			cout << it->nNumb << "\t" << it->sName << "\t" << it->fMath << endl;
		}
		++it;
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
	list<DATA> cl;
	list<DATA>::iterator it = m_list.begin();
	while (it != m_list.end()){
		if (it->fMath >= fMin && it->fMath <= fMax)
			cl.push_back(*it);
		++it;
	}
	if (cl.size()){
		list<DATA>::iterator it = cl.begin();
		while (it != cl.end()){
			cout << it->nNumb << "\t" << it->sName << "\t" << it->fMath << endl;
			++it;
		}
		cout << "����" << cl.size() << "����¼��" << endl;
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
	list<DATA>::iterator it = m_list.begin();
	while (it != m_list.end()){
		DATA d = *it;
		fwrite(&d, 1, sizeof(d), pf);
		++it;
	}
	fclose(pf);
}


void CStudent::Print()
{
	list<DATA>::iterator it = m_list.begin();
	while (it != m_list.end()){
		cout << it->nNumb << "\t" << it->sName << "\t" << it->fMath << endl;
		it++;
	}
	//system("pause");
}





void CStudent::Sort(BY_FUNC pFunc)
{
	int n = m_list.size(), i = 0;
	list<DATA>::iterator *ps = new list<DATA>::iterator[n+1];
	list<DATA>::iterator it = m_list.begin();
	while ((ps[i] = it) != m_list.end())
		++i, ++it;
	i = 0;
	while (i < n){
		int j = i+1;
		int m = i ;
		while (j < n){
			if (pFunc(*ps[m], *ps[j])) //*ps[m]��*ps[j]��DATA����
				m = j;
			++j;
		}
		if (i != m){
			list<DATA>::iterator t = ps[i];
			ps[i] = ps[m];
			ps[m] = t;
		}
		++i;
	}	
	PrintPS(ps, n);
	delete []ps;
}


void CStudent::PrintPS(std::list<DATA>::iterator* ps, int n)
{
	int i = 0;
	while (i<n){
		cout << ps[i]->nNumb << "\t" << ps[i]->sName << "\t" << ps[i]->fMath << endl;
		i++;
	}
	//system("pause");
}
