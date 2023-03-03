#include <iomanip>
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
#include "ReadMinimumSpawnTree.h"
#include "MinimumSpawnTreeDenseGraph.h"
#include "MinimumSpawnTreeSparseGraph.h"
#include "LazyPrimMST.h"
#include "bubbleSort.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "shellSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "bucketSort.h"

using namespace std;
using namespace SortTestHelper;
using namespace FileOps;
using namespace UnionFindTestHelper;
using namespace BubbleSort;
using namespace SelectionSort;
using namespace InsertionSort;
using namespace ShellSort;
using namespace MergeSort;
using namespace QuickSort;
using namespace NPBucketSort;

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

	// 测试1 一般性能测试
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
	// 我们使用文本量更小的共产主义宣言进行试验:)
	string filename = "communist.txt";
	vector<string> words;

	if (FileOps::readFile(filename, words))
	{

		cout << "There are totally " << words.size() << " words in " << filename << endl;
		cout << endl;


		// 测试1, 我们按照文本原有顺序插入进二分搜索树
		time_t startTime = clock();
		BST<string, int>* bst = new BST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int* res = (*bst).search(*iter);
			if (res == nullptr)
				(*bst).insert(*iter, 1);
			else
				(*res)++;
		}

		// 我们查看unite一词的词频
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

void test_MinimumSpawnTree()
{
	string filename = "C:\\Users\\sky\\Desktop\\coding-71-master\\coding-71\\08-Minimum-Span-Trees\\Course Code (C++)\\01-Weighted-Graph\\testG1.txt";
	int V = 8;
	cout<<fixed<<setprecision(2);

    // Test Weighted Dense Graph
    SpawnTreeDenseGraph<double> g1 = SpawnTreeDenseGraph<double>(V, false);
    ReadMinimumSpawnTreeGraph<SpawnTreeDenseGraph<double>,double> readGraph1(g1, filename);
    g1.show();
    cout<<endl;

    // Test Weighted Sparse Graph
    SpawnTreeSparseGraph<double> g2 = SpawnTreeSparseGraph<double>(V, false);
	ReadMinimumSpawnTreeGraph<SpawnTreeSparseGraph<double>,double> readGraph2(g2, filename);
    g2.show();
    cout<<endl;
}

void test_LazyPrim()
{
	string filename = "C:\\Users\\sky\\Desktop\\coding-71-master\\coding-71\\08-Minimum-Span-Trees\\Course Code (C++)\\03-Lazy-Prim\\testG1.txt";
	int V = 8;

	// Test Weighted Sparse Graph
	SpawnTreeSparseGraph<double> g2 = SpawnTreeSparseGraph<double>(V, false);
	ReadMinimumSpawnTreeGraph<SpawnTreeSparseGraph<double>, double> readGraph2(g2, filename);

	// Test Lazy Prim MST
	cout << "Test Lazy Prim MST: " << endl;
	LazyPrinmMST<SpawnTreeSparseGraph<double>, double> lazyPrimMST(g2);
	vector<Edge<double>> mst = lazyPrimMST.mstEdges();
	for (int i = 0; i < mst.size(); i++)
	{
		cout << mst[i] << endl;
	}
	cout << "The MST weight is: " << lazyPrimMST.result() << endl;

	cout << endl;
}


int main()
{
	//test_heap();
	//test_heapSort();
	//test_binarySearchTree();
	//test_unionFind();
	//test_Graph();
	//test_readGraph();
	//test_shortestPathGraph();
	//test_MinimumSpawnTree();
	//test_LazyPrim();
	//BubbleSort::test_func();
	//SelectionSort::test_func();
	//InsertionSort::test_func();
	//ShellSort::test_func();
	//MergeSort::test_func();
	//QuickSort::test_func();
	NPBucketSort::test_func();
	return 0;
}