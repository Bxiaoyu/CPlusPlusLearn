#pragma once
#include <iostream>
#include <cassert>
#include "SortTestHelper.h"
#include "insertionSort.h"

using namespace std;
using namespace SortTestHelper;
using namespace InsertionSort;

/************************************************************************/
// 归并排序
/************************************************************************/

namespace MergeSort
{
	template<typename T>
	void __merge(T arr[], int l, int mid, int r)
	{
		// 开辟一个临时数组
		//T aux[r - l + 1];  // 注意一些老的VS编译器不支持动态长度数组，可以用new的方式申请内存，但记得函数结束时释放内存
		T* aux = new T[r - l + 1];

		for (int i = l; i <= r; ++i)
		{
			aux[i - l] = arr[i];
		}

		// 初始化，i指向左半部分起始位置索引l，j指向右半部分起始位置索引mid+1
		int i = l, j = mid + 1;
		for (int k = l; k <= r; ++k)
		{
			if (i > mid)  // 如果左半边元素已经完全处理完毕
			{
				arr[k] = aux[j - l];
				j++;
			}
			else if (j > r)  // 如果右半边元素已经完全处理完毕
			{
				arr[k] = aux[i - l];
				i++;
			}
			else if (aux[i-l] < aux[j-l])  // 左半边所指元素 < 右半边所指元素
			{
				arr[k] = aux[i - l];
				i++;
			}
			else  // 左半边所指元素 >= 右半边所指元素
			{
				arr[k] = aux[j - l];
				j++;
			}
		}

		delete[] aux;
	}

	// 一般写法
	template<typename T>
	void __mergeSort(T arr[], int l, int r)
	{
		if (l >= r)
		{
			return;
		}

		int mid = (r - l) / 2 + l;
		__mergeSort(arr, l, mid);
		__mergeSort(arr, mid + 1, r);

		__merge(arr, l, mid, r);
	}

	// 使用优化的归并排序算法, 对arr[l...r]的范围进行排序
	template<typename T>
	void __mergeSort2(T arr[], int l, int r)
	{
		// 优化2: 对于小规模数组, 使用插入排序
		if (r - l <= 15)
		{
			InsertionSort::insertionSort2(arr, l, r);
			return;
		}

		int mid = (r - l) / 2 + l;
		__mergeSort2(arr, l, mid);
		__mergeSort2(arr, mid + 1, r);

		// 优化1: 对于arr[mid] <= arr[mid+1]的情况,不进行merge
		// 对于近乎有序的数组非常有效,但是对于一般情况,有一定的性能损失
		if (arr[mid] > arr[mid+1])
		{
			__merge(arr, l, mid, r);
		}
	}

	template<typename T>
	void mergeSort(T arr[], int n)
	{
		__mergeSort(arr, 0, n - 1);
	}

	template<typename T>
	void mergeSort2(T arr[], int n)
	{
		__mergeSort2(arr, 0, n - 1);
	}


	///////////////////////////////////测试///////////////////////////////////////
	void test_func()
	{
		int n = 50000;
		// 测试1 一般性测试
		cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
		int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
		int* arr2 = SortTestHelper::copyIntArray(arr1, n);
		int* arr3 = SortTestHelper::copyIntArray(arr1, n);

		SortTestHelper::testSort("insertionSort", InsertionSort::insertionSort, arr1, n);
		SortTestHelper::testSort("mergeSort", mergeSort, arr2, n);
		SortTestHelper::testSort("mergeSort2", mergeSort2, arr3, n);

		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
		cout << endl;

		// 测试2 测试近乎有序的数组
		int swapTimes = 10;
		assert(swapTimes >= 0);

		cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
		arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
		arr2 = SortTestHelper::copyIntArray(arr1, n);
		arr3 = SortTestHelper::copyIntArray(arr1, n);

		SortTestHelper::testSort("insertionSort", InsertionSort::insertionSort, arr1, n);
		SortTestHelper::testSort("mergeSort1", mergeSort, arr2, n);
		SortTestHelper::testSort("mergeSort2", mergeSort2, arr3, n);

		delete[] arr1;
		delete[] arr2;
		delete[] arr3;

		cout << endl;
	}
	/////////////////////////////////////////////////////////////////////////////

}