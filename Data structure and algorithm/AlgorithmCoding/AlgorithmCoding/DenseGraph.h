#pragma once
/*
*	稠密图-邻接矩阵
*/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class DenseGraph
{
private:
	int v;  // 存储节点数
	int e;  // 存储边数
	bool directed;  // 是否为有向图
	vector<vector<bool>> g;  // 图的具体数据

public:
	DenseGraph(int n, bool directed=false)
	{
		assert(n >= 0);
		this->v = n;
		this->e = 0;  // 初始化没有任何边
		this->directed = directed;
		// g初始化为n*n的布尔矩阵, 每一个g[i][j]均为false, 表示没有任和边
		g = vector<vector<bool>>(n, vector<bool>(n, false));
	}

	~DenseGraph()
	{
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
	void addEdge(int v, int w)
	{
		assert(v >= 0 && v < this->v);
		assert(w >= 0 && w < this->v);

		if (hasEdge(v, w))  // 如果两个节点间已有联系，则直接返回
		{
			return;
		}

		g[v][w] = true;
		if (!directed)  // 如果是无向图，则g[w][v]也需要设为true
		{
			g[w][v] = true;
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
};