#pragma once
#include <iostream>
#include "insertionSort.h"
#include "bubbleSort.h"
#include "selectionSort.h"
#include "SortTestHelper.h"

using namespace std;
using namespace BubbleSort;
using namespace InsertionSort;
using namespace SelectionSort;
using namespace SortTestHelper;

/************************************************************************/
// œ£∂˚≈≈–Ú
/************************************************************************/

namespace ShellSort
{
	template<typename T>
	void shellSort(T arr[], int n)
	{
		// º∆À„ increment sequence: 1, 4, 13, 40, 121, 364, 1093
		int h = 1;
		while (h < n / 3)
		{
			h = 3 * h + 1;
		}

		while (h >= 1)
		{
			// h-sort the array
			for (int i = h; i < n; ++i)
			{
				// ∂‘ arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]...  π”√≤Â»Î≈≈–Ú
				T e = arr[i];
				int j;
				for (j = i; j >= h && e < arr[j-h]; j-=h)
				{
					arr[j] = arr[j - h];
				}
				arr[j] = e;
			}
			h /= 3;
		}
	}

	// ≤‚ ‘
	void test_func()
	{
		int n = 20000;

		// ≤‚ ‘1 “ª∞„≤‚ ‘
		cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
		int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
		int* arr2 = SortTestHelper::copyIntArray(arr1, n);
		int* arr3 = SortTestHelper::copyIntArray(arr1, n);
		int* arr4 = SortTestHelper::copyIntArray(arr1, n);

		SortTestHelper::testSort("selectionSort", SelectionSort::selectionSort, arr1, n);
		SortTestHelper::testSort("insertionSort", InsertionSort::insertionSort, arr2, n);
		SortTestHelper::testSort("bubbleSort", BubbleSort::bubbleSort2, arr3, n);
		SortTestHelper::testSort("shellSort", shellSort, arr4, n);

		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
		delete[] arr4;

		cout << endl;

		// ≤‚ ‘2 ≤‚ ‘Ω¸∫ı”––Úµƒ ˝æ›
		int swapTimes = 100;
		cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
		arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
		arr2 = SortTestHelper::copyIntArray(arr1, n);
		arr3 = SortTestHelper::copyIntArray(arr1, n);
		arr4 = SortTestHelper::copyIntArray(arr1, n);

		SortTestHelper::testSort("selectionSort", SelectionSort::selectionSort, arr1, n);
		SortTestHelper::testSort("insertionSort", InsertionSort::insertionSort, arr2, n);
		SortTestHelper::testSort("bubbleSort", BubbleSort::bubbleSort2, arr3, n);
		SortTestHelper::testSort("shellSort", shellSort, arr4, n);

		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
		delete[] arr4;
	}
}