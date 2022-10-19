#pragma once
/*
*	ϡ��ͼ(��Ȩ)-�ڽӱ�
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
	int v;  // �ڵ���
	int e;  // ����
	bool directed;  // �Ƿ�Ϊ����ͼ
	vector<vector<Edge<Weight>* >> g;  // ͼ�ľ������ݣ��˴�Ϊ�˷������������洢�����ձ�Ŀ��������������������������洢

public:
	SpawnTreeSparseGraph(int n, bool directed = false)
	{
		this->v = n;
		this->e = 0;  // ��ʼ��ʱû���κα�
		this->directed = directed;
		// g��ʼ��Ϊn���յ�vector, ��ʾÿһ��g[i]��Ϊ��, ��û���κͱ�
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

	// ���ؽڵ����
	int V()
	{
		return this->v;
	}

	// ���ر���
	int E()
	{
		return this->e;
	}

	// ��ͼ�����һ���ߣ������ڽӱ��ڴ���ƽ�б�ʱ��ʱ����������addEdgeʱ������ƽ�бߣ�֮����Ҫ�ٴ���
	void addEdge(int v, int w, Weight weight)
	{
		assert(v >= 0 && v < this->v);
		assert(w >= 0 && w < this->v);


		g[v].push_back(new Edge<Weight>(v, w, weight));
		if (v != w && !directed)  // �ж��Ƿ����Ի��ߺ��Ƿ�������ͼ
		{
			g[w].push_back(new Edge<Weight>(w, v, weight));
		}

		this->e++;
	}

	// ��֤ͼ���Ƿ��д�v��w�ı�
	bool hasEdge(int v, int w)
	{
		assert(v >= 0 && v < this->v);
		assert(w >= 0 && w < this->v);

		for (int i = 0; i < g[v].size(); i++)  // �ʱ�临�Ӷ�ΪO(n)
		{
			if (g[v][i]->other(v) == w)
			{
				return true;
			}
		}
		return false;
	}

	// ��ӡ
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

	// �ڱߵ�����, ����һ��ͼ��һ������,
	// ���������ͼ�к�����������������ж���
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