#pragma once
#include <iostream>

using namespace std;

/*
	���ֲ����㷨
	- ����������arr�У�����target
	- ����ҵ�target��������Ӧ������index
	- ���û���ҵ�target������-1
*/

namespace BinarySearch
{
	// �ǵݹ�ʵ�ַ���
	template<typename T>
	int binarySearch(T arr[], int n, T target)
	{
		// ��arr[l...r]֮�в���target
		int l = 0, r = n - 1;
		while (l <= r)
		{
			int mid = (r - l) / 2 + l;
			if (arr[mid] == target)
			{
				return mid;
			}
			// ��arr[l...r-1]֮�в���target
			else if (target < arr[mid])
			{
				r = mid - 1;
			}
			else  // target > arr[mid]����arr[mid + 1...r]֮�в���target
			{
				l = mid + 1;
			}
		}

		return -1;
	}

	// �ݹ�ʵ��
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
		���ֲ��Ҽ������͵ı�������
		1.���ҵ�һ��ֵ���ڸ���ֵ��Ԫ��
		2.�������һ��ֵ���ڸ���ֵ��Ԫ��
		3.���ҵ�һ�����ڵ��ڸ���ֵ��Ԫ��
		4.�������һ��С�ڵ��ڸ���ֵ��Ԫ��
	*/

	// 1.���ҵ�һ��ֵ���ڸ���ֵ��Ԫ��
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
				// ��� mid ���� 0�������Ԫ���Ѿ�������ĵ�һ��Ԫ�أ������϶�������Ҫ�ҵģ���� mid ������ 0��
				// �� a[mid]��ǰһ��Ԫ�� a[mid-1]������ target����Ҳ˵�� a[mid]��������Ҫ�ҵĵ�һ��ֵ���ڸ���ֵ��Ԫ�ء�
				if ((mid == 0) || (arr[mid-1] != target))
				{
					return mid;
				}
				else // ������ǣ������Ǿ͸��� high=mid-1����ΪҪ�ҵ�Ԫ�ؿ϶�������[low, mid-1]֮�䡣
				{
					high = mid - 1;
				}
			}
		}

		return -1;
	}

	// 2.�������һ��ֵ���ڸ���ֵ��Ԫ��
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
				// ��� mid ���� n-1�������Ԫ���Ѿ�����������һ��Ԫ�أ������϶�������Ҫ�ҵģ���� mid ������ n-1��
				// �� a[mid]�ĺ�һ��Ԫ�� a[mid+1]������ target����Ҳ˵�� a[mid]��������Ҫ�ҵ����һ��ֵ���ڸ���ֵ��Ԫ�ء�
				if ((mid == n-1) || (arr[mid + 1] != target))
				{
					return mid;
				}
				else  // ������ǣ������Ǿ͸��� low=mid+1����ΪҪ�ҵ�Ԫ�ؿ϶�������[mid+1, high]֮�䡣
				{
					low = mid + 1;
				}
			}
		}

		return -1;
	}

	// 3.���ҵ�һ�����ڵ��ڸ���ֵ��Ԫ��
	template<class T>
	int binarySearch_firstGreateOrEqual(T arr[], int n, T target)
	{
		int low = 0;
		int high = n - 1;

		while (low <= high)
		{
			int mid = low + ((high - low) >> 1);
			// ���� a[mid]���ڵ��ڸ���ֵ target �����������Ҫ�ȿ������ a[mid]�ǲ�������Ҫ�ҵĵ�һ��ֵ���ڵ��ڸ���ֵ��Ԫ�ء�
			// ��� a[mid]ǰ���Ѿ�û��Ԫ�أ�����ǰ��һ��Ԫ��С��Ҫ���ҵ�ֵ target���� a[mid]��������Ҫ�ҵ�Ԫ�ء�
			// ��� a[mid - 1]Ҳ���ڵ���Ҫ���ҵ�ֵ target����˵��Ҫ���ҵ�Ԫ����[low, mid - 1]֮�䣬���ԣ����ǽ� high ����Ϊ mid - 1��
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
			{// ��� a[mid]С��Ҫ���ҵ�ֵ target����Ҫ���ҵ�ֵ�϶���[mid+1, high]֮�䣬���ԣ����Ǹ��� low=mid+1��
				low = mid + 1;
			}
		}
		return -1;
	}

	// 4.�������һ��С�ڵ��ڸ���ֵ��Ԫ��
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
