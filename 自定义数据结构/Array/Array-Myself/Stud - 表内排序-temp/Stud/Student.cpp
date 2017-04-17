#define  _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include<iostream>
#include<conio.h>
//#include<stdafx.h>
using namespace std;
typedef void(CStudent::*FIND_FUNC)();//��Ա������ָ���������

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
	case 1:
		//Print(m_arr);
		//system("pause");
		while (SortMenu());
		break;
	case 2:while (Input());//ѭ�����
		break;
	case 3:while (Delete());//ѭ��ɾ��
		system("pause");
		break;
	case 4:while(Modify());
		system("pause");
		break;
	case 5:FindMenu();
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
	m_arr.Add(d);
	Save();
	Print(m_arr);
	cout << "�Ƿ�������[y/n]:";
	fflush(stdin);
	char c = getchar();
	return c=='y'||c=='Y';
}


bool CStudent::Delete()
{
	int nNumb;
	Print(m_arr);
	cout << "\n������Ҫɾ����ѧ�ţ�";
	cin >> nNumb;
	int i = 0;
	while (i<m_arr.GetSize()){
		if (m_arr[i++].nNumb == nNumb){
			m_arr.RemoveAt(i);
			Save();
			cout << "ɾ���ɹ���" << endl;
			system("pause");
			Print(m_arr);
			return false;
		}
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
	Print(m_arr);
	cout << "\n������Ҫ�޸ĵ�ѧ�ţ�";
	cin >> d.nNumb;
	int i = 0;
	while (i<m_arr.GetSize()){
		if (m_arr[i].nNumb == d.nNumb){
			cout << "��������������ѧ�ɼ����ÿո�������";
			cin >> d.sName >> d.fMath;
			m_arr.SetAt(i, d);
			Save();
			cout << "�޸ĳɹ���" << endl;
			system("pause");
			Print(m_arr);
			return false;
		}
		++i;
	}
	cout << "�������ѧ�Ų����ڣ��Ƿ��������룿[y/n]:";
	char c = _getch();
	putchar(c);
	puts("");//����
	return c == 'y' || c == 'Y';
}

int CStudent::FindMenu(){
	system("cls");//clear screen
	puts("\n\t\t1����ѧ�Ų���");
	puts("\t\t2������������");
	puts("\t\t3���������β���");
	puts("\t\t0���˳�");
	cout << "\t\t��ѡ����Ҫ���еĲ�����";
	//��Ա�����Ƿ���ָ��������Ƿ����ͨ��ָ��������ó�Ա����
	//FIND_FUNC p = &CStudent::FindByNumb;
	//(this->*p)();
	FIND_FUNC ps[] = { &CStudent::FindByNumb, &CStudent::FindByName, &CStudent::FindByMath };
	int i = 0;
	cin >> i;
/*	switch (i){
	case 1:
		FindByNumb();	    
		break;
	case 2:
		FindByName();
		break;
	case 3:
		FindByMath();
		break;
	case 0:
		return false;
	}
*/
	if (i > 0 && i < 4)
		(this->*ps[i - 1])();
	return i;
}



void CStudent::FindByNumb(){
	cout << "������Ҫ���ҵ�ѧ�ţ�";
	int nNumb;
	cin >> nNumb;
	int i = 0;
	CArray<DATA> cl;
	while (i < m_arr.GetSize()){
		if (m_arr[i].nNumb == nNumb){
			cl.Add(m_arr[i]);
			break;
		}			
		++i;
	}
	if (cl.GetSize())
		Print(cl);
	else
		cout << "û���ҵ����ϵ�ѧ�ţ�";
	system("pause");
}

void CStudent::FindByName(){
	cout << "������Ҫ���ҵ�������";
	DATA d;
	cin >> d.sName;
	int i = 0;
	CArray<DATA> cl;
	while (i < m_arr.GetSize()){
		if (strstr(m_arr[i].sName , d.sName)){
			cl.Add(m_arr[i]);
		}
		++i;
	}
	if (cl.GetSize())
		Print(cl);
	else
		cout << "û���ҵ����ϵ�������";
	system("pause");
}

void CStudent::FindByMath(){
	cout << "������Ҫ���ҵķ����Σ�";
	int fMin, fMax;
	cin >> fMin >> fMax;
	if (fMin>fMax)
		swap(fMin, fMax);
	int i = 0;
	CArray<DATA> cl;
	while (i < m_arr.GetSize()){
		if (m_arr[i].fMath >= fMin && m_arr[i].fMath<fMax){
			cl.Add(m_arr[i]);
		}
		++i;
	}
	if (cl.GetSize())
		Print(cl);
	else
		cout << "û���ҵ����ϵķ�����";
	system("pause");
}


void CStudent::ColorSet()
{
}


void CStudent::Welcome()
{
}


void CStudent::Print(CArray<DATA> &cl)
{
	//Sort();
	int i = 0;
	while (i<cl.GetSize()){
		DATA &d = cl[i++];
		cout << d.nNumb << "\t" << d.sName << "\t" << d.fMath << endl;
	}
}


bool CStudent::Check(int nNumb)
{
	int i=0;
	while (i<m_arr.GetSize()){
		if (m_arr[i++].nNumb == nNumb)
			return true;
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
		m_arr.Add(d);
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
	int i = 0, nSize = m_arr.GetSize();
	while (i<nSize){
		DATA d = m_arr[i++];
		fwrite(&d, 1, sizeof(d), pf);
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


/*void CStudent::PrintPS(CArray<DATA> *ps)
{
	int i = 0;
	while (i<m_arr.GetSize()){
		DATA d = m_list.GetAt(ps[i]);
		cout << d.nNumb << "\t" << d.sName << "\t" << d.fMath << endl;
		i++;
	}
}
*/

int CStudent::Sort(By_FUNC pFunc)//ѡ������
{
	int n = m_arr.GetSize();
	int i = 0, m , j ;
	while (i < n - 1){
		m = i;
		j = i + 1;
		while (j < n){
			//if (m_list.GetAt(ps[j]).nNumb < m_list.GetAt(ps[m]).nNumb)
			if (pFunc(m_arr[j], m_arr[m]))
				m = j;
			j++;
		}
		if (m !=  i){
			DATA t = m_arr[i];
			m_arr[i] = m_arr[m];
			m_arr[m] = t;
		}
		i++;
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
		Print(m_arr);
		system("pause");
		break;
	case 2:Sort(ps[i - 1]);
		Print(m_arr);
		system("pause");
		break;
	case 3:Sort(ps[i - 1]);
		Print(m_arr);
		system("pause");
		break;
	case 4:
		Print(m_arr);
		system("pause");
		break;
	case 0:
		break;
	}
	return i;
}


