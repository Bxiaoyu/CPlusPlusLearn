#include "maxheap.h"
#include "heapsort.h"
#include "SortTestHelper.h"
#include "BST.h"
#include "FileOps.h"
#include "UnionFindTestHelper.h"

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
	UnionFindTestHelper::testUF1(n);
	UnionFindTestHelper::testUF2(n);
	UnionFindTestHelper::testUF3(n);
}

int main()
{
	//test_heap();
	//test_heapSort();
	//test_binarySearchTree();
	test_unionFind();
	return 0;
}