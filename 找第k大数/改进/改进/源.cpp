#include<iostream>
using namespace std;

int r = 5;  //����ȫ�ֱ���r, r��Ԫ��һ��

void InSort(int A[], int m, int p)  //��������
{
	int i;
	for (i = m + 1; i <= p; ++i) {
		int t;
		t = A[i];
		int j;
		for (j = i - 1; j >= m; --j) {
			if (t < A[j])
				A[j + 1] = A[j];
			else
				break;
		}
		A[j + 1] = t;
	}
}

void Swap(int &a, int &b) //��������
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

int Partition(int A[], int m, int p) //һ�λ��ֺ���
{
	int i = m, j = p + 1;
	int x = A[m];
	while (1) {
		while (A[++i] > x);
		while (A[--j] < x);
		if (i >= j)
			break;
		Swap(A[i], A[j]);
	}
	A[m] = A[j];
	A[j] = x;
	return j;
}

int Select(int A[], int m, int p, int k)  //����һ��iֵ��ʹ��A[i]��A[m..p]�е�kСԪ��
{
	int n = 0, i = 1, j = 0;
	if (p - m + 1 <= r) {
		InSort(A, m, p);
		return m + k - 1;
	}
	while (1) {
		n = p - m + 1;
		for (i = 1; i <= n / r; ++i) {  //�����м�ֵ
			InSort(A, m + (i - 1) * r, m + i * r - 1);
			//���м�ֵ�ռ���A[m..p]��ǰ��
			Swap(A[m + i - 1], A[m + (i - 1)*r + r / 2]);
		}
		j = Select(A, m, m + n / r - 1, (n / r) / 2 + 1);
		Swap(A[m], A[j]); //��������Ԫ��
		j = Partition(A, m, p);
		if (j - m + 1 == k)
			return j;
		else if (j - m + 1 > k)
			p = j - 1;	 
		else {
			k = k - (j - m + 1);
			m = j + 1;
		}
	}
}

int main()
{
	int A[24] = { 1, 3, 6, 33, 4, 1, 5, 2, 9, 8, 50, 22, 2, 23, 22, 45, 7, 18, 20, 40, 36, 22, 23, 10 };
	int find_out = Select(A, 0, 23, 7);
	int i;
	for (i = 0; i <= 23; ++i)
		cout << A[i] << " ";
	cout << endl;
	cout << A[find_out] << endl;
	system("pause");
	return 0;
}