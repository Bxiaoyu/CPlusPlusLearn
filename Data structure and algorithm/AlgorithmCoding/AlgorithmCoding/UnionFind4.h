#pragma once
/*
*	并查集，基于rank的优化，不常用
*/
#include <iostream>
#include <cassert>

namespace UF4 {
	class UnionFind
	{
	private:
		int* parent;
		int* rank;  // rank[i]表示以i为根的集合所表示的树的层数
		int count;

	public:
		UnionFind(int count)
		{
			this->parent = new int[count];
			this->rank = new int[count];
			this->count = count;
			for (int i = 0; i < count; i++)
			{
				parent[i] = i;
				rank[i] = 1;
			}
		}

		~UnionFind()
		{
			delete[] parent;
			delete[] rank;
		}

		int find(int p)
		{
			assert(p >= 0 && p < count);
			while (p != parent[p])
			{
				p = parent[p];
			}
			return p;
		}

		bool isConnected(int p, int q)
		{
			return find(p) == find(q);
		}

		void unionElements(int p, int q)
		{
			int pRoot = find(p);
			int qRoot = find(q);

			if (pRoot == qRoot)
			{
				return;
			}

			if (rank[pRoot] < rank[qRoot])  // 在两个根rank不相等时，不用维护rank数组
			{
				parent[pRoot] = qRoot;
			}
			else if(rank[pRoot] > rank[qRoot])
			{
				parent[qRoot] = pRoot;
			}
			else  // rank[pRoot] == rank[qRoot]，此时要维护rank数组
			{
				parent[pRoot] = qRoot;  // 随便选一个root作为父亲节点
				rank[qRoot] += 1;
			}
		}
	};
}
