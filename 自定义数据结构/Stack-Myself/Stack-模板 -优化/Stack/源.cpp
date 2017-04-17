#include<iostream>
#include"Stack.h"
using namespace std;

int main(){
	CStack<int> st;
	int i = 0;
	while (i < 10){
		st.push(i);
		++i;
	}
	int  d;
	while (i > 0){
		if (st.pop(d))
			cout << d << endl;
		--i;
	}
	system("pause");
	return 0;
}