#pragma once
/*
*	稀疏图(带权)-邻接表
*/
#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

template<class Weight>
class SpawnTreeSparseGraph
{
private:
	int v;  // 节点数
	int e;  // 边数
	bool directed;  // 是否为有向图
	vector<vector<Edge<Weight>* >> g;  // 图的具体数据，此处为了方便用数组来存储，更普遍的可以用链表或者跳表，红黑树等来存储

public:
	SpawnTreeSparseGraph(int n, bool directed = false)
	{
		this->v = n;
		this->e = 0;  // 初始化时没有任何边
		this->directed = directed;
		// g初始化为n个空的vector, 表示每一个g[i]都为空, 即没有任和边
		for (int i = 0; i < v; i++)
		{
			g.push_back(vector<Edge<Weight>* >());
		}
	}

	~SpawnTreeSparseGraph()
	{
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < g[i].size(); j++)
			{
				delete g[i][j];
			}
		}
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
	void addEdge(int v, int w, Weight weight)
	{
		assert(v >= 0 && v < this->v);
		assert(w >= 0 && w < this->v);


		g[v].push_back(new Edge<Weight>(v, w, weight));
		if (v != w && !directed)  // 判断是否有自环边和是否是有向图
		{
			g[w].push_back(new Edge<Weight>(w, v, weight));
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
			if (g[v][i]->other(v) == w)
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
				cout << "( to:" << g[i][j]->w() << ", wt:" << g[i][j]->wt() << ")\t";
			}
			cout << endl;
		}
	}

	// 邻边迭代器, 传入一个图和一个顶点,
	// 迭代在这个图中和这个顶点向连的所有顶点
	class adjIterator
	{
	private:
		SpawnTreeSparseGraph& G;
		int node;
		int index;
	public:
		adjIterator(SpawnTreeSparseGraph& graph, int node) :G(graph)
		{
			this->node = node;
			this->index = 0;
		}

		Edge<Weight>* begin()
		{
			index = 0;
			if (G.g[node].size())
			{
				return G.g[node][index];
			}
			return nullptr;
		}

		Edge<Weight>* next()
		{
			index++;
			if (index < G.g[node].size())
			{
				return G.g[node][index];
			}
			return nullptr;
		}

		bool end()
		{
			return index >= G.g[node].size();
		}
	};
};