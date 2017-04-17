#pragma once
template<class T>
class MinHeap
{
	T * heapArray;//存放堆数据的数组
	int currentSize;//当前堆中元素的数目
	int maxSize;//堆所能容纳的最大元素的数目
	void buildHeap();//建堆
public:
	MinHeap(const int n);//构造函数，n表示初始化对的最大元素数目
	~MinHeap(){
		delete[]heapArray;
	}
	//如果是叶节点，返回true
	bool isLeaf(int pos)const{
		return (pos >= currentSize / 2) && (pos < currentSize);
	}
	//返回左孩子的位置
	int leftchild(int pos)const{
		return 2 * pos + 1;
	}
	//返回右孩子的位置
	int rightchild(int pos)const{
		return 2 * pos + 2;
	}
	//返回父节点的位置
	int parent(int pos)const{
		return (pos - 1) / 2;
	}
	//删除给定下标的元素
	bool Remove(int pos, T & node);
	//向堆中插入新元素
	bool Insert(const T&newNode);
	//从堆中删除最小值
	T& RemoveMin();
	//从position向上开始调整，使序列成为堆
	void SiftUp(int position);
	//筛选法函数，参数left表示开始处理的数组下标
	void SiftDown(int position);
};
template<class T>
MinHeap<T>::MinHeap(const int n){
	if (n <= 0)
		return;
	currentSize = 0;
	maxSize = n;
	heapArray = new T[maxSize];
	buildHeap();
}
template<class T>
void MinHeap<T>::SiftDown(int position){
	int i = position;//标识父节点
	int j = 2 * i + 1;//标识关键值较小的子节点
	T temp = heapArray[i];//保存父节点
	//过筛
	while (j < currentSize){
		if ((j<currentSize - 1) && (heapArray[j]>heapArray[j + 1]))
			++j;
		if (temp > heapArray[j]){
			heapArray[i] = heapArray[j];
			i = j;
			j = 2 * j + 1;//继续向下
		}
		else
			break;
	}
	heapArray[i] = temp;
}
template<class T>
void MinHeap<T>::buildHeap(){
	//反复调用筛选函数
	for (int i = currentSize / 2 - 1; i >= 0; --i)
		SiftDown(i);
}
template<class T>
void MinHeap<T>::SiftUp(int position){
	//从position向上开始调整，使序列成为堆
	int temppos = position;
	T temp = heapArray[temppos];
	while ((temppos > 0) && (heapArray[parent(temppos)] > temp)){
		heapArray[temppos] = heapArray[parent(temppos)];
		temppos = parent(temppos);
	}
	heapArray[temppos] = temp;
}
template<class T>
bool MinHeap<T>::Insert(const T&newNode){
	if (currentSize == maxSize)
		return false;
	heapArray[currentSize] = newNode;
	SiftUp(currentSize);
	currentSize++;
	return true; 
}
template<class T>
T& MinHeap<T>::RemoveMin(){
	if (currentSize == 0){
		cout << "can't delete";
		exit(1);
	}
	else{
		swap(heapArray[0], heapArray[--currentSize]);
		if (currentSize > 1)
			SiftDown(0);
		return heapArray[currentSize];
	}
}
template<class T>
bool MinHeap<T>::Remove(int pos, T & node){
	if ((pos < 0) || (pos >= currentSize))
		return false;
	T temp = heapArray[pos];
	heapArray[pos] = heapArray[--currentSize];
	SiftUp(pos);
	SiftDown(pos);//SiftUp和SiftDown其实是二择一的
	node = temp;
	return true;
}
