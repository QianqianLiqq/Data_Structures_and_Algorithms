#include<map>//���ö�������ʵ�ֵ�
#include<iostream>
using namespace std;
int main(){
	map<char, int> mymap;
	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	mymap['d'] = 40;
	mymap['e'] = 50;
	mymap['f'] = 60;
	map<char, int>::iterator it;
	it = mymap.find('b');
	mymap.erase(it);//������ɾ��
	mymap.erase('c');//keyֵɾ��
	it = mymap.find('e');
	mymap.erase(it, mymap.end());//����ɾ��
	for (it = mymap.begin(); it != mymap.end(); ++it)//����������õ�����
		cout << it->first << "=>" << it->second << endl;
	if (mymap.find('g') == mymap.end())//����һ��key�Ƿ����
		cout << "û�и�����" << endl;
	cout << mymap['g'] << endl;//���Ҳ����ڵ�key����������
	if (mymap.count('x') == 0)//Ҳ���Բ���һ��key�Ƿ����
		cout << "û�и�����" << endl;
	cout << mymap['x'] << endl;
	system("pause");
	return 0;
}

/*
map<char, int> first;
first['a'] = 10;
first['b'] = 20;
first['c'] = 30;
map<char, int> second(first.begin(), first.end());//���캯��
map<char, int> third = first;//���ƹ��캯��
*/

/*
map<char, string> mymap;
mymap['a'] = "an element";
mymap['b'] = "another element";
mymap['c'] = mymap['b'];
cout << "mymap now size is" << "\t" << mymap.size() << endl;
cout << "mymap['a'] is" << "\t" << mymap['a'].c_str() << endl;
cout << "mymap['b'] is" << "\t" << mymap['b'].c_str() << endl;
cout << "mymap['c'] is" << "\t" << mymap['c'].c_str() << endl;
cout << "mymap['d'] is" << "\t" << mymap['d'].c_str() << endl;
cout << "mymap now size is" << "\t" << mymap.size() << endl;
system("pause");
*/