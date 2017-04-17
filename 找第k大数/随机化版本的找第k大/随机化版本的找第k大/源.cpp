#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

#define random(x)(rand() % x)

void findkth(int* a, int s, int e, int k)
{
	 if (s>e) return;
	 if (s == e){
		cout << a[s] << endl;
		return;
	}
	int index = rand() % (e - s + 1);
	int pivot = a[s + index], temp;
	temp = a[s]; a[s] = pivot; a[s + index] = temp;
	// 下面这一段做partition的工作
	int i = s, j;
	for (j = s + 1; j <= e; j++){
		if (a[j]<pivot){
			temp = a[++i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i]; a[i] = pivot; a[s] = temp;
	if (i == k){
		cout << pivot << endl;
		return;
	}else if (i<k){
		findkth(a, i + 1, e, k);
	}else{
		findkth(a, s, i-1 , k);
	}
}

int main(){
	int a[10] ;
	int i, j, k, index;
	srand(time(0));//重置随机数种子，以当前时间为参数
	               //如果没调用srand()，你会发现你每次运行程序，rand()得到的序列值是不变的
	for (i = 0; i<10; i++){
		a[i] = random(50);
		cout << a[i] << " ";
	}
	cout << endl;
	while (1){
		cin >> k;
		findkth(a, 0, 10 - 1, k);
	}
	return 0;
}