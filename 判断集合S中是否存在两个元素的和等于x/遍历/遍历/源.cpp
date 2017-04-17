#include<iostream>
using namespace std;
bool findX(int *a, int len, int x){
	for (int i = 0; i < len - 1; ++i){
		for (int j = i + 1; j < len; ++j){
			if (a[i] + a[j] == x)
				return true;
		}
	}
	return false;
}
int main(){
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	if (findX(a, 10, 8))
		cout << "存在" << endl;
	else
		cout << "不存在" << endl;
	if (findX(a, 10, 20))
		cout << "存在" << endl;
	else
		cout << "不存在" << endl;
	system("pause");
	return 0;
}