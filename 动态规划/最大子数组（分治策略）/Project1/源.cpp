#include<iostream>
using namespace std;

int find_max_crossing_subarray(int *arr, int low, int mid, int high) {
	int sum = 0;

	int left_sum = arr[mid];
	sum = 0;
	for (int i = mid; i >= low; i--) {
		sum += arr[i];
		if (sum > left_sum)
			left_sum = sum;
	}

	int right_sum = arr[mid + 1];
	sum = 0;
	for (int i = mid + 1; i <= high; i++) {
		sum += arr[i];
		if (sum > right_sum)
			right_sum = sum;
	}

	return (left_sum + right_sum);
}

int find_max_subarray(int *arr, int low, int high) {
	if (low == high)
		return arr[low];

	int mid = (low + high) / 2;

	int left_max = find_max_subarray(arr, low, mid);
	int right_max = find_max_subarray(arr, mid + 1, high);
	int cross_max = find_max_crossing_subarray(arr, low, mid, high);

 	if (left_max > right_max && left_max > cross_max)
		return left_max;
	else if (right_max > left_max && right_max > cross_max)
		return right_max;
	else
		return cross_max;
}

int main(){
	int a[5] = { 8, -4, 5, -2, 3 };
	int result = find_max_subarray(a, 0, 4);
	cout << result << endl;
	system("pause");
}
