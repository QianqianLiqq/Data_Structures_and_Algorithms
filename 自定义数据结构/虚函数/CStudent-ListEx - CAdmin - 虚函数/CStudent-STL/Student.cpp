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
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		DATA * pData = m_list.GetNext(pos);
		pData->Release();
	}
}


void CStudent::Start()
{
	m_admin.Load();
	if (m_admin.Login()){
		Load();
		while (Menu());
	}
}

int CStudent::Menu()
{
	system("cls");
	cout << "\n\t\t账户：" << m_admin.GetName() << "\t";
	cout << "权限：" << (m_admin.GetPriority() ? "普通用户" : "管理员") << endl;
	puts("\n\t\t1、浏览所有信息");
	puts("\t\t2、添加信息");
	puts("\t\t3、删除信息");
	puts("\t\t4、修改信息");
	puts("\t\t5、查找信息");
	if (m_admin.GetPriority())
		puts("\t\t6、修改密码");
	else
		puts("\t\t6、账户管理");
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
	case 6:m_admin.Start();
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
	puts("\t\t3、按类型排序：");
	puts("\t\t4、不排序直接浏览：");
	puts("\t\t0、返回主菜单：");
	int i;
	CListEx<DATA*>::SORT_FUNC ps[] = { ByNumb, ByName, ByType };
	cin >> i;
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
		SUser* pData = m_list.GetAt(ps[i]);
		pData->Print();
		++i;
	}
	delete[]ps;
}

int CStudent::Check(int numb)
{
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		DATA *d = m_list.GetAt(pos);
		if (d->nNumb == numb)
			return true;
		m_list.GetNext(pos);
	}
	return false;
}

int CStudent::Input()
{ 
	DATA *pData = NULL;
	while (!(pData = InputData()));
	m_list.AddTail(pData);
	Save();
	Print();
	cout << "\n是否继续添加[y/n]:";
	char c = _getch();
	putchar(c);
	return c == 'y' || c == 'Y';
}

CStudent::DATA* CStudent::InputData(){
	cout << "\n请选择文科还是理科[0代表文科，1代表理科]:";
	int i;
	cin >> i;
	SUser *pData = NULL;
	if (i == 0)
		pData = new SArt;	
	if (i == 1)
		pData = new SScn;	
	if (pData)
		pData->Input();
	return pData;
}

int CStudent::Delete()
{
	Print();
	//_getch();
	cout << "\n请输入要删除的学号：";
	DATA d;
	cin >> d.nNumb;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		DATA* pData = m_list.GetAt(pos);
		if (pData->nNumb == d.nNumb){
			m_list.RemoveAt(pos);
			delete pData;
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
/*	Print();
	system("pause");
	cout << "请输入要修改的学号：";
	DATA d;
	cin >> d.nNumb;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		if (m_list.GetAt(pos)->nNumb == d.nNumb){
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
	return c == 'y' || c == 'Y';*/
	return true;
}


int CStudent::FindMenu()
{
	system("cls");
	puts("\n\t\t1、按学号查找：");
	puts("\t\t2、按姓名查找：");
	puts("\t\t3、按类型查找：");
	puts("\t\t0、返回主菜单：");
	int i;
	cin >> i;
	switch (i){
	case 1:while(FindByNumb());
		break;
	case 2:while (FindByName());
		break;
	case 3:FindByType();
		break;
	case 0:
		break;
	}
	return i;
}

int CStudent::FindByNumb()
{
	int nNumb;
	cout << "请输入学号查找：";
	cin >> nNumb;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		SUser* pData = m_list.GetAt(pos);
		if (pData->nNumb == nNumb){
			pData->Print();
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
	char sName[20];
	cout << "请输入姓名查找：";
	cin >> sName;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		SUser* pData = m_list.GetAt(pos);
		if (!strcmp(pData->sName , sName)){
			pData->Print();
			system("pause");
			return false;
		}
		m_list.GetNext(pos);
	}
	cout << "你输入的姓名不存在，是否重新输入[y/n]:";
	char c = _getch();
	putchar(c);
	puts("");
	return c == 'y' || c == 'Y';
}

void  CStudent::FindByType(){
	int i = 0;
	do{
		cout << "请输入你要查找的类型（0代表文科，1代表理科）：";
		cin >> i;
	} while (i != 0 && i != 1);
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		SUser* pData = m_list.GetAt(pos);
		if (pData->nType == i&&i==1){
			pData->Print();
		}
		if (pData->nType == i&&i==0){
			pData->Print();
		}
		m_list.GetNext(pos);
	}
	system("pause");
}

void CStudent::ColorSet()
{
}
/*
void CStudent::Load()
{
	FILE *pf = fopen("std.lv", "r");
	if (!pf)
		return;
	int nType = -1;
	DATA* pData = NULL;
	while (fread(&nType, 1, sizeof(nType), pf) == sizeof(nType)){
		if (nType == 1){
			SScn* p = new SScn;
			p->nType = 1;
			fread(&p->nNumb, 1, sizeof(SScn) - sizeof(nType) - sizeof(void*), pf);//按文件中的顺序读取，第一个参数表示读取之后放到哪里
			pData = p;
		}
		if (nType == 0){
			SArt* p = new SArt;
			p->nType = 0;
			fread(&p->nNumb, 1, sizeof(SArt) - sizeof(nType) - sizeof(void*), pf);
			pData = p;
		}
		if (pData)
			m_list.AddTail(pData);
	}
	fclose(pf);
}
*/
void CStudent::Load()
{
	FILE *pf = fopen("std.lv", "r");
	if (!pf)
		return;
	int nType = -1;
	DATA* pData = NULL;
	while (fread(&nType, 1, sizeof(nType), pf) == sizeof(nType)){
		if (nType == 1){
			pData = new SScn;
			pData->nType = 1;
		}
		if (nType == 0){
			pData = new SArt;
			pData->nType = 0;
		}
		if (pData){
			pData->Read(pf);
			m_list.AddTail(pData);
		}
	}
	fclose(pf);
}
/*
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
		DATA* pData = m_list.GetNext(pos);
		if (pData->nType == 1)
			fwrite(&pData->nType, 1, sizeof(SScn)-sizeof(void*), pf);	//第一个参数表示将哪个地址的数据写入文件 //头部多出一个虚函数指针
		if(pData->nType == 0)
			fwrite(&pData->nType, 1, sizeof(SArt) - sizeof(void*), pf);
	}
	fclose(pf);
}
*/
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
		DATA* pData = m_list.GetNext(pos);
		pData->Write(pf);
	}
	fclose(pf);
}

void CStudent::Print()
{
	int a = 0, s = 0;
	POSITION pos = m_list.GetHeadPosition();
	while (pos){
		DATA *pData = m_list.GetNext(pos);
		pData->Print();						
	}
}

void SScn::Input(){
	nType = 1;
	SUser::Input();
	cout << "请输入理科成绩（数学、物理、化学）:";
	cin >> this->fmath >>fPhys>> fChem;
}

void SScn::Print(){
	SUser::Print();
	cout << "理科成绩（数学、物理、化学）：" << endl;
	cout << fmath << "\t" << fPhys << "\t" << fChem << endl;
	cout << endl;
}

void SArt::Input(){
	nType = 0;
	SUser::Input();
	cout << "请输入文科成绩（语文、英语、历史、地理）：";
	cin >> this->fChin >> fEngl >> fHist >> fGeog;
}

void SArt::Print(){
	SUser::Print();
	cout << "文科成绩（语文、英语、历史、地理）：" << endl;
	cout << fChin << "\t" << fEngl << "\t" << fHist << "\t" << fGeog << endl;
	cout << endl;
}

void SUser::Input(){
	cout << "请输入学号、姓名和性别（男/女）:";
	cin >> this->nNumb >> sName >> cSex;
}

void SUser::Print(){
	cout << "基本信息（学号、姓名、性别）："<<endl;
	cout << nNumb << "\t" << sName << "\t" << cSex << endl;
}