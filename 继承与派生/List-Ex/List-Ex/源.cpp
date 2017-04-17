#include"ListEx.h"
#include<iostream>
using namespace std;
typedef struct SStud{
	int nNumb;
	char sName[20];
	float fMath;
}DATA;
bool byNumb(const DATA& d1,const DATA& d2){
	return d1.nNumb < d2.nNumb;
}
bool byName(const DATA& d1, const DATA& d2){
	return strcmp(d1.sName, d2.sName) < 0;
}
bool byMath(const DATA& d1, const DATA& d2){
	return d1.fMath > d2.fMath;
}
int main(){
	CListEx<DATA> list2;
	DATA ds[] = {
		{ 1008, "张珊",93.5f },
		{ 1004, "李四",92 },
		{ 1003, "alice",95 },
		{ 1006, "smith",98 }
	};
	list2.AddTail(ds[0]);
	list2.AddTail(ds[1]);
	list2.AddTail(ds[2]);
	list2.AddTail(ds[3]);
	POSITION p = list2.GetHeadPosition();
	while (p){
		DATA &d= list2.GetAt(p);
		cout << d.nNumb << "\t" << d.sName << "\t" << d.fMath << endl;
		list2.GetNext(p);
	}
	cout << "总共有" << list2.GetCount() << "条数据！" << endl;
	cout << "按学号排序：" << endl;
	list2.Sort(byNumb);
	p = list2.GetHeadPosition();
	while (p){
		DATA &d = list2.GetAt(p);
		cout << d.nNumb << "\t" << d.sName << "\t" << d.fMath << endl;
		list2.GetNext(p);
	}
	cout << "按姓名排序：" << endl;
	list2.Sort(byName);
	p = list2.GetHeadPosition();
	while (p){
		DATA &d = list2.GetAt(p);
		cout << d.nNumb << "\t" << d.sName << "\t" << d.fMath << endl;
		list2.GetNext(p);
	}
	cout << "按分数排序：" << endl;
	list2.Sort(byMath);
	p = list2.GetHeadPosition();
	while (p){
		DATA &d = list2.GetAt(p);
		cout << d.nNumb << "\t" << d.sName << "\t" << d.fMath << endl;
		list2.GetNext(p);
	}
	cout << "按学号排序：" << endl;
	POSITION* ps = list2.Sort2(byNumb);
	int i = 0;
	while (i<list2.GetCount()){
		DATA &d = list2.GetAt(ps[i]);
		cout << d.nNumb << "\t" << d.sName << "\t" << d.fMath << endl;
		i++;
	}
	delete[]ps;
/*	CListEx<int> list;
	list.AddHead(32);
	list.AddHead(12);
	list.AddHead(20);
	list.AddTail(34);
	list.AddTail(11);
	list.AddTail(30);
	POSITION p = list.GetHeadPosition();
	while (p)
		cout << list.GetNext(p) << "";
	cout << endl;
	cout << "总共有" << list.GetCount() << "条数据！" << endl;
	list.Sort();
	cout << "排序后：" << endl;
    p = list.GetHeadPosition();
	while (p)
		cout << list.GetNext(p) << "";
	cout << endl;
	cout << "总共有" << list.GetCount() << "条数据！" << endl;
*/
	system("pause");
	return 0;
}