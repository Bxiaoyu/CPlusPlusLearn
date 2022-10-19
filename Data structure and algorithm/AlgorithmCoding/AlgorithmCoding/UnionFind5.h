#pragma once
/*
*	并查集，基于路径压缩的优化（迭代法），并查集的时间复杂度近乎是O(1)的
* 
*   // 我们将我们的并查集初始设置成如下的样子
	//            0
	//           /
	//          1
	//         /
	//        2
	//       /
	//      3
	//     /
	//    4

	// 压缩完成后, 我们可以看出, 使用迭代的路径压缩, 我们的并查集可以变成这个样子:
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

		// 在find过程中进行路径压缩
		int find(int p)
		{
			assert(p >= 0 && p < count);
			while (p != parent[p])
			{
				parent[p] = parent[parent[p]];  // 将p指向父节点的指针指向其父节点的父节点，这样即可压缩路径；由于不存在父节点的节点指针指向自己，所以不存在指针无效问题
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
			else if (rank[pRoot] > rank[qRoot])
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

/*
*	并查集，基于路径压缩的优化（递归法），逻辑上这样更优，但实际上性能略弱于迭代法
*
*   // 我们将我们的并查集初始设置成如下的样子
	//            0
	//           /
	//          1
	//         /
	//        2
	//       /
	//      3
	//     /
	//    4

	// 使用递归的路径压缩, 我们的并查集变成这个样子:
	//     0
	//  / / \ \
	// 1 2   3 4
*/
namespace UF6 {
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

		// 在find过程中进行路径压缩，递归法
		int find(int p)
		{
			assert(p >= 0 && p < count);
			if (p != parent[p])
			{
				parent[p] = find(parent[p]);  // 递归返回树的根节点，并将p的父节点指针指向根节点
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

			if (rank[pRoot] < rank[qRoot])  // 在两个根rank不相等时，不用维护rank数组
			{
				parent[pRoot] = qRoot;
			}
			else if (rank[pRoot] > rank[qRoot])
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
