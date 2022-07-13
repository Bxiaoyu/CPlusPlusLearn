#pragma once
#include <iostream>

using namespace std;

/*
	二分查找算法
	- 在有序数组arr中，查找target
	- 如果找到target，返回相应的索引index
	- 如果没有找到target，返回-1
*/

namespace BinarySearch
{
	// 非递归实现方法
	template<typename T>
	int binarySearch(T arr[], int n, T target)
	{
		// 在arr[l...r]之中查找target
		int l = 0, r = n - 1;
		while (l <= r)
		{
			int mid = (r - l) / 2 + l;
			if (arr[mid] == target)
			{
				return mid;
			}
			// 在arr[l...r-1]之中查找target
			else if (target < arr[mid])
			{
				r = mid - 1;
			}
			else  // target > arr[mid]，在arr[mid + 1...r]之中查找target
			{
				l = mid + 1;
			}
		}

		return -1;
	}

	// 递归实现
	template<class T>
	int binarySearch2(T arr[], int n, T target)
	{
		return __binarySearch2(arr, 0, n - 1, target);
	}

	template<class T>
	int __binarySearch2(T arr[], int low, int high, T target)
	{
		if (low > high)
		{
			return -1;
		}
		//int mid = low + ((high - low) >> 1);
		int mid = low + (high - low) / 2;
		if (arr[mid] == target)
		{
			return mid;
		}
		else if (arr[mid] < target)
		{
			return __binarySearch2(arr, mid + 1, high, target);
		}
		else  // arr[mid] > target
		{
			return __binarySearch2(arr, low, mid - 1, target);
		}
	}

	/*
		二分查找几个典型的变体问题
		1.查找第一个值等于给定值的元素
		2.查找最后一个值等于给定值的元素
		3.查找第一个大于等于给定值的元素
		4.查找最后一个小于等于给定值的元素
	*/

	// 1.查找第一个值等于给定值的元素
	template<class T>
	int binarySearch_firstEqual(T arr[], int n, T target)
	{
		int low = 0;
		int high = n - 1;

		while (low <= high)
		{
			int mid = low + ((high - low) >> 1);
			if (arr[mid] > target)
			{
				high = mid - 1;
			}
			else if (arr[mid] < target)
			{
				low = mid + 1;
			}
			else  // arr[mid] == target
			{
				// 如果 mid 等于 0，那这个元素已经是数组的第一个元素，那它肯定是我们要找的；如果 mid 不等于 0，
				// 但 a[mid]的前一个元素 a[mid-1]不等于 target，那也说明 a[mid]就是我们要找的第一个值等于给定值的元素。
				if ((mid == 0) || (arr[mid-1] != target))
				{
					return mid;
				}
				else // 如果不是，那我们就更新 high=mid-1，因为要找的元素肯定出现在[low, mid-1]之间。
				{
					high = mid - 1;
				}
			}
		}

		return -1;
	}

	// 2.查找最后一个值等于给定值的元素
	template<class T>
	int binarySearch_lastEqual(T arr[], int n, T target)
	{
		int low = 0;
		int high = n - 1;

		while (low <= high)
		{
			int mid = low + ((high - low) >> 1);
			if (arr[mid] > target)
			{
				high = mid - 1;
			}
			else if (arr[mid] < target)
			{
				low = mid + 1;
			}
			else  // arr[mid] == target
			{
				// 如果 mid 等于 n-1，那这个元素已经是数组的最后一个元素，那它肯定是我们要找的；如果 mid 不等于 n-1，
				// 但 a[mid]的后一个元素 a[mid+1]不等于 target，那也说明 a[mid]就是我们要找的最后一个值等于给定值的元素。
				if ((mid == n-1) || (arr[mid + 1] != target))
				{
					return mid;
				}
				else  // 如果不是，那我们就更新 low=mid+1，因为要找的元素肯定出现在[mid+1, high]之间。
				{
					low = mid + 1;
				}
			}
		}

		return -1;
	}

	// 3.查找第一个大于等于给定值的元素
	template<class T>
	int binarySearch_firstGreateOrEqual(T arr[], int n, T target)
	{
		int low = 0;
		int high = n - 1;

		while (low <= high)
		{
			int mid = low + ((high - low) >> 1);
			// 对于 a[mid]大于等于给定值 target 的情况，我们要先看下这个 a[mid]是不是我们要找的第一个值大于等于给定值的元素。
			// 如果 a[mid]前面已经没有元素，或者前面一个元素小于要查找的值 target，那 a[mid]就是我们要找的元素。
			// 如果 a[mid - 1]也大于等于要查找的值 target，那说明要查找的元素在[low, mid - 1]之间，所以，我们将 high 更新为 mid - 1。
			if (arr[mid] >= target)
			{
				if ((mid == 0) || (arr[mid-1] < target))
				{
					return mid;
				}
				else
				{
					high = mid - 1;
				}
			}
			else  // arr[mid] < target
			{// 如果 a[mid]小于要查找的值 target，那要查找的值肯定在[mid+1, high]之间，所以，我们更新 low=mid+1。
				low = mid + 1;
			}
		}
		return -1;
	}

	// 4.查找最后一个小于等于给定值的元素
	template<class T>
	int binarySearch_lastLessOrEqual(T arr[], int n, T target)
	{
		int low = 0;
		int high = n - 1;

		while (low <= high)
		{
			int mid = low + ((high - low) >> 1);
			if (arr[mid] > target)
			{
				high = mid - 1;
			}
			else  // arr[mid] <= target
			{
				if ((mid == n-1) || (arr[mid+1] > target))
				{
					return mid;
				}
				else
				{
					low = mid + 1;
				}
			}
		}
		return -1;
	}
}
