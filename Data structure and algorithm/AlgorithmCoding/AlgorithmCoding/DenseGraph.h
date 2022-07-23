#pragma once
/*
*	����ͼ-�ڽӾ���
*/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class DenseGraph
{
private:
	int v;  // �洢�ڵ���
	int e;  // �洢����
	bool directed;  // �Ƿ�Ϊ����ͼ
	vector<vector<bool>> g;  // ͼ�ľ�������

public:
	DenseGraph(int n, bool directed=false)
	{
		assert(n >= 0);
		this->v = n;
		this->e = 0;  // ��ʼ��û���κα�
		this->directed = directed;
		// g��ʼ��Ϊn*n�Ĳ�������, ÿһ��g[i][j]��Ϊfalse, ��ʾû���κͱ�
		g = vector<vector<bool>>(n, vector<bool>(n, false));
	}

	~DenseGraph()
	{
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
	void addEdge(int v, int w)
	{
		assert(v >= 0 && v < this->v);
		assert(w >= 0 && w < this->v);

		if (hasEdge(v, w))  // ��������ڵ��������ϵ����ֱ�ӷ���
		{
			return;
		}

		g[v][w] = true;
		if (!directed)  // ���������ͼ����g[w][v]Ҳ��Ҫ��Ϊtrue
		{
			g[w][v] = true;
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
				cout << g[i][j] << "\t";
			}
			cout << endl;
		}
	}

	// �ڱߵ�����, ����һ��ͼ��һ������,
	// ���������ͼ�к�����������������ж���
	class adjIterator
	{
	private:
		DenseGraph& G;
		int node;
		int index;
	public:
		adjIterator(DenseGraph& graph, int node) :G(graph)
		{
			this->node = node;
			this->index = -1;
		}

		int begin()
		{
			index = -1;
			return next();
		}

		int next()
		{
			for (index += 1; index < G.V(); index++)
			{
				if (G.g[node][index])
				{
					return index;
				}
			}
			return -1;
		}

		bool end()
		{
			return index >= G.V();
		}
	};
};