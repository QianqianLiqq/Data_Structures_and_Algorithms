#include"List.h"
#include<iostream>
using namespace std;

CList list;

void Delete(int d){
	CList::iterator it = list.begin();
	while (it != NULL){
		if (*it == d){
			list.erase(it);
			break;
		}
		++it;
	}
}

/*
void Modify(DATA old, DATA d){
	CList::iterator it = list.begin();
	while (it!=NULL){
		if (*it == old)
			list.SetAt(pos, d);
		++it;
	}
}
*/

int main(){
	list.push_front(12);
	list.push_front(20);
	list.push_front(33);
	list.push_back(50);
	list.push_back(88);
	//Delete(33);
	//Modify(12, 1);
	CList::iterator it = list.begin();
	cout << "正向打印：" << endl;
	while (it!=NULL)
		cout << *it++ << endl;
	it = list.end();
	cout << "反向打印：" << endl;
	while (it)
		cout << *it-- << endl;
	cout << "总共有"<<list.size() <<"条数据！"<< endl;
	system("pause");
	return 0;
}