#include<iostream>
#include"Map.h"
using namespace std;
int main(){
	VALUE ds[] = {
		{ 1038, "����", 89.5f },	
		{ 1018, "��˼˼", 100 },
		{ 1008, "��ɺ", 95.5f },
		{ 1031, "����", 96 },
		{ 1068, "john", 91 },
		{ 1022, "smith", 95.5f },
		{ 1055, "tom", 88 },
		{ 1023, "Alice", 91.5f },
		{ 1072, "��ķ", 98 }
	};
	CMap m;
	int i = -1;
	while (++i < _countof(ds))
		m.SetAt(ds[i].nNumb, ds[i]);
	VALUE v1;
	if (m.Lookup(1021, v1))
		cout << v1.nNumb << "\t" << v1.sName << "\t" << v1.fMath << endl;
	else
		cout << "û�ҵ����ѧ��" << endl;
	if (m.Lookup(1022, v1))
		cout << v1.nNumb << "\t" << v1.sName << "\t" << v1.fMath << endl;
	else
		cout << "û�ҵ����ѧ��" << endl;
	VALUE v2 = m[1055];
	cout << v2.nNumb << "\t" << v2.sName << "\t" << v2.fMath << endl;
	v2 = m[1056];//����
	cout << v2.nNumb << "\t" << v2.sName << "\t" << v2.fMath << endl;
	m[1056] = { 1056, "����", 100 };//��ֵ
	cout << m[1056].nNumb << "\t" << m[1056].sName << "\t" << m[1056].fMath << endl;
	system("pause");
	return 0;
}