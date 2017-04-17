#define _CRT_SECURE_NO_WARNINGS
#include "Admin.h"
#include<iostream>
#include"conio.h"
#include<algorithm>
using namespace std;

CAdmin::CAdmin()
{
}


CAdmin::~CAdmin()
{
}

bool CAdmin::Try()
{
	char sName[20], sPass[20];
	cout << "�������˺ź����룺[�Կո���]";
	cin >> sName >> sPass;
	_strlwr(sName);
	int i = 0;
	while (i < m_arr.GetSize()){
		DATA d = m_arr[i];
		//stricmp:�����ִ�Сд�ıȽ�
		if (!strcmp(d.sName, sName) && !strcmp(d.sPass, sPass)){
			m_data = d;
			return true;
		}
		++i;
	}
	return false;
}

bool CAdmin::Login()
{
	int nSize = m_arr.GetSize();
	if (!nSize){
		m_arr.Add({ "admin", "admin", 0 });
		nSize = m_arr.GetSize();
	}
	int i = 0;
	while (i < 3){
		if (Try())
			return true;
		cout << "�û���������������������룡" << endl;
		++i;
	}
	cout << "������½�����������Զ��˳���" << endl;
	return false;
}


void CAdmin::Load()
{
	FILE *pf = fopen("admin.lv", "r");
	DATA d;
	while (fread(&d, 1, sizeof(DATA), pf) == sizeof(d))
		m_arr.Add(d);	
	fclose(pf);
}


void CAdmin::Save()
{
	FILE *pf = fopen("admin.lv", "w");
	if (!pf){
		cout << "��������ʱ����" << endl;
		_getch;
		return;
	}
	int i = 0, nSize = m_arr.GetSize();
	while (i < nSize){
		fwrite(&m_arr[i], 1, sizeof(DATA), pf);
		++i;
	}
	fclose(pf);
}

void CAdmin::Start()
{
	if (m_data.nPrior == 0)
		while (Menu());
	else
		ChangePass();
}


int CAdmin::Menu()
{
	system("cls");
	puts("\n\t\t1������˻���");
	puts("\t\t2������˻���");
	puts("\t\t3��ɾ���˻���");
	puts("\t\t0���������˵���");
	int i = 0;
	cin >> i;
	switch (i){
	case 1:
		while(SortMenu());
		break;
	case 2:Input();
		break;
	case 3:while(Delete());
		break;
	}
	return i;
}


void CAdmin::ChangePass()
{
	cout << "����������룺";
	char sold[20];
	cin >> sold;
	while (strcmp(sold, m_data.sPass)){
		cout << "������������������룺����#���ء�";
		cin >> sold;
		if (sold[0] == '#')
			return;
	}
	char sPass[20], sConf[20];
	while (true){
		cout << "������������:";
		cin >> sPass;
		cout << "��ȷ������:";
		cin >> sConf;
		if (!strcmp(sPass, sConf)){
			Change(sPass);
			return;
		}
		cout << "�����������벻һ��" << endl;
	}
}

void CAdmin::Change(const char * sPass)
{
	int i = 0, nSize = m_arr.GetSize();
	while (i < nSize){
		if (!_stricmp(m_data.sName, m_arr[i].sName)){
			strcpy(m_arr[i].sPass, sPass);
			cout << "�����޸ĳɹ���"<<endl;
			system("pause");
			break;
		}
		++i;
	}
	Save();
	strcpy(m_data.sPass, sPass);
}


void CAdmin::Print()
{
	int i = 0, nSize = m_arr.GetSize();
	while (i < nSize){
		DATA d = m_arr[i];
		cout << d.sName << "\t" << d.sName << "\t" ;
		cout << (d.nPrior ? "��ͨ�û�" : "����Ա") << endl;
		++i;
	}
	system("pause");
}


void CAdmin::Input()
{
	DATA d;
	cout << "�������˻�����" << endl;
	cin >> d.sName;
	_strlwr(d.sName);
	while (Check(d.sName)>=0){
		cout << "�˻����Ѵ��ڣ����������룺����#���أ�";
		cin >> d.sName;
		if(d.sName[0] == '#')
			return;
		_strlwr(d.sName);
	}
	cout << "�����������Ȩ�ޣ�1������ͨ�û�|0�������Ա��";
	cin >> d.sPass >> d.nPrior;
	m_arr.Add(d);
	Save();
	Print();
}

int CAdmin::Check(const char * pName)
{
	int i = 0, nSize = m_arr.GetSize();
	while (i < nSize){
		if (!strcmp(m_arr[i].sName, pName))			
			return i;		
		++i;
	}
	return -1;
}


int CAdmin::Delete()
{
	cout << "\n������Ҫɾ�����˻�����";
	char sName[20];
	cin >> sName;
	int i = Check(sName);
	if (i >= 0){
		m_arr.RemoveAt(i);
		Save();
		cout << "ɾ���ɹ�" << endl;
		Print();
		return 0;
	}
	else{
		cout << "��������˻��������ڣ��Ƿ��������롾y/n]:";
		char c = _getch();
		putchar(c);
		return c == 'y' || c == 'Y';
	}	
}

int CAdmin::SortMenu()
{
	system("cls");
	cout << "1�����˻�������" << endl;
	cout << "2����Ȩ�޵ȼ�����" << endl;
	cout << "0���������˵�" << endl;
	int i;
	DATA *p = m_arr.GetData();
	cin >> i;
	switch (i){
	case 1:
		sort(p, p + m_arr.GetSize(), byName);
		Print();
		break;
	case 2:
		sort(p, p + m_arr.GetSize(), byPriority);
		Print();
		break;
	case 0:
		break;
	}
	return i;
}
