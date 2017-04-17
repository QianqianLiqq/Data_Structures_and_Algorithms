#include<iostream>
#include<list>
using namespace std;

typedef struct Student{
	int nNumb;
	char sName[20];
	float fMath;
}DATA;

list<DATA> m_list;

void Input(){
	DATA d1 = { 10001, "张三", 98.5f };
	DATA d2 = { 10008, "李四", 95.5f };
	DATA d3 = { 10005, "王五", 99.5f };
	m_list.push_back(d1);
	m_list.push_back(d2);
	m_list.push_back(d3);
}

void Print(){
	list<DATA>::iterator it = m_list.begin();
	while (it != m_list.end()){
		cout << it->nNumb << "\t" << it->sName << "\t" << it->fMath << endl;
		it++;
	}
	//system("pause");
}

bool ByNumb(DATA &d1, DATA &d2){
	return d1.nNumb < d2.nNumb;
}

bool ByName(DATA &d1, DATA &d2){
	return strcmp(d1.sName, d2.sName) < 0;
}

bool ByMath(DATA &d1, DATA &d2){
	return d1.fMath > d2.fMath;
}

void Delete(int nNumb){
	list<DATA>::iterator it = m_list.begin();
	for (; it != m_list.end(); ++it){
		if (it->nNumb == nNumb){
			m_list.erase(it);
			break;
		}
	}
}

int main(){
	Input();
/*	cout << "排序前：" << endl;
	Print();
	cout << "按学号排序后：" << endl;
	m_list.sort(ByNumb);
	//m_list.sort(ByName);
	//m_list.sort(ByMath);
	Print();
	cout << "按姓名排序后：" << endl;
	//m_list.sort(ByNumb);
	m_list.sort(ByName);
	//m_list.sort(ByMath);
	Print();
	cout << "按成绩排序后：" << endl;
	//m_list.sort(ByNumb);
	//m_list.sort(ByName);
	m_list.sort(ByMath);   */
	Print();
	Delete(10001);
	Print();
	system("pause");
	return 0;
}