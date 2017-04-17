#include <stdio.h>  
#include <errno.h>  
#include<iostream>
using namespace std;
#ifndef INT_MAX  
#define INT_MAX     ((int)(~0U>>1))  
#endif  


void merge(int *a, int start, int mid, int end)
{
	int nl = mid - start + 1;
	int nr = end - mid;
	int sentinel = INT_MAX;
	int *left = new int[nl + 1];
	int *right = new int[nr + 1];
	int i, j, k ;

	for (i = 0; i < nl; ++i) {
		left[i] = a[start + i];
	}
	/* Set sentinel */
	left[i] = sentinel;

	for (j = 0; j < nr; ++j) {
		right[j] = a[mid + 1 + j];
	}
	/* Set sentinel */
	right[j] = sentinel;

	i = j = 0;
	for (k = start; k <= end; ++k) {
		if (left[i] <= right[j]) 
			a[k] = left[i++];	
		else 
			a[k] = right[j++];
	}
	delete[] left;
	delete[] right;
}

void merge_sort(int *a, int start, int end)
{
	int mid;

	if ((start >= 0) && (start < end)) {
		mid = (start + end) / 2;

		merge_sort(a, start, mid);
		merge_sort(a, mid + 1, end);

		merge(a, start, mid, end);
	}
}

int check_exist_x(int *a, int len, int x)
{
	int i, j, k;
	int last;
	int *tmp = new int[len];
	int *collection = new int[2 * len];
	int repeats;

	if (len < 1) {
		fprintf(stderr, "Too few elements.\n");
		return -EINVAL;
	}

	merge_sort(a, 0, len - 1);

	last = 0;
	/* Remove repeat elements */
	for (i = 1; i < len; ++i) {
		if (a[last] == a[i]) {
			if ((a[last] << 1) == x) {
				/* Found */
				return 1;
			}
			continue;
		}
		a[++last] = a[i];
	}
	++last;

	/* Form tmp set */
	for (i = 0; i < last; ++i) 
		tmp[i] = x - a[i];

	i = 0;
	j = last - 1;
	k = 0;
	/* Merge */
	while ((i < last) && (j >= 0)) {
		if (a[i] < tmp[j]) 
			collection[k++] = a[i++];		
		else 
			collection[k++] = tmp[j--];
	}
	while (i < last) 
		collection[k++] = a[i++];
	while (j >= 0) 
		collection[k++] = tmp[j--];

	repeats = 0;
	/* Check the number of repeat elements */
	for (i = 1, j = 0; i < k; ++i, ++j) {
		if (collection[i] == collection[j]) 
			++repeats;
		if (repeats >= 2) 
			return 1;
	}
	return -1;
}

int main()
{
	int source[] = { 7, 5, 2, 4, 6, 1, 5, 3 ,3 ,7 };
	int ret;
	int x = 14;
	int len = sizeof(source)/sizeof(int);
	ret = check_exist_x(source, len , x);

	cout << "If there are two elements whose sum equals to " << x << (ret < 0 ? " No" : " Yes") << endl;
	system("pause");
	return 0;
}