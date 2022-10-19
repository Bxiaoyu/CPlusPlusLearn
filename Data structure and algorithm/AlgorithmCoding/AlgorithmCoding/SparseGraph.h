#pragma once
/*
*	稀疏图-邻接表
*/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class SparseGraph
{
private:
	int v;  // 节点数
	int e;  // 边数
	bool directed;  // 是否为有向图
	vector<vector<int>> g;  // 图的具体数据，此处为了方便用数组来存储，更普遍的可以用链表或者跳表，红黑树等来存储

public:
	SparseGraph(int n, bool directed = false)
	{
		this->v = n;
		this->e = 0;  // 初始化时没有任何边
		this->directed = directed;
		// g初始化为n个空的vector, 表示每一个g[i]都为空, 即没有任和边
		g = vector<vector<int>>(n, vector<int>());
	}

	~SparseGraph()
	{
	}

	// 返回节点个数
	int V()
	{
		return this->v;
	}

	// 返回边数
	int E()
	{
		return this->e;
	}

	// 向图中添加一条边，由于邻接表在处理平行边时耗时长，所以在addEdge时不考虑平行边，之后需要再处理
	void addEdge(int v, int w)
	{
		assert(v >= 0 && v < this->v);
		assert(w >= 0 && w < this->v);


		g[v].push_back(w);
		if (v != w && !directed)  // 判断是否有自环边和是否是有向图
		{
			g[w].push_back(v);
		}

		this->e++;
	}

	// 验证图中是否有从v到w的边
	bool hasEdge(int v, int w)
	{
		assert(v >= 0 && v < this->v);
		assert(w >= 0 && w < this->v);

		for (int i = 0; i < g[v].size(); i++)  // 最坏时间复杂度为O(n)
		{
			if (g[v][i] == w)
			{
				return true;
			}
		}
		return false;
	}

	// 打印
	void show()
	{
		for (int i = 0; i < v; i++)
		{
			cout << "vertex " << i << ":\t";
			for (int j = 0; j < g[i].size(); j++)
			{
				cout << g[i][j] << "\t";
			}
			cout << endl;
		}
	}

	// 邻边迭代器, 传入一个图和一个顶点,
	// 迭代在这个图中和这个顶点向连的所有顶点
	class adjIterator
	{
	private:
		SparseGraph& G;
		int node;
		int index;
	public:
		adjIterator(SparseGraph& graph, int node) :G(graph)
		{
			this->node = node;
			this->index = 0;
		}

		int begin()
		{
			index = 0;
			if (G.g[node].size())
			{
				return G.g[node][index];
			}
			return -1;
		}

		int next()
		{
			index++;
			if (index < G.g[node].size())
			{
				return G.g[node][index];
			}
			return -1;
		}

		bool end()
		{
			return index >= G.g[node].size();
		}
	};
};