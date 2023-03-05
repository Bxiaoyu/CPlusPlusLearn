#pragma once
#include <iostream>
#include <algorithm>
#include <ctime>
#include "SortTestHelper.h"
#include "insertionSort.h"
#include "mergeSort.h"

using namespace std;
using namespace SortTestHelper;
using namespace InsertionSort;
using namespace MergeSort;

/************************************************************************/
// ��������
/************************************************************************/

namespace QuickSort
{
	////////////////////////////////1.ͨ��д��//////////////////////////////////////////
	// ��arr[l...r]���ֽ���partition����
	// ����p, ʹ��arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
	template<typename T>
	int __partition(T arr[], int l, int r)
	{
		// ѡ���һ����ֵ��Ϊ�궨��pivot
		T v = arr[l];
		int j = l;  // arr[l+1...j] < v ; arr[j+1...i) > v
		for (int i = l + 1; i <= r; ++i)
		{
			if (arr[i] < v)
			{
				j++;
				swap(arr[j], arr[i]);
			}
		}

		swap(arr[l], arr[j]);

		return j;
	}

	// ��arr[l...r]���ֽ��п�������
	template<typename T>
	void __quickSort(T arr[], int l, int r)
	{
		if (l >= r)
		{
			return;
		}

		int p = __partition(arr, l, r);
		__quickSort(arr, l, p - 1);
		__quickSort(arr, p + 1, r);
	}

	template<typename T>
	void quickSort(T arr[], int n)
	{
		__quickSort(arr, 0, n - 1);
	}

	//////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////2.�ò��������Ż�/////////////////////////////////////////
	// ��arr[l...r]���ֽ���partition����
	// ����p, ʹ��arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
	template<typename T>
	int __partition2(T arr[], int l, int r)
	{
		// �����arr[l...r]�ķ�Χ��, ѡ��һ����ֵ��Ϊ�궨��pivot
		swap(arr[l], arr[rand() % (r - l + 1) + l]);

		T v = arr[l];
		int j = l;
		for (int i = l + 1; i <= r; ++i)
		{
			if (arr[i] < v)
			{
				j++;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[l], arr[j]);

		return j;
	}

	// ��arr[l...r]���ֽ��п�������
	template<typename T>
	void __quickSort2(T arr[], int l, int r)
	{
		if (r - l <= 15)
		{
			InsertionSort::insertionSort2(arr, l, r);
			return;
		}

		int p = __partition2(arr, l, r);
		__quickSort2(arr, l, p - 1);
		__quickSort2(arr, p + 1, r);
	}

	template<typename T>
	void quickSort2(T arr[], int n)
	{
		srand(time(NULL));
		__quickSort2(arr, 0, n - 1);
	}
	///////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////3.˫·����/////////////////////////////////////////////
	// ˫·���������partition
	// ����p, ʹ��arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
	template<typename T>
	int __partition2Way(T arr[], int l, int r)
	{
		// �����arr[l...r]�ķ�Χ��, ѡ��һ����ֵ��Ϊ�궨��pivot
		swap(arr[l], arr[rand() % (r - l + 1) + l]);
		T v = arr[l];

		// arr[l+1...i) <= v; arr(j...r] >= v
		int i = l + 1;
		int j = r;

		while (true)
		{
			// ע������ı߽�, arr[i] < v, ������arr[i] <= v
			while (i <= r && arr[i] < v)
			{
				i++;
			}

			// ע������ı߽�, arr[j] > v, ������arr[j] >= v
			while (j >= l + 1 && arr[j] > v)
			{
				j--;
			}

			if (i > j)
			{
				break;
			}

			swap(arr[i], arr[j]);
			i++;
			j--;
		}

		swap(arr[l], arr[j]);

		return j;
	}

	// ��arr[l...r]���ֽ��п�������
	template<typename T>
	void __quickSort2Way(T arr[], int l, int r)
	{
		// ����С��ģ����, ʹ�ò�����������Ż�
		if (r - l <= 15)
		{
			InsertionSort::insertionSort2(arr, l, r);
			return;
		}

		// ����˫·���������partition
		int p = __partition2Way(arr, l, r);
		__quickSort2Way(arr, l, p - 1);
		__quickSort2Way(arr, p + 1, r);
	}

	// ˫·��������
	template<typename T>
	void quickSort2Way(T arr[], int n)
	{
		srand(time(NULL));
		__quickSort2Way(arr, 0, n - 1);
	}
	//////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////4.��·����/////////////////////////////////////////////
	// �ݹ����·���������㷨
	template<typename T>
	void __quickSort3Way(T arr[], int l, int r)
	{
		// ����С��ģ���飬���ò�����������Ż�
		if (r - l <= 15)
		{
			InsertionSort::insertionSort2(arr, l, r);
			return;
		}

		// �����arr[l...r]�ķ�Χ��, ѡ��һ����ֵ��Ϊ�궨��pivot
		swap(arr[l], arr[rand() % (r - l + 1) + l]);

		T v = arr[l];

		int lt = l;      // arr[l+1...lt] < v
		int gt = r + 1;  // arr[gt...r] > v
		int i = l + 1;   // arr[lt+1...i] == v

		while (i < gt)
		{
			if (arr[i] < v)
			{
				swap(arr[i], arr[lt + 1]);
				i++;
				lt++;
			}
			else if (arr[i] > v)
			{
				swap(arr[i], arr[gt - 1]);
				gt--;
			}
			else  // arr[i] == v
			{
				i++;
			}
		}

		swap(arr[l], arr[lt]);

		__quickSort3Way(arr, l, lt - 1);
		__quickSort3Way(arr, gt, r);
	}

	template<typename T>
	void quickSort3Way(T arr[], int n)
	{
		srand(time(NULL));
		__quickSort3Way(arr, 0, n - 1);
	}
	//////////////////////////////////////////////////////////////////////////////////////

	// ����
	void test_func()
	{
		int n = 1000000;

		// ����1 һ���Բ���
		std::cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
		int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
		int* arr2 = SortTestHelper::copyIntArray(arr1, n);
		int* arr3 = SortTestHelper::copyIntArray(arr1, n);
		int* arr4 = SortTestHelper::copyIntArray(arr1, n);
		int* arr5 = SortTestHelper::copyIntArray(arr1, n);

		SortTestHelper::testSort("mergeSort", MergeSort::mergeSort2, arr1, n);
		SortTestHelper::testSort("quickSort", quickSort, arr2, n);
		SortTestHelper::testSort("quickSort2", quickSort2, arr3, n);
		SortTestHelper::testSort("quickSort2Way", quickSort2Way, arr4, n);
		SortTestHelper::testSort("quickSort3Way", quickSort3Way, arr5, n);

		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
		delete[] arr4;
		delete[] arr5;
		std::cout << endl;

		// ����2 ���Խ������������
		int swapTimes = 100;
		std::cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
		arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
		arr2 = SortTestHelper::copyIntArray(arr1, n);
		arr3 = SortTestHelper::copyIntArray(arr1, n);
		arr4 = SortTestHelper::copyIntArray(arr1, n);
		arr5 = SortTestHelper::copyIntArray(arr1, n);

		SortTestHelper::testSort("mergeSort", MergeSort::mergeSort2, arr1, n);
		// �ڰ��������ظ�Ԫ�ص������, QuickSort���˻���O(n ^ 2)�㷨, �����ﲻ��ִ��
		//SortTestHelper::testSort("quickSort", quickSort, arr2, n);
		//SortTestHelper::testSort("quickSort2", quickSort2, arr3, n);
		SortTestHelper::testSort("quickSort2Way", quickSort2Way, arr4, n);
		SortTestHelper::testSort("quickSort3Way", quickSort3Way, arr5, n);

		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
		delete[] arr4;
		delete[] arr5;
		std::cout << endl;

		// ����3 ���Դ��ڰ���������ͬԪ�ص�����
		std::cout << "Test for random array, size = " << n << ", random range [0,10]" << endl;
		arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
		arr2 = SortTestHelper::copyIntArray(arr1, n);
		arr3 = SortTestHelper::copyIntArray(arr1, n);
		arr4 = SortTestHelper::copyIntArray(arr1, n);
		arr5 = SortTestHelper::copyIntArray(arr1, n);

		SortTestHelper::testSort("mergeSort", MergeSort::mergeSort2, arr1, n);
		// �ڰ��������ظ�Ԫ�ص������, QuickSort���˻���O(n^2)�㷨, �����ﲻ��ִ��
		//SortTestHelper::testSort("quickSort", quickSort, arr2, n);
		//SortTestHelper::testSort("quickSort2", quickSort2, arr3, n);
		SortTestHelper::testSort("quickSort2Way", quickSort2Way, arr4, n);
		SortTestHelper::testSort("quickSort3Way", quickSort3Way, arr5, n);

		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
		delete[] arr4;
		delete[] arr5;
		std::cout << endl;
	}
}