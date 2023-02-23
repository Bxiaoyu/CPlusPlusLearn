#pragma once
#include <iostream>
#include "SortTestHelper.h"

using namespace std;
using namespace SortTestHelper;

/************************************************************************/
// ð������
/************************************************************************/

namespace BubbleSort
{
	// ��һ��bubbleSort
	template<typename T>
	void bubbleSort(T arr[], int n)
	{
		if (n <= 1)
		{
			return;
		}

		for (int i = 0; i < n; ++i)
		{
			// ��ǰ�Ƴ�ð������ı�־λ
			bool flag = false;
			for (int j = 0; j < n-i-1; ++j)
			{
				if (arr[j] > arr[j+1])
				{
					swap(arr[j], arr[j+1]);
					flag = true;  // ��ʾ�����ݽ���
				}
			}

			if (!flag)
			{
				break;  // û�����ݽ�������ǰ�˳�
			}
		}
	}

	// �ڶ���bubbleSort,ʹ��newn�����Ż���ʵ�ʲ��Ա����Ż��������ȷʵ�ȵ�һ���
	template<typename T>
	void bubbleSort2(T arr[], int n)
	{
		if (n <= 1)
		{
			return;
		}

		int newn;  // ʹ��newn�����Ż�
		do 
		{
			newn = 0;
			for (int i = 1; i < n; ++i)
			{
				if (arr[i-1] > arr[i])
				{
					swap(arr[i - 1], arr[i]);

					// ��¼���һ�εĽ���λ��,�ڴ�֮���Ԫ������һ��ɨ���о�������
					newn = i;
				}
			}
			n = newn;
		} while (newn > 0);
	}

	// ����
	void test_func()
	{
		int n = 20000;

		// ����1 һ�����
		cout << "Test for random array, size = " << n << ", randome range [0, " << n << "]" << endl;
		int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
		int* arr2 = SortTestHelper::copyIntArray(arr1, n);

		SortTestHelper::testSort("bubbleSort1", bubbleSort, arr1, n);
		SortTestHelper::testSort("bubbleSort2", bubbleSort2, arr2, n);

		delete[] arr1;
		delete[] arr2;

		cout << endl;

		// ����2 ���Խ������������
		int swapTimes = 100;

		cout << "Test for nNearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
		arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
		arr2 = SortTestHelper::copyIntArray(arr1, n);

		SortTestHelper::testSort("bubbleSort1", bubbleSort, arr1, n);
		SortTestHelper::testSort("bubbleSort2", bubbleSort2, arr2, n);

		delete[] arr1;
		delete[] arr2;

		cout << endl;

		// ����3 ������ȫ���������
		// ������ȫ��������飬ð������Ҳ����ΪO(n)������㷨
		swapTimes = 0;
		n = 10000000;   // �������ǵĲ������ݹ�ģ���Ϊ1000,0000
		cout << "Test for ordered array, size = " << n << endl;

		arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
		arr2 = SortTestHelper::copyIntArray(arr1, n);

		SortTestHelper::testSort("bubbleSort1", bubbleSort, arr1, n);
		SortTestHelper::testSort("bubbleSort2", bubbleSort2, arr2, n);

		delete[] arr1;
		delete[] arr2;
	}
}