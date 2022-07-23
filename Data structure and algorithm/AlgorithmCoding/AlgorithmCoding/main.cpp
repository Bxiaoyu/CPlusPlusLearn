#include "maxheap.h"
#include "heapsort.h"
#include "SortTestHelper.h"
#include "BST.h"
#include "FileOps.h"
#include "UnionFindTestHelper.h"
#include "ReadGraph.h"
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "Path.h"
#include "ShortestPath.h"

using namespace std;
using namespace SortTestHelper;
using namespace FileOps;
using namespace UnionFindTestHelper;

void test_heap()
{
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	cout << maxheap.size() << endl;

	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		maxheap.insert(rand() % 100);
	}
	//maxheap.testPrint();
	while (!maxheap.isEmpty())
	{
		cout << maxheap.extractMax() << " ";
	}
	cout << endl;
}

void test_heapSort()
{
	int n = 1000000;

	// ����1 һ�����ܲ���
	cout << "Test for Random Array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0 ,n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);
	int* arr3 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("HeapSort1", heapSort1, arr1, n);
	SortTestHelper::testSort("HeapSort2", heapSort2, arr2, n);
	SortTestHelper::testSort("HeapSort3", heapSort3, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	cout << endl;
}

void test_binarySearchTree()
{
	// ����ʹ���ı�����С�Ĺ����������Խ�������:)
	string filename = "communist.txt";
	vector<string> words;

	if (FileOps::readFile(filename, words))
	{

		cout << "There are totally " << words.size() << " words in " << filename << endl;
		cout << endl;


		// ����1, ���ǰ����ı�ԭ��˳����������������
		time_t startTime = clock();
		BST<string, int>* bst = new BST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int* res = (*bst).search(*iter);
			if (res == nullptr)
				(*bst).insert(*iter, 1);
			else
				(*res)++;
		}

		// ���ǲ鿴uniteһ�ʵĴ�Ƶ
		if (bst->contain("unite"))
			cout << "'unite' : " << *(*bst).search("unite") << endl;
		else
			cout << "No word 'unite' in " + filename << endl;
		time_t endTime = clock();

		cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		delete bst;
	}
}

void test_unionFind()
{
	int n = 100000;
	//UnionFindTestHelper::testUF1(n);
	//UnionFindTestHelper::testUF2(n);
	//UnionFindTestHelper::testUF3(n);
	UnionFindTestHelper::testUF4(n);
	UnionFindTestHelper::testUF5(n);
}

void test_Graph()
{
	int N = 20;
	int M = 100;

	srand(time(NULL));


	// Sparse Graph
	SparseGraph g1(N, false);
	for (int i = 0; i < M; i++) {
		int a = rand() % N;
		int b = rand() % N;
		g1.addEdge(a, b);
	}

	// O(E)
	for (int v = 0; v < N; v++) {
		cout << v << " : ";
		SparseGraph::adjIterator adj(g1, v);
		for (int w = adj.begin(); !adj.end(); w = adj.next())
			cout << w << " ";
		cout << endl;
	}

	cout << endl;


	// Dense Graph
	DenseGraph g2(N, false);
	for (int i = 0; i < M; i++) {
		int a = rand() % N;
		int b = rand() % N;
		g2.addEdge(a, b);
	}

	// O(V^2)
	for (int v = 0; v < N; v++) {
		cout << v << " : ";
		DenseGraph::adjIterator adj(g2, v);
		for (int w = adj.begin(); !adj.end(); w = adj.next())
			cout << w << " ";
		cout << endl;
	}
}

void test_readGraph()
{
	string filename = "testG1.txt";
	SparseGraph g1(13, false);
	ReadGraph<SparseGraph> readGraph1(g1, filename);
	g1.show();

	cout << endl;

	DenseGraph g2(13, false);
	ReadGraph<DenseGraph> readGraph2(g2, filename);
	g2.show();
}

void test_shortestPathGraph()
{
	string filename = "C:\\Users\\sky\\Desktop\\coding-71-master\\coding-71\\07-Graph-Basics\\Course Code (C++)\\06-Finding-a-Path\\testG.txt";
	SparseGraph g = SparseGraph(7, false);
	ReadGraph<SparseGraph> readGraph(g, filename);
	g.show();
	cout << endl;

	Path<SparseGraph> dfs(g, 0);
	cout << "DFS: ";
	dfs.showPath(6);

	ShortestPath<SparseGraph> bfs(g, 0);
	cout << "BFS: ";
	bfs.showPath(6);
}


int main()
{
	//test_heap();
	//test_heapSort();
	//test_binarySearchTree();
	//test_unionFind();
	//test_Graph();
	//test_readGraph();
	test_shortestPathGraph();
	return 0;
}