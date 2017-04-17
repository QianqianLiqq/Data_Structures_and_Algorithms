#pragma once
template<class T>
class MinHeap
{
	T * heapArray;//��Ŷ����ݵ�����
	int currentSize;//��ǰ����Ԫ�ص���Ŀ
	int maxSize;//���������ɵ����Ԫ�ص���Ŀ
	void buildHeap();//����
public:
	MinHeap(const int n);//���캯����n��ʾ��ʼ���Ե����Ԫ����Ŀ
	~MinHeap(){
		delete[]heapArray;
	}
	//�����Ҷ�ڵ㣬����true
	bool isLeaf(int pos)const{
		return (pos >= currentSize / 2) && (pos < currentSize);
	}
	//�������ӵ�λ��
	int leftchild(int pos)const{
		return 2 * pos + 1;
	}
	//�����Һ��ӵ�λ��
	int rightchild(int pos)const{
		return 2 * pos + 2;
	}
	//���ظ��ڵ��λ��
	int parent(int pos)const{
		return (pos - 1) / 2;
	}
	//ɾ�������±��Ԫ��
	bool Remove(int pos, T & node);
	//����в�����Ԫ��
	bool Insert(const T&newNode);
	//�Ӷ���ɾ����Сֵ
	T& RemoveMin();
	//��position���Ͽ�ʼ������ʹ���г�Ϊ��
	void SiftUp(int position);
	//ɸѡ������������left��ʾ��ʼ����������±�
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
	int i = position;//��ʶ���ڵ�
	int j = 2 * i + 1;//��ʶ�ؼ�ֵ��С���ӽڵ�
	T temp = heapArray[i];//���游�ڵ�
	//��ɸ
	while (j < currentSize){
		if ((j<currentSize - 1) && (heapArray[j]>heapArray[j + 1]))
			++j;
		if (temp > heapArray[j]){
			heapArray[i] = heapArray[j];
			i = j;
			j = 2 * j + 1;//��������
		}
		else
			break;
	}
	heapArray[i] = temp;
}
template<class T>
void MinHeap<T>::buildHeap(){
	//��������ɸѡ����
	for (int i = currentSize / 2 - 1; i >= 0; --i)
		SiftDown(i);
}
template<class T>
void MinHeap<T>::SiftUp(int position){
	//��position���Ͽ�ʼ������ʹ���г�Ϊ��
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
	SiftDown(pos);//SiftUp��SiftDown��ʵ�Ƕ���һ��
	node = temp;
	return true;
}
