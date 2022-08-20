#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
#include "./MinHeap.h"
/*
*	最小生成树定义：在图中找到V-1条边，连接V个顶点（既不能有环），且总权值最小。
*	最小生成树针对的对象：
		1.带权无向图；
		2.连通图
*	实现算法：
		1.寻找最小生成树算法--Lazy Prim算法（基于切分定理）

	切分定理：给定任意切分（Cut），横切边中权值最小的边必然属于最小生成树。

*	切分定理要点：
*       1.切分：把图中的节点分为两部分，成为一个切分（Cut）;
*		2.横切边：如果一个边的两个端点，属于切分（Cut）不同的两边，这个边称为横切边（Crossing Edge）；
*	
*/

using namespace std;

// Lazy Prim算法
template<class Graph, class Weight>
class LazyPrinmMST
{
private:
	Graph& G;                    // 图的引用
	MinHeap<Edge<Weight>> pq;    // 最小堆，算法辅助数据结构
	bool* marked;                // 标记数组，在算法运行过程中标记节点i是否被访问
	vector<Edge<Weight>> mst;    // 最小生成树所包含的所有边
	Weight mstWeight;            // 最小生成树的权值

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
			// 使用最小堆找出已经访问的边中权值最小的边
			Edge<Weight> e = pq.extractMin();
			// 如果这条边的两个端点都已经被访问过了，则扔掉这条边
			if (marked[e.v()] == marked[e.w()])
				continue;
			// 否则，这条边应该存在在最小生成树中
			mst.push_back(e);

			// 访问和这条边连接的还没被访问过的节点
			if (!marked[e.v()])
			{
				visit(e.v());
			}
			else
			{
				visit(e.w());
			}
		}

		// 计算最小生成树的权值
		mstWeight = mst[0].wt();
		for (int i = 1; i < mst.size(); i++)
		{
			mstWeight += mst[i].wt();
		}

	}

	// 析构函数
	~LazyPrinmMST()
	{
		delete[] marked;
	}

	// 返回最小生成树的所有边
	vector<Edge<Weight>> mstEdges()
	{
		return mst;
	}

	// 返回最小生成树的权值
	Weight result()
	{
		return mstWeight;
	}

private:
	// 访问节点v
	void visit(int v)
	{
		assert(!marked[v]);
		marked[v] = true;

		// 将和节点v相连接的所有未被访问的边放入最小堆中
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