/*
*copyright@nciaebupt 转载请注明出处
*问题：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整数组成一个子数组。
*求所有子数组的和的最大值。要求时间负责度为O(n)。
*使用动态规划方法来实现：
*如果用函数f(i)表示以第i个数字结尾的子数组的最大和，那么我们需要求出max(f[0...n])。
*我们可以给出如下递归公式求f(i)
*     |-- array[i] 如果i==0或者f(i-1)<0
*f(i)=|
*     |-- f(i-1) + array[i] 如果f(i-1)>0
*这个公式的意义：
*   当以第(i-1)个数字为结尾的子数组中所有数字的和f(i-1)小于0时，如果把这个负数和第i个数相加，得到的结果反而不第i个数本身还要小，所以这种情况下最大子数组和是第i个数本身。
*   如果以第(i-1)个数字为结尾的子数组中所有数字的和f(i-1)大于0，与第i个数累加就得到了以第i个数结尾的子数组中所有数字的和。
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int maxSumInSubArray(int *array, int len)
{
	int *c = new int[len];//用来记录以当前元素结尾（数组就到当前元素的位置为止）的子数组的最大和
	int max = array[0];//用来记录数组c[]中的最大值
	int start = 0;//记录数组中子数组的最大和的开始位置
	int end = 0;//记录数组中子数组的最大和的结束位置
	int tmp = 0;

	c[0] = array[0];
	for (int i = 1; i < len; ++i)
	{
		if (c[i - 1] > 0)
		{
			c[i] = c[i - 1] + array[i];
		}
		else
		{
			c[i] = array[i];
			tmp = i;
		}
		if (c[i] > max)
		{
			max = c[i];
			start = tmp;
			end = i;
		}
	}
	for (int i = 0; i < len; ++i)
		cout << c[i] << " ";
	cout << endl;
	cout << "子数组最大和的起始位置：" << start << "~" << end << endl;
	return max;
}

int main(int args, char ** argv)
{
	int array[] = { 0,0,0,1, -1, 3, 10, -4, 7, 2, -5 };
	int len = sizeof(array) / sizeof(int);
	int res = maxSumInSubArray(array, len);
	cout << "子数组最大和: " << res << endl;
	system("pause");
	return 0;
}