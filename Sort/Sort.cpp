// Sort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SortTestHelper.h"
#include "student.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Heap.h"

template <typename T>
void heapSprt2(T arr[], int n) {
	MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);
	for (int i = 0; i < n; i++)
		maxHeap.insert(arr[i]);
	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxHeap.extractMax();
}

template <typename T>
void heapSort1(T arr[], int n) {
	MaxHeap<T> maxHeap = MaxHeap<T>(arr, n);
	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxHeap.extractMax();
}

int main()
{
	MaxHeap<int> maxHeap = MaxHeap<int>(100);
	srand(time(NULL));
	for (int i = 0; i < 50; i++) {
		maxHeap.insert(rand() % 100);
	}
	while (!maxHeap.isEmpty())
	{
		cout<<maxHeap.extractMax()<<" ";
	}
	system("pause");
	return 0;
}

