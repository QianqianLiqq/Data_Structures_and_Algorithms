#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v;
	vector<int>::iterator it = v.begin();
	v.push_back(23);
	v.push_back(11);
	v.insert(v.begin(), 5);//��ǰ�����5
	v.insert(v.begin(), 3, 4);//��ǰ�����3��4
	v.insert(v.begin() + 2, 5, -1);
/*	int &x = v[1];
	x = -1;
*/ 
	//v.resize(20);
	v.resize(15,-8);
/*	int i = 0;
	while (i < v.size()){
		cout << v[i] << endl;
		++i;
	}
*/
	it = v.begin();
	while (it != v.end()){
		cout << *it <<" ";
		++it;
	}
	cout << endl;
	cout << "ɾ����" << endl;
	v.erase(v.begin(), v.begin() + 3);
	it = v.begin();
	while (it != v.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;
	sort(v.begin(), v.end());
	cout << "�����" << endl;
	it = v.begin();
	while (it != v.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;
	system("pause");
	return 0;
}
