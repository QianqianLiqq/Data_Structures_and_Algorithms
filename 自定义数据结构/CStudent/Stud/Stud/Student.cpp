#define  _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include"List.h"
#include<iostream>
#include<conio.h>
//#include<stdafx.h>
using namespace std;


CStudent::CStudent()
{	
}


CStudent::~CStudent()
{
}


int CStudent::Menu()
{
	system("cls");//clear screen
	puts("\n\t\t1�����������Ϣ");
	puts("\t\t2�������Ϣ");
	puts("\t\t3��ɾ����Ϣ");
	puts("\t\t4���޸���Ϣ");
	puts("\t\t5��������Ϣ");
	puts("\t\t6����ɫ����");
	puts("\t\t0���˳�");
	cout << "\t\t��ѡ����Ҫ���еĲ�����";
	int i = 0;
	cin >> i;
	switch (i){
	case 1:while (SortMenu()){
		Print();
		system("pause");//����---�������������ʹ�����ܿ�����ʾ����Ϣ
	}
		break;
	case 2:while (Input());//ѭ�����
		break;
	case 3:while (Delete());//ѭ��ɾ��
		system("pause");
		break;
	case 4:while(Modify());
		system("pause");
		break;
	case 5:while(FindMenu());
		break;
	case 6:ColorSet();
		break;
	case 0:
		return false;
	}
	return true;
}


void CStudent::Start()
{
	Welcome();
	Load();//������д������
	while (Menu());
}


int CStudent::Input()
{
	cout << "������ѧ�ţ�";
	DATA d;
	while (true){
		cin >> d.nNumb;
		if (Check(d.nNumb))
			cout << "��ѧ���Ѵ��ڣ�����������ѧ�ţ�";
		else 
			break;
	}
	cout << "��������������ѧ�ɼ����ÿո�������";
	cin >> d.sName >> d.fMath;
	m_list.push_front(d);
	Save();
	Print();
	cout << "�Ƿ�������[y/n]:";
	fflush(stdin);
	char c = getchar();
	return c=='y'||c=='Y';
}


bool CStudent::Delete()
{
	int nNumb;
	Print();
	cout << "\n������Ҫɾ����ѧ�ţ�";
	cin >> nNumb;
	CList::iterator it = m_list.begin();
	while (it!=m_list.end()){
		if (it->nNumb == nNumb){
			m_list.erase(it);
			Save();
			cout << "ɾ���ɹ���" << endl;
			Print();
			system("pause");
			return false;
		}
		++it;
	}
	cout << "�������ѧ�Ų����ڣ��Ƿ���������?[y/n]:";
	char c = _getch();
	putchar(c);
	puts("");//����
	return c == 'y' || c == 'Y';
}


bool CStudent::Modify()
{
	DATA d;
	Print();
	cout << "\n������Ҫ�޸ĵ�ѧ�ţ�";
	cin >> d.nNumb;
	CList::iterator it = m_list.begin();
	while (it != m_list.end()){
		if (it->nNumb == d.nNumb){
			cout << "��������������ѧ�ɼ����ÿո�������";
			cin >> d.sName >> d.fMath;
			*it = d;
			Save();
			cout << "�޸ĳɹ���" << endl;
			system("pause");
			Print();
			return false;
		}
		++it;
	}
	cout << "�������ѧ�Ų����ڣ��Ƿ��������룿[y/n]:";
	char c = _getch();
	putchar(c);
	puts("");//����
	return c == 'y' || c == 'Y';
}


void CStudent::ColorSet()
{
}


void CStudent::Welcome()
{
}


void CStudent::Print()
{
	//Sort();
	CList::iterator it = m_list.begin();
	while (it != m_list.end()){
		//DATA d = m_list.GetAt(p);
		cout << it->nNumb << "\t" << it->sName << "\t" << it->fMath << endl;
		++it;
	}
}


bool CStudent::Check(int nNumb)
{
	CList::iterator it = m_list.begin();
	while (it!=m_list.end()){
		if (it->nNumb == nNumb)
			return true;
		++it;
	}
	return false;
}


void CStudent::Load()
{
	FILE *pf = fopen("stud.lv", "r");
	if (!pf)
		return;
	DATA d;
	while (fread(&d, 1, sizeof(d), pf) == sizeof(d))//�����������β����
		m_list.push_back(d);
	fclose(pf);	
}


void CStudent::Save()
{
	FILE *pf = fopen("stud.lv", "w");
	if (!pf){
		cout << "������Ϣ����";
		_getch;//����
		return;
	}
	CList::iterator it = m_list.begin();
	while (it!=m_list.end()){
		DATA d = *it;
		fwrite(&d, 1, sizeof(d), pf);
		++it;
	}
	fclose(pf);
}


bool byNumb(DATA &q, DATA &m){//�ص�������û��thisָ�룬ֻ����ȫ�ֱ���
	return  q.nNumb < m.nNumb;
}

bool byName(DATA &q, DATA &m){//�ص�������û��thisָ�룬ֻ����ȫ�ֱ���
	return  strcmp(q.sName, m.sName ) < 0;;
}

bool byMath(DATA &q, DATA &m){//�ص�������û��thisָ�룬ֻ����ȫ�ֱ���
	return  q.fMath > m.fMath;
}

int CStudent::Sort(By_FUNC pFunc)//ѡ������
{
	CList::iterator it = m_list.begin(), m, q;
	while (it!=m_list.end()){
		m = q = it;
		++q;
		while (q!=m_list.end()){
			//if (m_list.GetAt(q).nNumb < m_list.GetAt(m).nNumb)
			if (pFunc(*q, *m))
				m = q;
			++q;
		}
		if (m != it){
			DATA t = *it;
			*it = *m;
			*m = t;
		}
		++it;
	}
	return 0;
}


int CStudent::SortMenu()
{
	system("cls");
	puts("1����ѧ������");
	puts("2������������");
	puts("3������ѧ�ɼ�����");
	puts("4��������ֱ�������");
	puts("0���������˵���");
	int i;
	cin >> i;
	By_FUNC ps[] = { byNumb, byName, byMath };
	switch (i){
	case 1:Sort(ps[i - 1]);
		break;
	case 2:Sort(ps[i - 1]);
		break;
	case 3:Sort(ps[i - 1]);
		break;
	case 4:
		//Print();//while(SortMenu())�����д�ӡ
		//system("pause");
		break;
	case 0:
		break;
	}
	return i;
}


int CStudent::FindMenu()
{
	system("cls");
	puts("1����ѧ�Ų��ң�");
	puts("2�����������ң�");
	puts("3���������β��ң�");
	puts("0���������˵���");
	int i = 0;
	cin >> i;
	switch (i){
	case 1:while(FindByNumb());
		break;
	case 2:FindByName();
		break;
	case 3:FindByMath();
		break;
	case 0:
		;
	}
	return i;
}


bool CStudent::FindByNumb()
{ 
	int nNumb, nCount=0;
	cout << "������Ҫ���ҵ�ѧ�ţ�";
	cin >> nNumb;
	CList::iterator it = m_list.begin();
	while (it!=m_list.end()){
		if (it->nNumb == nNumb){
			cout << it->nNumb << "\t" << it->sName << "\t" << it->fMath << endl;
			++nCount;
			system("pause");
			return false;
		}
		++it;
	}
	//system("pause");
	if (nCount == 0){
		cout << "�������ѧ�Ų����ڣ��Ƿ���������[y/n]:";
		char c = _getch();
		putchar(c);
		puts("");//����
		return c == 'y' || c == 'Y';
	}
	//cout << "���ҵ�" << nCount << "����¼��" << endl;
	system("pause");
}


void CStudent::FindByMath()
{
	int nCount = 0;
	float fMin,fMax;
	cout << "������Ҫ���ҵķ����Σ�������������";
	cin >> fMin>>fMax;
	if (fMin > fMax)
		swap(fMin, fMax);
	CList::iterator it = m_list.begin();
	while (it != m_list.end()){
		if (it->fMath >= fMin&&it->fMath < fMax){
			cout << it->nNumb << "\t" << it->sName << "\t" << it->fMath << endl;
			++nCount;
		}
		++it;
	}
	cout << "���ҵ�" << nCount << "����¼��" << endl;
	system("pause");
}

void CStudent::FindByName()
{
	int nCount = 0;
	DATA d;
	cout << "������Ҫ���ҵ�������";
	cin >> d.sName;
	CList::iterator it = m_list.begin();
	while (it != m_list.end()){
		if (strcmp(it->sName,d.sName)==0){
			cout << it->nNumb << "\t" << it->sName << "\t" << it->fMath << endl;
			++nCount;
		}
		++it;
	}
	cout << "���ҵ�" << nCount << "����¼��" << endl;
	system("pause");
}
