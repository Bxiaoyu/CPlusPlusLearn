#pragma once
#include <iostream>
#include "SortTestHelper.h"

using namespace std;
using namespace SortTestHelper;

/************************************************************************/
// ѡ������
/************************************************************************/

namespace SelectionSort
{
	// ������������㷨
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

	// ����
	void test_func()
	{
		int n = 20000;

		// ����1 һ�����
		cout << "Test for random array, size = " << n << ", randome range [0, " << n << "]" << endl;
		int* arr = SortTestHelper::generateRandomArray(n, 0, n);

		SortTestHelper::testSort("selectionSort", selectionSort, arr, n);

		delete[] arr;

		// ����2 ���Խ������������
		int swapTimes = 100;

		cout << "Test for nNearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
		arr = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);

		SortTestHelper::testSort("selectionSort", selectionSort, arr, n);

		delete[] arr;

		// ����3 ������ȫ���������
		swapTimes = 0;
		n = 100000;    // �������ǵĲ������ݹ�ģ���Ϊ1000,0000
		cout << "Test for ordered array, size = " << n << endl;
		arr = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);

		SortTestHelper::testSort("selectionSort", selectionSort, arr, n);

		delete[] arr;
	}
}