#pragma once
/*
*	遍历图：深度优先遍历查看连通分量个数
*/
#include <iostream>
#include <cassert>

using namespace std;

template<typename Graph>
class Component
{
private:
	Graph& G;
	bool* visited;
	int* id;
	int ccount;

	void dfs(int v)
	{
		visited[v] = true;
		id[v] = ccount;

		typename Graph::adjIterator adj(G, v);
		for (int i = adj.begin(); !adj.end(); i = adj.next())
		{
			if (!visited[i])
			{
				dfs(i);
			}
		}
	}

public:
	Component(Graph& graph) :G(graph)
	{
		visited = new bool[G.V()];
		id = new int[G.V()];
		ccount = 0;
		for (int i = 0; i < G.V(); i++)
		{
			visited[i] = false;
			id[i] = -1;
		}

		for (int i = 0; i < G.V(); i++)
		{
			if (!visited[i])
			{
				dfs(i);
				ccount++;
			}
		}
	}

	~Component()
	{
		delete[] visited;
		delete[] id;
	}

	// 返回连通分量个数
	int count()
	{
		return ccount;
	}

	// 判断两个节点是否相连
	bool isConnected(int v, int w)
	{
		assert(v >= 0 && v < G.V());
		assert(w >= 0 && w < G.V());
		return id[v] == id[w];
	}
};