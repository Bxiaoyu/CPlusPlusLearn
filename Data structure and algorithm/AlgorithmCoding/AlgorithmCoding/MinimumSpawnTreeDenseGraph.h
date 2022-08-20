#pragma once
/*
*	����ͼ(��Ȩ)-�ڽӾ���
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
	int v;  // �洢�ڵ���
	int e;  // �洢����
	bool directed;  // �Ƿ�Ϊ����ͼ
	vector<vector<Edge<Weight> *>> g;  // ͼ�ľ�������

public:
	SpawnTreeDenseGraph(int n, bool directed = false)
	{
		assert(n >= 0);
		this->v = n;
		this->e = 0;  // ��ʼ��û���κα�
		this->directed = directed;
		// g��ʼ��Ϊn*n�Ĳ�������, ÿһ��g[i][j]��Ϊfalse, ��ʾû���κͱ�
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

	// ���ؽڵ����
	int V()
	{
		return v;
	}

	// ���رߵĸ���
	int E()
	{
		return e;
	}

	// ��ͼ�����һ����
	void addEdge(int v, int w, Weight weight)
	{
		assert(v >= 0 && v < this->v);
		assert(w >= 0 && w < this->v);

		if (hasEdge(v, w))  // ��������ڵ��������ϵ����������򵥸���
		{
			delete g[v][w];
			if (!directed)
			{
				delete g[w][v];
			}
			this->e--;
		}

		g[v][w] = new Edge<Weight>(v, w, weight);
		if (!directed)  // ���������ͼ����g[w][v]Ҳ��Ҫ��Ϊtrue
		{
			g[w][v] = new Edge<Weight>(w, v, weight);
		}

		this->e++;
	}

	// ��֤ͼ���Ƿ��д�v��w�ı�
	bool hasEdge(int v, int w)
	{
		assert(v >= 0 && v < this->v);
		assert(w >= 0 && w < this->v);
		return g[v][w];
	}

	// ��ӡ
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

	// �ڱߵ�����, ����һ��ͼ��һ������,
	// ���������ͼ�к�����������������ж���
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