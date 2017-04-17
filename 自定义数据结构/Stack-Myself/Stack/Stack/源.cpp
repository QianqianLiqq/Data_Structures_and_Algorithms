#include<iostream>
#include"Stack.h"
using namespace std;

int main(){
	CStack st;
	int i = 0;
	while (i < 10){
		st.push(i);
		++i;
	}
	DATA d;
	while (i > 0){
		if (st.pop(d))
			cout << d << endl;
		--i;
	}
	system("pause");
	return 0;
}