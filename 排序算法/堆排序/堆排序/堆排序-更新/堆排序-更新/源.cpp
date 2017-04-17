#include<iostream>

void SifeDown(int heapArray[], int position, int size){
	int i = position;
	int j = 2 * i + 1;
	int temp = heapArray[i];
	while (j < size){
		if (j<size - 1 && heapArray[j]>heapArray[j + 1])
			++j;
		if (temp > heapArray[j]){
			heapArray[i] = heapArray[j];
			i = j;
			j = 2 * j + 1;
		}
		else
			break;
	}
	heapArray[i] = temp;
}

void buildHeap(int heapArray[], int size){
	for (int i = size / 2 - 1; i >= 0; --i)
		SifeDown(heapArray, i, size);
}

void heapSort(int heapArray[], int size){
	buildHeap(heapArray, size);
	while (size > 0){
		int temp = heapArray[size - 1];
		heapArray[size - 1] = heapArray[0];
		heapArray[0] = temp;
		std::cout << heapArray[size - 1] << " " << std::endl;
		size--;
		SifeDown(heapArray, 0, size);
	}
}

int main(){
	int heapArray[7] = { 8, 13, 2, 9, 6, 10, 1 };
	heapSort(heapArray, 7);
	system("pause");
}