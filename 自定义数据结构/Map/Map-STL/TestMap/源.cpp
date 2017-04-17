#include<map>//利用二叉树来实现的
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
	mymap.erase(it);//迭代器删除
	mymap.erase('c');//key值删除
	it = mymap.find('e');
	mymap.erase(it, mymap.end());//区间删除
	for (it = mymap.begin(); it != mymap.end(); ++it)//中序遍历，得到排序
		cout << it->first << "=>" << it->second << endl;
	if (mymap.find('g') == mymap.end())//查找一个key是否存在
		cout << "没有该数据" << endl;
	cout << mymap['g'] << endl;//查找不存在的key，会进行填充
	if (mymap.count('x') == 0)//也可以查找一个key是否存在
		cout << "没有该数据" << endl;
	cout << mymap['x'] << endl;
	system("pause");
	return 0;
}

/*
map<char, int> first;
first['a'] = 10;
first['b'] = 20;
first['c'] = 30;
map<char, int> second(first.begin(), first.end());//构造函数
map<char, int> third = first;//复制构造函数
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