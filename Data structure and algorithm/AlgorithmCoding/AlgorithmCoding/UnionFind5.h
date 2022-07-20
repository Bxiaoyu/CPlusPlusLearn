#pragma once
/*
*	���鼯������·��ѹ�����Ż����������������鼯��ʱ�临�ӶȽ�����O(1)��
* 
*   // ���ǽ����ǵĲ��鼯��ʼ���ó����µ�����
	//            0
	//           /
	//          1
	//         /
	//        2
	//       /
	//      3
	//     /
	//    4

	// ѹ����ɺ�, ���ǿ��Կ���, ʹ�õ�����·��ѹ��, ���ǵĲ��鼯���Ա���������:
	//     0
	//    / \
	//   1   2
	//  / \
	// 3  4
*/
#include <iostream>
#include <cassert>

namespace UF5 {
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

		// ��find�����н���·��ѹ��
		int find(int p)
		{
			assert(p >= 0 && p < count);
			while (p != parent[p])
			{
				parent[p] = parent[parent[p]];  // ��pָ�򸸽ڵ��ָ��ָ���丸�ڵ�ĸ��ڵ㣬��������ѹ��·�������ڲ����ڸ��ڵ�Ľڵ�ָ��ָ���Լ������Բ�����ָ����Ч����
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
			else if (rank[pRoot] > rank[qRoot])
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

/*
*	���鼯������·��ѹ�����Ż����ݹ鷨�����߼����������ţ���ʵ�������������ڵ�����
*
*   // ���ǽ����ǵĲ��鼯��ʼ���ó����µ�����
	//            0
	//           /
	//          1
	//         /
	//        2
	//       /
	//      3
	//     /
	//    4

	// ʹ�õݹ��·��ѹ��, ���ǵĲ��鼯����������:
	//     0
	//  / / \ \
	// 1 2   3 4
*/
namespace UF6 {
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

		// ��find�����н���·��ѹ�����ݹ鷨
		int find(int p)
		{
			assert(p >= 0 && p < count);
			if (p != parent[p])
			{
				parent[p] = find(parent[p]);  // �ݹ鷵�����ĸ��ڵ㣬����p�ĸ��ڵ�ָ��ָ����ڵ�
			}
			return parent[p];
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
			else if (rank[pRoot] > rank[qRoot])
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
