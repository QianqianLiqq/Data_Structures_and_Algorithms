#include"List.h"
#include<iostream>
using namespace std;

CList list;

void Delete(int d){
	POSITION pos = list.GetHeadPosition();
	while (pos){
		if (list.GetAt(pos) == d){
			list.RemoveAt(pos);
			break;
		}
		list.GetNext(pos);
	}
}

void Modify(DATA old, DATA d){
	POSITION pos = list.GetHeadPosition();
	while (pos){
		if (list.GetAt(pos) == old)
			list.SetAt(pos, d);
		list.GetNext(pos);
	}
}

int main(){
	list.AddHead(12);
	list.AddHead(20);
	list.AddHead(33);
	list.AddTail(50);
	list.AddTail(88);
	//Delete(33);
	Modify(12, 1);
	POSITION pos = list.GetHeadPosition();
	cout << "正向打印：" << endl;
	while (pos)
		cout << list.GetNext(pos) << endl;
	pos = list.GetTailPosition();
	cout << "反向打印：" << endl;
	while (pos)
		cout << list.GetPrev(pos) << endl;
	cout << "总共有"<<list.GetCount() <<"条数据！"<< endl;
	system("pause");
	return 0;
}