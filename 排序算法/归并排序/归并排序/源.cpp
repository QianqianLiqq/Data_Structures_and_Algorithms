#include<iostream>
using namespace std;
void Merge(int *a, int low, int mid, int high)
{
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];
	int i, j, k;

	for (i = 0; i<n1; i++){
		L[i] = a[low + i];
	}
	for (j = 0; j<n2; j++){
		R[j] = a[mid + j + 1];
	}
	L[n1] = 10000000;
	R[n2] = 10000000;

	for (i = 0, j = 0, k = low; k <= high; k++)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else{
			a[k] = R[j];
			j++;
		}
	}

	delete[]L;
	delete[]R;
}

void MergeSort1(int *a, int low, int high)
{
	if (low<high)
	{
		int mid = (low + high) / 2;
		MergeSort1(a, low, mid);
		MergeSort1(a, mid + 1, high);
		Merge(a, low, mid, high);
	}
}
int main(){
	int a[7] = { 16, 7, 3, 20, 17, 8 ,1};
	MergeSort1(a, 0, 6);
	for (int i = 0; i < 7; ++i)
		cout << a[i] << "\t" ;
	cout << endl;
	system("pause");
	return 0;
}