#pragma once
/*
*	���鼯������rank���Ż���������
*/
#include <iostream>
#include <cassert>

namespace UF4 {
	class UnionFind
	{
	private:
		int* parent;
		int* rank;  // rank[i]��ʾ��iΪ���ļ�������ʾ�����Ĳ���
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

			if (rank[pRoot] < rank[qRoot])  // ��������rank�����ʱ������ά��rank����
			{
				parent[pRoot] = qRoot;
			}
			else if(rank[pRoot] > rank[qRoot])
			{
				parent[qRoot] = pRoot;
			}
			else  // rank[pRoot] == rank[qRoot]����ʱҪά��rank����
			{
				parent[pRoot] = qRoot;  // ���ѡһ��root��Ϊ���׽ڵ�
				rank[qRoot] += 1;
			}
		}
	};
}
