#include<iostream>
#include<vector>
using namespace std;

void QuickSort(int *a,int *b,int start,int end){
	if (start > end)
		return;
	int i = start;
	int j = end;
	int key = a[i];
	int key2 = b[i];
	while (i != j){
		while (a[j] >= key&&i < j)
			--j;
		while (a[i] <= key&&i < j)
			++i;
		if (i < j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			int res = b[i];
			b[i] = b[j];
			b[j] = res;
		}
	}
	a[start] = a[i];
	a[i] = key;
	b[start] = b[i];
	b[i] = key2;
	QuickSort(a, b, start, i - 1);
	QuickSort(a, b, i + 1, end);
}

vector<int> Greedy_Activity_Selector(int*s, int*f, int n) {
	vector<int> A ;

	int k = 0;
	A.push_back(k+1);

	for (int m =1; m < n; m++) {
		if (s[m] >= f[k]) {
			A.push_back(m+1);
			k = m;
		}
	}
	return A;
}

int main(){
	int s[] = { 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12 };
	int f[] = { 4, 5, 6, 7, 8, 9, 10,  11, 12, 13, 14 };
	int n = sizeof(s) / sizeof(s[0]);
	QuickSort(f, s, 0, n - 1);
	vector<int> A = Greedy_Activity_Selector(s, f, n);
	for (int i = 0; i < A.size(); ++i)
		cout << A[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}