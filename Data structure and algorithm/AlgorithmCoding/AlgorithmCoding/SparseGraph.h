#pragma once
/*
*	ϡ��ͼ-�ڽӱ�
*/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class SparseGraph
{
private:
	int v;  // �ڵ���
	int e;  // ����
	bool directed;  // �Ƿ�Ϊ����ͼ
	vector<vector<int>> g;  // ͼ�ľ������ݣ��˴�Ϊ�˷������������洢�����ձ�Ŀ��������������������������洢

public:
	SparseGraph(int n, bool directed = false)
	{
		this->v = n;
		this->e = 0;  // ��ʼ��ʱû���κα�
		this->directed = directed;
		// g��ʼ��Ϊn���յ�vector, ��ʾÿһ��g[i]��Ϊ��, ��û���κͱ�
		g = vector<vector<int>>(n, vector<int>());
	}

	~SparseGraph()
	{
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
	void addEdge(int v, int w)
	{
		assert(v >= 0 && v < this->v);
		assert(w >= 0 && w < this->v);


		g[v].push_back(w);
		if (v != w && !directed)  // �ж��Ƿ����Ի��ߺ��Ƿ�������ͼ
		{
			g[w].push_back(v);
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
			if (g[v][i] == w)
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