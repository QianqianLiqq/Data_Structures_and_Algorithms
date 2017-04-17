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
	case 1:while (SortMenu());
		break;
	case 2:while (Input());//循环添加
		break;
	case 3:while (Delete());//循环删除
		system("pause");
		break;
	case 4:while(Modify());
		system("pause");
		break;
	case 5:while (true);
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


void CStudent::PrintPS(POSITION *ps)
{
	int i = 0;
	while (ps[i]){
		DATA d = m_list.GetAt(ps[i]);
		cout << d.nNumb << "\t" << d.sName << "\t" << d.fMath << endl;
		i++;
	}
}


int CStudent::Sort(By_FUNC pFunc)//选择排序
{
	int n = m_list.GetCount();
	POSITION *ps = new POSITION[n+1];
	POSITION p = m_list.GetHeadPosition();
	int i = 0, m = 0, j = 0;
	while (ps[i++] = p)
		m_list.GetNext(p);
	i = 0;
	while (i < n - 1){
		m = i;
		j = i + 1;
		while (j < n){
			//if (m_list.GetAt(ps[j]).nNumb < m_list.GetAt(ps[m]).nNumb)
			if (pFunc(m_list.GetAt(ps[j]), m_list.GetAt(ps[m])))
				m = j;
			j++;
		}
		if (m !=  i){
			POSITION t = ps[i];
			ps[i] = ps[m];
			ps[m] = t;
		}
		i++;
	}
	PrintPS(ps);
	system("pause");
	delete[]ps;//不删除堆空间就是内存泄漏
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
	case 4:Print();
		system("pause");
		break;
	case 0:
		break;
	}
	return i;
}



