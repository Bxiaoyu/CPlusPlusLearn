#pragma once
#include <iostream>
#include "SortTestHelper.h"

using namespace std;
using namespace SortTestHelper;

/************************************************************************/
// 选择排序
/************************************************************************/

namespace SelectionSort
{
	// 最基础的排序算法
	template<typename T>
	void selectionSort(T arr[], int n)
	{
		if (n <= 1)
		{
			return;
		}

		for (int i = 0; i < n; ++i)
		{
			int minIndex = i;
			for (int j = i+1; j < n; ++j)
			{
				if (arr[j] < arr[minIndex])
				{
					minIndex = j;
				}
			}
			swap(arr[i], arr[minIndex]);
		}
	}

	// 测试
	void test_func()
	{
		int n = 20000;

		// 测试1 一般测试
		cout << "Test for random array, size = " << n << ", randome range [0, " << n << "]" << endl;
		int* arr = SortTestHelper::generateRandomArray(n, 0, n);

		SortTestHelper::testSort("selectionSort", selectionSort, arr, n);

		delete[] arr;

		// 测试2 测试近乎有序的数组
		int swapTimes = 100;

		cout << "Test for nNearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
		arr = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);

		SortTestHelper::testSort("selectionSort", selectionSort, arr, n);

		delete[] arr;

		// 测试3 测试完全有序的数组
		swapTimes = 0;
		n = 100000;    // 所以我们的测试数据规模变大，为1000,0000
		cout << "Test for ordered array, size = " << n << endl;
		arr = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);

		SortTestHelper::testSort("selectionSort", selectionSort, arr, n);

		delete[] arr;
	}
}