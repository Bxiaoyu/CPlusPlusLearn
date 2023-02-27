#pragma once
#include <iostream>
#include <cassert>
#include "SortTestHelper.h"
#include "insertionSort.h"

using namespace std;
using namespace SortTestHelper;
using namespace InsertionSort;

/************************************************************************/
// �鲢����
/************************************************************************/

namespace MergeSort
{
	template<typename T>
	void __merge(T arr[], int l, int mid, int r)
	{
		// ����һ����ʱ����
		//T aux[r - l + 1];  // ע��һЩ�ϵ�VS��������֧�ֶ�̬�������飬������new�ķ�ʽ�����ڴ棬���ǵú�������ʱ�ͷ��ڴ�
		T* aux = new T[r - l + 1];

		for (int i = l; i <= r; ++i)
		{
			aux[i - l] = arr[i];
		}

		// ��ʼ����iָ����벿����ʼλ������l��jָ���Ұ벿����ʼλ������mid+1
		int i = l, j = mid + 1;
		for (int k = l; k <= r; ++k)
		{
			if (i > mid)  // �������Ԫ���Ѿ���ȫ�������
			{
				arr[k] = aux[j - l];
				j++;
			}
			else if (j > r)  // ����Ұ��Ԫ���Ѿ���ȫ�������
			{
				arr[k] = aux[i - l];
				i++;
			}
			else if (aux[i-l] < aux[j-l])  // ������ָԪ�� < �Ұ����ָԪ��
			{
				arr[k] = aux[i - l];
				i++;
			}
			else  // ������ָԪ�� >= �Ұ����ָԪ��
			{
				arr[k] = aux[j - l];
				j++;
			}
		}

		delete[] aux;
	}

	// һ��д��
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

	// ʹ���Ż��Ĺ鲢�����㷨, ��arr[l...r]�ķ�Χ��������
	template<typename T>
	void __mergeSort2(T arr[], int l, int r)
	{
		// �Ż�2: ����С��ģ����, ʹ�ò�������
		if (r - l <= 15)
		{
			InsertionSort::insertionSort2(arr, l, r);
			return;
		}

		int mid = (r - l) / 2 + l;
		__mergeSort2(arr, l, mid);
		__mergeSort2(arr, mid + 1, r);

		// �Ż�1: ����arr[mid] <= arr[mid+1]�����,������merge
		// ���ڽ������������ǳ���Ч,���Ƕ���һ�����,��һ����������ʧ
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


	///////////////////////////////////����///////////////////////////////////////
	void test_func()
	{
		int n = 50000;
		// ����1 һ���Բ���
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

		// ����2 ���Խ������������
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