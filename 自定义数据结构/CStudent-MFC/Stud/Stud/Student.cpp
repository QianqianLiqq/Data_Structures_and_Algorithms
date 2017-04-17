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
	puts("\n\t\t1、浏览所有信息");
	puts("\t\t2、添加信息");
	puts("\t\t3、删除信息");
	puts("\t\t4、修改信息");
	puts("\t\t5、查找信息");
	puts("\t\t6、颜色设置");
	puts("\t\t0、退出");
	cout << "\t\t请选择所要进行的操作：";
	int i = 0;
	cin >> i;
	switch (i){
	case 1:while (SortMenu()){
		Print();
		system("pause");//阻塞---按任意键继续，使我们能看到显示的信息
	}
		break;
	case 2:while (Input());//循环添加
		break;
	case 3:while (Delete());//循环删除
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
	Load();//必须先写入链表
	while (Menu());
}


int CStudent::Input()
{
	cout << "请输入学号：";
	DATA d;
	while (true){
		cin >> d.nNumb;
		if (Check(d.nNumb))
			cout << "该学号已存在，请重新输入学号：";
		else 
			break;
	}
	cout << "请输入姓名和数学成绩（用空格间隔）：";
	cin >> d.sName >> d.fMath;
	m_list.AddTail(d);
	Save();
	Print();
	cout << "是否继续添加[y/n]:";
	fflush(stdin);
	char c = getchar();
	return c=='y'||c=='Y';
}


bool CStudent::Delete()
{
	int nNumb;
	Print();
	cout << "\n请输入要删除的学号：";
	cin >> nNumb;
	POSITION p = m_list.GetHeadPosition();
	while (p){
		if (m_list.GetAt(p).nNumb == nNumb){
			m_list.RemoveAt(p);
			Save();
			cout << "删除成功！" << endl;
			system("pause");
			Print();
			return false;
		}
		m_list.GetNext(p);
	}
	cout << "你输入的学号不存在，是否重新输入?[y/n]:";
	char c = _getch();
	putchar(c);
	puts("");//换行
	return c == 'y' || c == 'Y';
}


bool CStudent::Modify()
{
	DATA d;
	Print();
	cout << "\n请输入要修改的学号：";
	cin >> d.nNumb;
	POSITION p = m_list.GetHeadPosition();
	while (p){
		if (m_list.GetAt(p).nNumb == d.nNumb){
			cout << "请输入姓名和数学成绩（用空格间隔）：";
			cin >> d.sName >> d.fMath;
			m_list.SetAt(p, d);
			Save();
			cout << "修改成功！" << endl;
			system("pause");
			Print();
			return false;
		}
		m_list.GetNext(p);
	}
	cout << "你输入的学号不存在，是否重新输入？[y/n]:";
	char c = _getch();
	putchar(c);
	puts("");//换行
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
	while (fread(&d, 1, sizeof(d), pf) == sizeof(d))//读不出或读到尾结束
		m_list.AddTail(d);
	fclose(pf);	
}


void CStudent::Save()
{
	FILE *pf = fopen("stud.lv", "w");
	if (!pf){
		cout << "保存信息出错！";
		_getch;//回显
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


bool byNumb(DATA &q, DATA &m){//回调函数，没有this指针，只能用全局变量
	return  q.nNumb < m.nNumb;
}

bool byName(DATA &q, DATA &m){//回调函数，没有this指针，只能用全局变量
	return  strcmp(q.sName, m.sName ) < 0;;
}

bool byMath(DATA &q, DATA &m){//回调函数，没有this指针，只能用全局变量
	return  q.fMath > m.fMath;
}

int CStudent::Sort(By_FUNC pFunc)//选择排序
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
	puts("1、按学号排序：");
	puts("2、按姓名排序：");
	puts("3、按数学成绩排序：");
	puts("4、不排序直接浏览：");
	puts("0、返回主菜单：");
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
		//Print();//while(SortMenu())后面有打印
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
	puts("1、按学号查找：");
	puts("2、按姓名查找：");
	puts("3、按分数段查找：");
	puts("0、返回主菜单：");
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
	cout << "请输入要查找的学号：";
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
		cout << "你输入的学号不存在，是否重新输入[y/n]:";
		char c = _getch();
		putchar(c);
		puts("");//换行
		return c == 'y' || c == 'Y';
	}
	system("pause");
}


bool CStudent::FindByMath()
{
	int nCount = 0;
	float fMath;
	cout << "请输入要查找的分数段：";
	cin >> fMath;
	return false;
}
