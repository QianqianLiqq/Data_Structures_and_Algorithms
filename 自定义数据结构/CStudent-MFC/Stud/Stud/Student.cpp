#define  _CRT_SECURE_NO_WARNINGS
#include "Student.h"
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
	m_list.AddTail(d);
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
	POSITION p = m_list.GetHeadPosition();
	while (p){
		if (m_list.GetAt(p).nNumb == nNumb){
			m_list.RemoveAt(p);
			Save();
			cout << "ɾ���ɹ���" << endl;
			system("pause");
			Print();
			return false;
		}
		m_list.GetNext(p);
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
	POSITION p = m_list.GetHeadPosition();
	while (p){
		if (m_list.GetAt(p).nNumb == d.nNumb){
			cout << "��������������ѧ�ɼ����ÿո�������";
			cin >> d.sName >> d.fMath;
			m_list.SetAt(p, d);
			Save();
			cout << "�޸ĳɹ���" << endl;
			system("pause");
			Print();
			return false;
		}
		m_list.GetNext(p);
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
	POSITION p = m_list.GetHeadPosition();
	while (p){
		DATA d = m_list.GetAt(p);
		cout << d.nNumb << "\t" << d.sName << "\t" << d.fMath << endl;
		m_list.GetNext(p);
	}
}


bool CStudent::Check(int nNumb)
{
	POSITION p = m_list.GetHeadPosition();
	while (p){
		if (m_list.GetAt(p).nNumb == nNumb)
			return true;
		m_list.GetNext(p);
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
		m_list.AddTail(d);
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
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		DATA d = m_list.GetAt(pos);
		fwrite(&d, 1, sizeof(d), pf);
		m_list.GetNext(pos);
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
	POSITION p = m_list.GetHeadPosition(), m, q;
	while (p){
		m = q = p;
		m_list.GetNext(q);
		while (q){
			//if (m_list.GetAt(q).nNumb < m_list.GetAt(m).nNumb)
			if (pFunc(m_list.GetAt(q), m_list.GetAt(m)))
				m = q;
			m_list.GetNext(q);
		}
		if (m != p){
			DATA t = m_list.GetAt(p);
			m_list.SetAt(p, m_list.GetAt(m));
			m_list.SetAt(m, t);
		}
		m_list.GetNext(p);
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
	case 2:
	case 3:while (FindByMath());
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
	POSITION p = m_list.GetHeadPosition();
	while (p){
		DATA d = m_list.GetNext(p);
		if (d.nNumb == nNumb){
			cout << d.nNumb << "\t" << d.sName << "\t" << d.fMath << endl;
			++nCount;
			break;
			return false;
		}
	}
	if (nCount == 0){
		cout << "�������ѧ�Ų����ڣ��Ƿ���������[y/n]:";
		char c = _getch();
		putchar(c);
		puts("");//����
		return c == 'y' || c == 'Y';
	}
	system("pause");
}


bool CStudent::FindByMath()
{
	int nCount = 0;
	float fMath;
	cout << "������Ҫ���ҵķ����Σ�";
	cin >> fMath;
	return false;
}
