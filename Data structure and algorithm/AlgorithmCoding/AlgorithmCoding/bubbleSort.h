#pragma once
#include <iostream>
#include "SortTestHelper.h"

using namespace std;
using namespace SortTestHelper;

/************************************************************************/
// 冒泡排序
/************************************************************************/

namespace BubbleSort
{
	// 第一版bubbleSort
	template<typename T>
	void bubbleSort(T arr[], int n)
	{
		if (n <= 1)
		{
			return;
		}

		for (int i = 0; i < n; ++i)
		{
			// 提前推出冒泡排序的标志位
			bool flag = false;
			for (int j = 0; j < n-i-1; ++j)
			{
				if (arr[j] > arr[j+1])
				{
					swap(arr[j], arr[j+1]);
					flag = true;  // 表示有数据交换
				}
			}

			if (!flag)
			{
				break;  // 没有数据交换，提前退出
			}
		}
	}

	// 第二版bubbleSort,使用newn进行优化，实际测试表明优化后的性能确实比第一版好
	template<typename T>
	void bubbleSort2(T arr[], int n)
	{
		if (n <= 1)
		{
			return;
		}

		int newn;  // 使用newn进行优化
		do 
		{
			newn = 0;
			for (int i = 1; i < n; ++i)
			{
				if (arr[i-1] > arr[i])
				{
					swap(arr[i - 1], arr[i]);

					// 记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
					newn = i;
				}
			}
			n = newn;
		} while (newn > 0);
	}

	// 测试
	void test_func()
	{
		int n = 20000;

		// 测试1 一般测试
		cout << "Test for random array, size = " << n << ", randome range [0, " << n << "]" << endl;
		int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
		int* arr2 = SortTestHelper::copyIntArray(arr1, n);

		SortTestHelper::testSort("bubbleSort1", bubbleSort, arr1, n);
		SortTestHelper::testSort("bubbleSort2", bubbleSort2, arr2, n);

		delete[] arr1;
		delete[] arr2;

		cout << endl;

		// 测试2 测试近乎有序的数组
		int swapTimes = 100;

		cout << "Test for nNearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
		arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
		arr2 = SortTestHelper::copyIntArray(arr1, n);

		SortTestHelper::testSort("bubbleSort1", bubbleSort, arr1, n);
		SortTestHelper::testSort("bubbleSort2", bubbleSort2, arr2, n);

		delete[] arr1;
		delete[] arr2;

		cout << endl;

		// 测试3 测试完全有序的数组
		// 对于完全有序的数组，冒泡排序法也将成为O(n)级别的算法
		swapTimes = 0;
		n = 10000000;   // 所以我们的测试数据规模变大，为1000,0000
		cout << "Test for ordered array, size = " << n << endl;

		arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
		arr2 = SortTestHelper::copyIntArray(arr1, n);

		SortTestHelper::testSort("bubbleSort1", bubbleSort, arr1, n);
		SortTestHelper::testSort("bubbleSort2", bubbleSort2, arr2, n);

		delete[] arr1;
		delete[] arr2;
	}
}