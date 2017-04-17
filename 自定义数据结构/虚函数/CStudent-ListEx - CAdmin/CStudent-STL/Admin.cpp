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
	cout << "请输入账号和密码：[以空格间隔]";
	cin >> sName >> sPass;
	_strlwr(sName);
	int i = 0;
	while (i < m_arr.GetSize()){
		DATA d = m_arr[i];
		//stricmp:不区分大小写的比较
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
		cout << "用户名或密码错误，请重新输入！" << endl;
		++i;
	}
	cout << "超过登陆次数，程序自动退出！" << endl;
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
		cout << "保存数组时出错！" << endl;
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
	puts("\n\t\t1、浏览账户：");
	puts("\t\t2、添加账户：");
	puts("\t\t3、删除账户：");
	puts("\t\t0、返回主菜单：");
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
	cout << "请输入旧密码：";
	char sold[20];
	cin >> sold;
	while (strcmp(sold, m_data.sPass)){
		cout << "旧密码错误，请重新输入：【按#返回】";
		cin >> sold;
		if (sold[0] == '#')
			return;
	}
	char sPass[20], sConf[20];
	while (true){
		cout << "请输入新密码:";
		cin >> sPass;
		cout << "请确认密码:";
		cin >> sConf;
		if (!strcmp(sPass, sConf)){
			Change(sPass);
			return;
		}
		cout << "两次输入密码不一致" << endl;
	}
}

void CAdmin::Change(const char * sPass)
{
	int i = 0, nSize = m_arr.GetSize();
	while (i < nSize){
		if (!_stricmp(m_data.sName, m_arr[i].sName)){
			strcpy(m_arr[i].sPass, sPass);
			cout << "密码修改成功！"<<endl;
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
		cout << (d.nPrior ? "普通用户" : "管理员") << endl;
		++i;
	}
	system("pause");
}


void CAdmin::Input()
{
	DATA d;
	cout << "请输入账户名：" << endl;
	cin >> d.sName;
	_strlwr(d.sName);
	while (Check(d.sName)>=0){
		cout << "账户名已存在，请重新输入：（按#返回）";
		cin >> d.sName;
		if(d.sName[0] == '#')
			return;
		_strlwr(d.sName);
	}
	cout << "请输入密码和权限（1代表普通用户|0代表管理员）";
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
	cout << "\n请输入要删除的账户名：";
	char sName[20];
	cin >> sName;
	int i = Check(sName);
	if (i >= 0){
		m_arr.RemoveAt(i);
		Save();
		cout << "删除成功" << endl;
		Print();
		return 0;
	}
	else{
		cout << "你输入的账户名不存在，是否重新输入【y/n]:";
		char c = _getch();
		putchar(c);
		return c == 'y' || c == 'Y';
	}	
}

int CAdmin::SortMenu()
{
	system("cls");
	cout << "1、按账户名排序" << endl;
	cout << "2、按权限等级排序" << endl;
	cout << "0、返回主菜单" << endl;
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
