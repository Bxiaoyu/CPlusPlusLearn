#pragma once
#include <iostream>
#include "SortTestHelper.h"

using namespace std;
using namespace SortTestHelper;

/************************************************************************/
// ��������
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
			int j;  // j����Ԫ��eӦ�ò����λ��
			// ���Ҳ���λ��,��β��ͷ����
			for (j = i; j > 0 && arr[j-1] > e; --j)
			{
				arr[j] = arr[j-1];  // �����ƶ�
			}
			arr[j] = e;
		}
	}

	// �İ棬��arr[l...r]��Χ��������в�������
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

	// ����
	void test_func()
	{
		int n = 20000;

		// ����1 һ�����
		cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
		int* arr = SortTestHelper::generateRandomArray(n, 0, n);

		SortTestHelper::testSort("insertionSort", insertionSort, arr, n);

		delete[] arr;

		cout << endl;

		// ����2 �����Ը�ǿ�Ĳ���
		cout << "Test for more ordered random array, size = " << n << ", random range [0, 3]" << endl;
		arr = SortTestHelper::generateRandomArray(n, 0, 3);

		SortTestHelper::testSort("insertionSort", insertionSort, arr, n);

		delete[] arr;

		cout << endl;

		// ����3 ���Խ������������
		int swapTimes = 100;
		cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
		arr = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);

		SortTestHelper::testSort("insertionSort", insertionSort, arr, n);

		delete[] arr;
	}
}