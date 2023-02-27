#pragma once
#include <iostream>
#include "SortTestHelper.h"

using namespace std;
using namespace SortTestHelper;

/************************************************************************/
// 插入排序
/************************************************************************/

namespace InsertionSort
{
	template<typename T>
	void insertionSort(T arr[], int n)
	{
		if (n <= 1)
		{
			return;
		}

		for (int i = 1; i < n; ++i)
		{
			T e = arr[i];
			int j;  // j保存元素e应该插入的位置
			// 查找插入位置,从尾到头遍历
			for (j = i; j > 0 && arr[j-1] > e; --j)
			{
				arr[j] = arr[j-1];  // 数据移动
			}
			arr[j] = e;
		}
	}

	// 改版，对arr[l...r]范围的数组进行插入排序
	template<typename T>
	void insertionSort2(T arr[], int l, int r)
	{
		for (int i = l + 1; i <= r; ++i)
		{
			T e = arr[i];
			int j;
			for (j = i; j > l && arr[j-1] > e; --j)
			{
				arr[j] = arr[j - 1];
			}
			arr[j] = e;
		}
	}

	// 测试
	void test_func()
	{
		int n = 20000;

		// 测试1 一般测试
		cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
		int* arr = SortTestHelper::generateRandomArray(n, 0, n);

		SortTestHelper::testSort("insertionSort", insertionSort, arr, n);

		delete[] arr;

		cout << endl;

		// 测试2 有序性更强的测试
		cout << "Test for more ordered random array, size = " << n << ", random range [0, 3]" << endl;
		arr = SortTestHelper::generateRandomArray(n, 0, 3);

		SortTestHelper::testSort("insertionSort", insertionSort, arr, n);

		delete[] arr;

		cout << endl;

		// 测试3 测试近乎有序的数组
		int swapTimes = 100;
		cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
		arr = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);

		SortTestHelper::testSort("insertionSort", insertionSort, arr, n);

		delete[] arr;
	}
}