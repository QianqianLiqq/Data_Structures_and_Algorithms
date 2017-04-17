//思路:使用快速排序的patition函数来进行处理 时间复杂度为O(n)  
#include<iostream>  
#include<cassert>  
using namespace std;

int partition(int *ar, int low, int high)
{
	int key = ar[low];
	int i = low, j = high;
	while (i!=j)
	{
		while (i < j && key <= ar[j])		
			j--;
		while (i < j && key >= ar[i])
			i++;
		if (i < j)
		{
			int temp = ar[i];
			ar[i] = ar[j];
			ar[j] = temp;
		}
	}
	ar[low] = ar[i];
	ar[i] = key;
	return i;
}

/*int partition(int *ar, int len, int low, int high)
{
	int temp = ar[low];

	while (low < high)
	{
		while (low < high && temp < ar[high])
			high--;
		if (low == high)
			break;
		else
			ar[low] = ar[high];

		while (low < high && temp > ar[low])
			low++;
		if (low == high)
			break;
		else
			ar[high] = ar[low];
	}
	ar[low] = temp;
	return low;
}*/
int findkmin(int *ar, int len, int k)//寻找第k小的数  
{
	assert((ar != NULL) && (k>0) && (k<len + 1));

	int low = 0;
	int high = len - 1;

	int index = partition(ar,  low, high);
	while (index != k - 1)
	{
		if (index > k)
		{
			index = partition(ar, low, index - 1);
		}
		else
		{
			index = partition(ar,  index + 1, high);
		}
	}
	return ar[index];
}

void findkmin(int *ar, int len, int k, int *retar)//寻找最小的k个数  
{
	assert((ar != NULL) && (k>0) && (k<len + 1) && (retar != NULL));

	int low = 0;
	int high = len - 1;
	int index = partition(ar,  low, high);

	while (index != k - 1)
	{
		if (index > k-1)
		{
			index = partition(ar,  low, index - 1);
		}
		else
		{
			index = partition(ar,  index + 1, high);
		}
	}

	for (int i = 0; i <= index; ++i)
	{
		retar[i] = ar[i];
	}
}

void show(int *ar, int len)
{
	for (int i = 0; i<len; ++i)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
}

int main()
{
	int ar[] = { 12,5,10,65,32,50,18,18,70,45,68,29 };
	int retar[32];
	int len = sizeof(ar) / sizeof(ar[0]);
	int len2 = sizeof(retar) / sizeof(retar[0]);

	cout << findkmin(ar, len, 10) << endl;
	cout << findkmin(ar, len, 11) << endl;
	cout << findkmin(ar, len, 12) << endl;  

	findkmin(ar, len, 7, retar);
	show(retar, 7);
	findkmin(ar, len, 1, retar);
	show(retar, 1);
	findkmin(ar, len, 5, retar);
	show(retar, 5);
	system("pause");
	return 0;
}