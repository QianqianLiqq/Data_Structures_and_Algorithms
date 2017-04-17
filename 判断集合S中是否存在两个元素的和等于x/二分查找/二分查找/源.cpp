#include<iostream>
using namespace std;
void QuickSort(int *a, int low, int high){
	int i, j, key, temp;
	i = low;
	j = high;
	key = a[low];
	if (low > high)
		return;
	while (i != j){
		while (i < j&&a[j] >= key)
			--j;
		while (i < j&&a[i] <= key)
			++i;
		if (i < j){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[low] = a[i];
	a[i] = key;
	QuickSort(a, low, i - 1);
	QuickSort(a, i+1, high);
}
int BinarySearch(int *a, int low, int high,int key){
	if (low > high)
		return -1;
	int mid = 0;
	while (low <= high){
		mid = (low + high) / 2;
		if (key == a[mid])
			return mid;
		else if (key < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
bool findX(int *a, int low, int high, int x){
	for (int i = low; i < high; ++i){
		int key = a[i];
		if (BinarySearch(a, i + 1, high, x - key)>-1)
			return true;
	}
	return false;
}
int main(){
	int a[10] = { 12, 20, 5, 9, 25, 18, 30, 21, 28, 7 };
	QuickSort(a, 0, 9);
	for (int i = 0; i < 10; ++i)
		cout << a[i] << " ";
	cout << endl;
	if (findX(a, 0, 9, 40))
		cout << "存在" << endl;
	else
		cout<< "不存在" << endl;
	if (findX(a, 0, 9, 30))
		cout << "存在" << endl;
	else
		cout << "不存在" << endl;
	if (findX(a, 0, 9, 8))
		cout << "存在" << endl;
	else
		cout << "不存在" << endl;
	system("pause");
}