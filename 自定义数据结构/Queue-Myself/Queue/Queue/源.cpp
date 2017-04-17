#include"Queue.h"
#include<iostream>
using namespace std;
int main(){
	CQueue<int> q;
	int i = 0;
	while (i < 10)
		q.push(++i);
	int d=0;
	q.pop(d);
	q.pop(d);
	i = 0;
	while (i < 5)
		q.push(++i);
	return 0;
}