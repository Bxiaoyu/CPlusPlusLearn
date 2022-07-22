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
};