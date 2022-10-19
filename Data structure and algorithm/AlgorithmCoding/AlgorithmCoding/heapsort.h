#pragma once
#include "maxheap.h"
#include "indexheap.h"

template<class T>
void heapSort1(T arr[], int n)
{
	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for (int i = 0; i < n; i++)
	{
		maxheap.insert(arr[i]);
	}

	for (int i = n - 1; i >= 0; i--)  // 反向操作输出从小到大的排序结果
	{
		arr[i] = maxheap.extractMax();
	}
}

template<class T>
void heapSort2(T arr[], int n)
{
	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
	for (int i = n - 1; i >= 0; i--)
	{
		arr[i] = maxheap.extractMax();
	}
}

template<class T>
void heapSort3(T arr[], int n)
{
	IndexMaxHeap<T> maxheap = IndexMaxHeap<T>(n);
	for (int i = 0; i < n; i++)
	{
		maxheap.insert(i, arr[i]);
	}
	for (int i = n-1; i >= 0; i--)
	{
		arr[i] = maxheap.extractMax();
	}
}