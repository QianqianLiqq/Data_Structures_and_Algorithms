#include<iostream>
#include"Map.h"
using namespace std;
int main(){
	VALUE ds[] = {
		{ 1038, "赵六", 89.5f },	
		{ 1018, "李思思", 100 },
		{ 1008, "张珊", 95.5f },
		{ 1031, "王五", 96 },
		{ 1068, "john", 91 },
		{ 1022, "smith", 95.5f },
		{ 1055, "tom", 88 },
		{ 1023, "Alice", 91.5f },
		{ 1072, "汤姆", 98 }
	};
	CMap m;
	int i = -1;
	while (++i < _countof(ds))
		m.SetAt(ds[i].nNumb, ds[i]);
	VALUE v1;
	if (m.Lookup(1021, v1))
		cout << v1.nNumb << "\t" << v1.sName << "\t" << v1.fMath << endl;
	else
		cout << "没找到这个学号" << endl;
	if (m.Lookup(1022, v1))
		cout << v1.nNumb << "\t" << v1.sName << "\t" << v1.fMath << endl;
	else
		cout << "没找到这个学号" << endl;
	VALUE v2 = m[1055];
	cout << v2.nNumb << "\t" << v2.sName << "\t" << v2.fMath << endl;
	v2 = m[1056];//查找
	cout << v2.nNumb << "\t" << v2.sName << "\t" << v2.fMath << endl;
	m[1056] = { 1056, "测试", 100 };//赋值
	cout << m[1056].nNumb << "\t" << m[1056].sName << "\t" << m[1056].fMath << endl;
	system("pause");
	return 0;
}