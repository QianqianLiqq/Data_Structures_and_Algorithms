#include<iostream>
#include"Map.h"
using namespace std;

int main(){
	DATA ds[] = {
		{ 1008, "张珊", 95.5f },
		{ 1018, "李思思", 100 },
		{ 1031, "王五", 96 },
		{ 1038, "赵六", 89.5f },
		{ 1068, "john", 91 },
		{ 1022, "smith", 95.5f },
		{ 1055, "Tom", 88 },
		{ 1023, "Alice", 91.5f },
		{ 1055, "汤姆", 98 },
	};
	CMap m;
	int i = 0;
	while (i < _countof(ds)){
		m.SetAt(ds[i].nNumb, ds[i]);
		++i;
	}
	VALUE v;
	if (m.Lookup(1038, v)){
		cout << v.nNumb << "\t" << v.sName << "\t" << v.fMath << endl;
	}
	else{
		cout << "没有找到" << endl;
	}
	v = m[1055];//Lookup
	m[1055] = { 1055, "aaa", 98 };//SetAt
	system("pause");
	return 0;
}
/*enum{COUNT=17};
typedef int DATA;
struct SNode{
	DATA data;
	SNode* pNext;
};
SNode* g_hash[COUNT] = { NULL };
void SetAt(DATA data){
	int n = data%COUNT;
	SNode* p = new SNode;
	p->data = data;
	p->pNext = g_hash[n];
	g_hash[n] = p;
}
bool Lookup(DATA data){
	int n = data%COUNT;
	SNode* p = g_hash[n];
	while (p){
		if (p->data == data)
			return true;
		p = p->pNext;
	}
	return false;
}
int main(){
	SetAt(32);
	SetAt(49);
	SetAt(108);
	SetAt(52);
	SetAt(88);
	SetAt(67);
	SetAt(93);
	if (Lookup(49))
		cout << "找到49" << endl;
	else
	    cout << "没有找到49" << endl;
	if (Lookup(48))
		cout << "找到48" << endl;
	else
		cout << "没有找到48" << endl;
	system("pause");
	return 0;
}
*/