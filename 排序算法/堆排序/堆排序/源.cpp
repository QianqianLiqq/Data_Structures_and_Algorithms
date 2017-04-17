//堆排序  
#include <iostream>  
using namespace std;

/*堆排序算法解析：
核心思想在于建立最大堆(或最小堆），
因为最大堆满足一个性质:所有的父节点都要比它的左右节点均要大，
于是据此可以每次将最大的(根节点)抽取出来(实际上是放最后面),
每次都抽取剩余部分的最大值，那最终得到的序列就是有序的。
所以堆排序其实算是一种高级版的选择排序。
建立最大堆的方法：首先从底层的父节点开始，把它的子树整成最大堆，
然后往上整成最大堆，注意这里要从下往上。
最后堆排序就是先建立一个最大堆，然后把根节点元素也就是最大的元素
跟最后面的元素交换，这样一来，树就未必满足最大堆了，所以要重新
进行堆的调整（不包括已经被抽取的最大元素）。这样下来，每次都抽取
出子序列的最大元素，最终的序列就从小到大排好序了。*/

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void HeapAdjust(int *a, int i, int size)
{
	int left = 2 * i;//左孩子节点  
	int right = 2 * i + 1;//右孩子节点  
	int max = i;//暂存最大元素下标  
	if (left <= size && a[left] > a[max])
		//这里不直接交换是因为如果交换则要进行递归,  
		//所以连同右边的也判断了再做可能的交换和做可能的递归，  
		//递归的原因则是因为你把人的老爸交换了，  
		//那人家的儿子可能就比继父要大了。  
		//swap(a,left,i);  
		max = left;
	if (right <= size && a[right] > a[max])
		max = right;
	if (max != i)//表明当前的父节点并不是最大的  
	{
		swap(a, i, max);
		HeapAdjust(a, max, size);//有交换就要递归把子树也整成最大堆  
	}
}

void BuildHeap(int a[], int size)
{
	for (int i = size / 2; i >= 1; i--)//非叶节点最大下标为/2  
	{
		HeapAdjust(a, i, size);
	}
}

//堆排序对要排序的序列有个要求就是下标是从1开始到size的，而并非常用的0~size-1  
void HeapSort(int a[], int size)
{
	BuildHeap(a, size);//先建立初始的最大堆  
	for (int i = size; i >= 2; i--)
	{
		swap(a, 1, i);//把最大的元素放到最后面  
		size--;//不再包括最大的元素  
		//这里之所以直接从根节点开始维护堆是因为除了根节点外的其他子树都是最大堆了。  
		//而上面第一次建立最大堆时不能保证父节点已经是最大的了，  
		//所以上面的需要先从底层的非叶节点层开始维护/调整堆。  
		HeapAdjust(a, 1, size);
	}
	//至此数组就已经从小到大排好序了,  
	//如果要从大到小输出，则倒着输出就行了；  
	//而如果要将序列从大到小排序，则应建立最小堆。  
}

void print(int a[], int size)
{
	for (int i = 1; i < size; i++)
		cout << a[i] << " ";
	cout << a[size] << endl;
}

int main()
{
	int a[7] = {16, 7, 3,20, 17, 8};
	cout << "排序之前的序列为：" << endl;
	print(a, 6);
	HeapSort(a, 6);
	cout << "排序之后的序列为：" << endl;
	print(a, 6);
	system("pause");
	return 0;
}