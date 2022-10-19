#pragma once
/*
*	稠密图(带权)-邻接矩阵
*/
#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

template<class Weight>
class SpawnTreeDenseGraph
{
private:
	int v;  // 存储节点数
	int e;  // 存储边数
	bool directed;  // 是否为有向图
	vector<vector<Edge<Weight> *>> g;  // 图的具体数据

public:
	SpawnTreeDenseGraph(int n, bool directed = false)
	{
		assert(n >= 0);
		this->v = n;
		this->e = 0;  // 初始化没有任何边
		this->directed = directed;
		// g初始化为n*n的布尔矩阵, 每一个g[i][j]均为false, 表示没有任和边
		for (int i = 0; i < n; i++)
		{
			g.push_back(vector<Edge<Weight>*>(n, nullptr));
		}
	}

	~SpawnTreeDenseGraph()
	{
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
			{
				if (g[i][j] != nullptr)
				{
					delete g[i][j];
				}
			}
		}
	}

	// 返回节点个数
	int V()
	{
		return v;
	}

	// 返回边的个数
	int E()
	{
		return e;
	}

	// 向图中添加一个边
	void addEdge(int v, int w, Weight weight)
	{
		assert(v >= 0 && v < this->v);
		assert(w >= 0 && w < this->v);

		if (hasEdge(v, w))  // 如果两个节点间已有联系，在这里则简单覆盖
		{
			delete g[v][w];
			if (!directed)
			{
				delete g[w][v];
			}
			this->e--;
		}

		g[v][w] = new Edge<Weight>(v, w, weight);
		if (!directed)  // 如果是无向图，则g[w][v]也需要设为true
		{
			g[w][v] = new Edge<Weight>(w, v, weight);
		}

		this->e++;
	}

	// 验证图中是否有从v到w的边
	bool hasEdge(int v, int w)
	{
		assert(v >= 0 && v < this->v);
		assert(w >= 0 && w < this->v);
		return g[v][w];
	}

	// 打印
	void show()
	{
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
			{
				if (g[i][j])
					cout << g[i][j]->wt() << "\t";
				else
					cout << "NULL\t";
			}
			cout << endl;
		}
	}

	// 邻边迭代器, 传入一个图和一个顶点,
	// 迭代在这个图中和这个顶点向连的所有顶点
	class adjIterator
	{
	private:
		SpawnTreeDenseGraph& G;
		int node;
		int index;
	public:
		adjIterator(SpawnTreeDenseGraph& graph, int node) :G(graph)
		{
			this->node = node;
			this->index = -1;
		}

		Edge<Weight>* begin()
		{
			index = -1;
			return next();
		}

		Edge<Weight>* next()
		{
			for (index += 1; index < G.V(); index++)
			{
				if (G.g[node][index])
				{
					return G.g[v][index];
				}
			}
			return nullptr;
		}

		bool end()
		{
			return index >= G.V();
		}
	};
};