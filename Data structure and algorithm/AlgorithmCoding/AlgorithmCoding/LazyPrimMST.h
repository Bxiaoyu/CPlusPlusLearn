#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
#include "./MinHeap.h"
/*
*	��С���������壺��ͼ���ҵ�V-1���ߣ�����V�����㣨�Ȳ����л���������Ȩֵ��С��
*	��С��������ԵĶ���
		1.��Ȩ����ͼ��
		2.��ͨͼ
*	ʵ���㷨��
		1.Ѱ����С�������㷨--Lazy Prim�㷨�������зֶ���

	�зֶ������������з֣�Cut�������б���Ȩֵ��С�ı߱�Ȼ������С��������

*	�зֶ���Ҫ�㣺
*       1.�з֣���ͼ�еĽڵ��Ϊ�����֣���Ϊһ���з֣�Cut��;
*		2.���бߣ����һ���ߵ������˵㣬�����з֣�Cut����ͬ�����ߣ�����߳�Ϊ���бߣ�Crossing Edge����
*	
*/

using namespace std;

// Lazy Prim�㷨
template<class Graph, class Weight>
class LazyPrinmMST
{
private:
	Graph& G;                    // ͼ������
	MinHeap<Edge<Weight>> pq;    // ��С�ѣ��㷨�������ݽṹ
	bool* marked;                // ������飬���㷨���й����б�ǽڵ�i�Ƿ񱻷���
	vector<Edge<Weight>> mst;    // ��С�����������������б�
	Weight mstWeight;            // ��С��������Ȩֵ

public:
	LazyPrinmMST(Graph& graph) :G(graph), pq(MinHeap<Edge<Weight>>(graph.E()))
	{
		marked = new bool[G.V()];
		for (int i = 0; i < G.V(); i++)
		{
			marked[i] = false;
		}
		mst.clear();

		// Lazy Prim
		visit(0);
		while (!pq.isEmpty())
		{
			// ʹ����С���ҳ��Ѿ����ʵı���Ȩֵ��С�ı�
			Edge<Weight> e = pq.extractMin();
			// ��������ߵ������˵㶼�Ѿ������ʹ��ˣ����ӵ�������
			if (marked[e.v()] == marked[e.w()])
				continue;
			// ����������Ӧ�ô�������С��������
			mst.push_back(e);

			// ���ʺ����������ӵĻ�û�����ʹ��Ľڵ�
			if (!marked[e.v()])
			{
				visit(e.v());
			}
			else
			{
				visit(e.w());
			}
		}

		// ������С��������Ȩֵ
		mstWeight = mst[0].wt();
		for (int i = 1; i < mst.size(); i++)
		{
			mstWeight += mst[i].wt();
		}

	}

	// ��������
	~LazyPrinmMST()
	{
		delete[] marked;
	}

	// ������С�����������б�
	vector<Edge<Weight>> mstEdges()
	{
		return mst;
	}

	// ������С��������Ȩֵ
	Weight result()
	{
		return mstWeight;
	}

private:
	// ���ʽڵ�v
	void visit(int v)
	{
		assert(!marked[v]);
		marked[v] = true;

		// ���ͽڵ�v�����ӵ�����δ�����ʵı߷�����С����
		typename Graph::adjIterator adj(G, v);
		for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next())
		{
			if (!marked[e->other(v)])
			{
				pq.insert(*e);
			}
		}
	}
};