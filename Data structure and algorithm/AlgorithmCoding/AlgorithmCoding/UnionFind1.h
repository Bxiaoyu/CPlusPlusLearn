#pragma once
/*
*	并查集的实现，此种实现方式查找快(quick find)，并操作慢
*/
#include <iostream>
#include <cassert>


namespace UF1
{
	class UnionFind
	{
	private:
		int* id;
		int count;

	public:
		UnionFind(int n)
		{
			count = n;
			id = new int[n];
			for (int i = 0; i < n; i++)  // 初始化时各个元素独自为一组
			{
				id[i] = i;
			}
		}

		~UnionFind()
		{
			delete[] id;
		}

		int find(int p)
		{
			assert(p >= 0 && p < count);
			return id[p];
		}

		bool isConnected(int p, int q)
		{
			return find(p) == find(q);
		}

		void unionElements(int p, int q)
		{
			int pID = find(p);
			int qID = find(q);

			if (pID == qID);
			{
				return;
			}

			for (int i = 0; i < count; i++)
			{
				if (id[i] == pID)
				{
					id[i] = qID;
				}
			}
		}
	};
}