#pragma once
#include <iostream>
#include <algorithm>
#include <cassert>

/*
	最大索引堆，构建堆时用索引构建，提高性能和方便查找
	index 1  2  3
	data  15 20 32
*/
using namespace std;

template<class Item>
class IndexMaxHeap
{
private:
	Item* data;   // 存储数据数组
	int* indexes; // 索引data的数组
	int* reverse; // 索引indexes的数组
	int count;
	int capacity;

private:
	// 从下往上堆化
	void shiftUp(int k)
	{
		while (k > 1 && data[indexes[k / 2]] < data[indexes[k]])
		{
			swap(indexes[k / 2], indexes[k]);
			reverse[indexes[k / 2]] = k / 2;
			reverse[indexes[k]] = k;
			k /= 2;
		}
	}

	// 从上往下堆化
	void shiftDown(int k)
	{
		// 在完全二叉树中，只需判断其左右子节点是否有其中一个就行，此处判断其是否存在左孩子
		while (2 * k <= count)
		{
			int j = 2 * k;  // 在此轮循环中，data[k]和data[j]交换位置
			if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]])  // 判断右孩子是否大于左孩子
			{
				j += 1;
			}

			if (data[indexes[k]] >= data[indexes[j]])  // 如果根节点比左右孩子节点都大，那么结束堆化
			{
				break;
			}

			swap(indexes[k], indexes[j]);
			reverse[indexes[k]] = k;
			reverse[indexes[j]] = j;
			k = j;
		}
	}

public:
	IndexMaxHeap(int capacity)
	{
		data = new Item[capacity + 1];  // 数据存储从下标1开始，不是从0开始，所以要加1
		indexes = new int[capacity + 1]; // 索引数组
		reverse = new int[capacity + 1]; // 索引数组
		for (int i = 0; i <= capacity; i++)
		{
			reverse[i] = 0;
		}
		count = 0;
		this->capacity = capacity;
	}

	~IndexMaxHeap()
	{
		delete[] data;
		delete[] indexes;
		delete[] reverse;
	}

	int size()
	{
		return count;
	}

	bool isEmpty()
	{
		return count == 0;
	}

	// 传入的index对于用户而言，是从0开始索引的
	void insert(int index, Item item)
	{
		assert(count + 1 <= capacity);
		assert(index + 1 >= 1 && index + 1 <= capacity);
		index += 1;
		data[index] = item;
		indexes[count + 1] = index;  // 将数据放在已有数据末尾
		reverse[index] = count + 1;
		count++;  // count移动到新插入的数据位置
		shiftUp(count);  // 从下往上堆化，保持最大堆结构
	}

	Item extractMax()
	{
		assert(count > 0);
		Item ret = data[indexes[1]];

		swap(indexes[1], indexes[count]); // 第一个元素和最后一个元素交换
		reverse[indexes[1]] = 1;
		reverse[indexes[count]] = 0;
		count--;
		shiftDown(1);  // 从上往下堆化，保持最大堆结构
		return ret;
	}	
	
	int extractMaxIndex()
	{
		assert(count > 0);
		int ret = indexes[1] - 1;

		swap(indexes[1], indexes[count]); // 第一个元素和最后一个元素交换
		reverse[indexes[1]] = 1;
		reverse[indexes[count]] = 0;
		count--;
		shiftDown(1);  // 从上往下堆化，保持最大堆结构
		return ret;
	}

	bool contain(int i)
	{
		assert(i + 1 >= 1 && i + 1 <= capacity);
		return reverse[i + 1] != 0;
	}

	Item getItem(int index)
	{
		assert(contain(index));
		return data[index + 1];
	}

	void change(int index, Item newItem)
	{
		assert(contain(index));
		index += 1;
		data[index] = newItem;

		// 找到indexes[j] = index，j表示data[index]在堆中的位置
		// 之后shiftUp(j)，再shiftDown(j)
		//for (int j = 1; j <= count; j++)
		//{
		//	if (indexes[j] == index)
		//	{
		//		shiftUp(j);
		//		shiftDown(j);
		//		return;
		//	}
		//}
		int j = reverse[index];
		shiftUp(j);
		shiftDown(j);
	}

private:
	void putNumberInLine(int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft) {

		int sub_tree_width = (cur_tree_width - 1) / 2;
		int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
		assert(offset + 1 < line.size());
		if (num >= 10) {
			line[offset + 0] = '0' + num / 10;
			line[offset + 1] = '0' + num % 10;
		}
		else {
			if (isLeft)
				line[offset + 0] = '0' + num;
			else
				line[offset + 1] = '0' + num;
		}
	}

	void putBranchInLine(string &line, int index_cur_level, int cur_tree_width) {

		int sub_tree_width = (cur_tree_width - 1) / 2;
		int sub_sub_tree_width = (sub_tree_width - 1) / 2;
		int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
		assert(offset_left + 1 < line.size());
		int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
		assert(offset_right < line.size());

		line[offset_left + 1] = '/';
		line[offset_right + 0] = '\\';
	}

public:
	// 以树状打印整个堆结构
	void testPrint() {

		// 我们的testPrint只能打印100个元素以内的堆的树状信息
		if (size() >= 100) {
			cout << "This print function can only work for less than 100 int";
			return;
		}

		// 我们的testPrint只能处理整数信息
		if (typeid(Item) != typeid(int)) {
			cout << "This print function can only work for int item";
			return;
		}

		cout << "The max heap size is: " << size() << endl;
		cout << "Data in the max heap: ";
		for (int i = 1; i <= size(); i++) {
			// 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
			assert(data[i] >= 0 && data[i] < 100);
			cout << data[i] << " ";
		}
		cout << endl;
		cout << endl;

		int n = size();
		int max_level = 0;
		int number_per_level = 1;
		while (n > 0) {
			max_level += 1;
			n -= number_per_level;
			number_per_level *= 2;
		}

		int max_level_number = int(pow(2, max_level - 1));
		int cur_tree_max_level_number = max_level_number;
		int index = 1;
		for (int level = 0; level < max_level; level++) {
			string line1 = string(max_level_number * 3 - 1, ' ');

			int cur_level_number = min(count - int(pow(2, level)) + 1, int(pow(2, level)));
			bool isLeft = true;
			for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++) {
				putNumberInLine(data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
				isLeft = !isLeft;
			}
			cout << line1 << endl;

			if (level == max_level - 1)
				break;

			string line2 = string(max_level_number * 3 - 1, ' ');
			for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
				putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
			cout << line2 << endl;

			cur_tree_max_level_number /= 2;
		}
	}
};