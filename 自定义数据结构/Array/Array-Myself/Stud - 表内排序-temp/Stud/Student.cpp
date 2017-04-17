#define  _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include<iostream>
#include<conio.h>
//#include<stdafx.h>
using namespace std;
typedef void(CStudent::*FIND_FUNC)();//成员函数的指针变量类型

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
	case 1:
		//Print(m_arr);
		//system("pause");
		while (SortMenu());
		break;
	case 2:while (Input());//循环添加
		break;
	case 3:while (Delete());//循环删除
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
	m_arr.Add(d);
	Save();
	Print(m_arr);
	cout << "是否继续添加[y/n]:";
	fflush(stdin);
	char c = getchar();
	return c=='y'||c=='Y';
}


bool CStudent::Delete()
{
	int nNumb;
	Print(m_arr);
	cout << "\n请输入要删除的学号：";
	cin >> nNumb;
	int i = 0;
	while (i<m_arr.GetSize()){
		if (m_arr[i++].nNumb == nNumb){
			m_arr.RemoveAt(i);
			Save();
			cout << "删除成功！" << endl;
			system("pause");
			Print(m_arr);
			return false;
		}
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
	Print(m_arr);
	cout << "\n请输入要修改的学号：";
	cin >> d.nNumb;
	int i = 0;
	while (i<m_arr.GetSize()){
		if (m_arr[i].nNumb == d.nNumb){
			cout << "请输入姓名和数学成绩（用空格间隔）：";
			cin >> d.sName >> d.fMath;
			m_arr.SetAt(i, d);
			Save();
			cout << "修改成功！" << endl;
			system("pause");
			Print(m_arr);
			return false;
		}
		++i;
	}
	cout << "你输入的学号不存在，是否重新输入？[y/n]:";
	char c = _getch();
	putchar(c);
	puts("");//换行
	return c == 'y' || c == 'Y';
}

int CStudent::FindMenu(){
	system("cls");//clear screen
	puts("\n\t\t1、按学号查找");
	puts("\t\t2、按姓名查找");
	puts("\t\t3、按分数段查找");
	puts("\t\t0、退出");
	cout << "\t\t请选择所要进行的操作：";
	//成员函数是否有指针变量，是否可以通过指针变量调用成员函数
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
	cout << "请输入要查找的学号：";
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
		cout << "没有找到符合的学号！";
	system("pause");
}

void CStudent::FindByName(){
	cout << "请输入要查找的姓名：";
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
		cout << "没有找到符合的姓名！";
	system("pause");
}

void CStudent::FindByMath(){
	cout << "请输入要查找的分数段：";
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
		cout << "没有找到符合的分数！";
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
	while (fread(&d, 1, sizeof(d), pf) == sizeof(d))//读不出或读到尾结束
		m_arr.Add(d);
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
	int i = 0, nSize = m_arr.GetSize();
	while (i<nSize){
		DATA d = m_arr[i++];
		fwrite(&d, 1, sizeof(d), pf);
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

int CStudent::Sort(By_FUNC pFunc)//选择排序
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


