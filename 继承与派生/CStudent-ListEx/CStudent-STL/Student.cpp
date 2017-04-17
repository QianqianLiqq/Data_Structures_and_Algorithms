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
	puts("\n\t\t1、浏览所有信息");
	puts("\t\t2、添加信息");
	puts("\t\t3、删除信息");
	puts("\t\t4、修改信息");
	puts("\t\t5、查找信息");
	puts("\t\t6、颜色设置");
	puts("\t\t0、退出");
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
	puts("\n\t\t1、按学号排序：");
	puts("\t\t2、按姓名排序：");
	puts("\t\t3、按数学成绩排序：");
	puts("\t\t4、不排序直接浏览：");
	puts("\t\t0、返回主菜单：");
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
	cout << "\n请输入学号：";
	DATA d;
	while (true){
		cin >> d.nNumb;
		if (Check(d.nNumb))
			cout << "你输入的学号已存在，请重新输入学号:";
		else
			break;
	}
	cout << "请输入姓名和数学成绩（用空格间隔）：";
	cin >> d.sName >> d.fMath;
	m_list.AddTail(d);
	Save();
	Print();
	cout << "是否继续添加[y/n]:";
	char c = _getch();
	putchar(c);
	return c == 'y' || c == 'Y';
}


int CStudent::Delete()
{
	Print();
	//system("pause");
	_getch();
	cout << "\n请输入要删除的学号：";
	DATA d;
	cin >> d.nNumb;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		if (m_list.GetAt(pos).nNumb == d.nNumb){
			m_list.RemoveAt(pos);
			cout << "删除成功" << endl;
			Save();
			Print();
			system("pause");
			return false;
		}
		m_list.GetNext(pos);
	}
	cout << "你输入的学号不存在，是否重新输入[y/n]:";
	char c = _getch();
	putchar(c);
	puts("");
	return c == 'y' || c == 'Y';
}


int CStudent::Modify()
{
	Print();
	system("pause");
	cout << "请输入要修改的学号：";
	DATA d;
	cin >> d.nNumb;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		if (m_list.GetAt(pos).nNumb == d.nNumb){
			cout << "\n请输入姓名和数学成绩（用空格间隔）：";
			cin >> d.sName >> d.fMath;
			strcpy(m_list.GetAt(pos).sName, d.sName);
			m_list.GetAt(pos).fMath = d.fMath;
			cout << "修改成功！" << endl;
			Save();
			Print();
			system("pause");
			return false;
		}
		m_list.GetNext(pos);
	}
	cout << "你输入的学号不存在，是否重新输入[y/n]:";
	char c = _getch();
	putchar(c);
	puts("");
	return c == 'y' || c == 'Y';
}


int CStudent::FindMenu()
{
	system("cls");
	puts("\n\t\t1、按学号查找：");
	puts("\t\t2、按姓名查找：");
	puts("\t\t3、按数学成绩查找：");
	puts("\t\t0、返回主菜单：");
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
	cout << "请输入学号查找：";
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
	cout << "你输入的学号不存在，是否重新输入[y/n]:";
	char c = _getch();
	putchar(c);
	puts("");
	return c == 'y' || c == 'Y';
}

int CStudent::FindByName()
{
	DATA d;
	cout << "请输入姓名查找：";
	cin >> d.sName;
	int count = 0;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		if (strcmp(m_list.GetAt(pos).sName, d.sName) == 0){//strchr:查找单个字符  strpbrk：查找多个字符  strstr：查找一个子串
			count++;
			cout << m_list.GetAt(pos).nNumb << "\t" << m_list.GetAt(pos).sName << "\t" << m_list.GetAt(pos).fMath << endl;
		}
		m_list.GetNext(pos);
	}
	system("pause");
	if (count != 0)
		return false;
	cout << "你输入的姓名不存在，是否重新输入[y/n]:";
	char c = _getch();
	putchar(c);
	puts("");
	return c == 'y' || c == 'Y';
}

void  CStudent::FindByMath(){
	cout << "请输入你要查找的分数段（2个分数）：";
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
		cout << "共有" << cl.GetSize() << "条记录！" << endl;
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
		cout << "保存链表时出错！" << endl;
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






