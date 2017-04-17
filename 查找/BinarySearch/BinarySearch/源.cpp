#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
static const int ERROR = -1;

template<typename T>
int binary_search(T *array, const int size, const T & key)
{
	if (NULL == array || size < 1)
	{
		cout << "illegal input!" << endl;
		return ERROR;
	}

	int low = 0, high = size - 1;
	int mid_index = 0;

	while (low <= high)
	{
		mid_index = (low + high) / 2;

		if (key == array[mid_index])
			return mid_index;
		else if (key > array[mid_index])
			low = mid_index + 1;
		else
			high = mid_index - 1;
	}

	return ERROR;
}
int main(){
	 int a[6] = { 12, 4, 9, 10, 65, 77 };
	 int i = binary_search(a, 6, 77);
	 cout << i << endl;
	 system("pause");
}