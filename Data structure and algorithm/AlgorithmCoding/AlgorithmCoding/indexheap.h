#pragma once
#include <iostream>
#include <algorithm>
#include <cassert>

/*
	��������ѣ�������ʱ������������������ܺͷ������
	index 1  2  3
	data  15 20 32
*/
using namespace std;

template<class Item>
class IndexMaxHeap
{
private:
	Item* data;   // �洢��������
	int* indexes; // ����data������
	int* reverse; // ����indexes������
	int count;
	int capacity;

private:
	// �������϶ѻ�
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

	// �������¶ѻ�
	void shiftDown(int k)
	{
		// ����ȫ�������У�ֻ���ж��������ӽڵ��Ƿ�������һ�����У��˴��ж����Ƿ��������
		while (2 * k <= count)
		{
			int j = 2 * k;  // �ڴ���ѭ���У�data[k]��data[j]����λ��
			if (j + 1 <= count && data[indexes[j + 1]] > data[indexes[j]])  // �ж��Һ����Ƿ��������
			{
				j += 1;
			}

			if (data[indexes[k]] >= data[indexes[j]])  // ������ڵ�����Һ��ӽڵ㶼����ô�����ѻ�
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
		data = new Item[capacity + 1];  // ���ݴ洢���±�1��ʼ�����Ǵ�0��ʼ������Ҫ��1
		indexes = new int[capacity + 1]; // ��������
		reverse = new int[capacity + 1]; // ��������
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

	// �����index�����û����ԣ��Ǵ�0��ʼ������
	void insert(int index, Item item)
	{
		assert(count + 1 <= capacity);
		assert(index + 1 >= 1 && index + 1 <= capacity);
		index += 1;
		data[index] = item;
		indexes[count + 1] = index;  // �����ݷ�����������ĩβ
		reverse[index] = count + 1;
		count++;  // count�ƶ����²��������λ��
		shiftUp(count);  // �������϶ѻ����������ѽṹ
	}

	Item extractMax()
	{
		assert(count > 0);
		Item ret = data[indexes[1]];

		swap(indexes[1], indexes[count]); // ��һ��Ԫ�غ����һ��Ԫ�ؽ���
		reverse[indexes[1]] = 1;
		reverse[indexes[count]] = 0;
		count--;
		shiftDown(1);  // �������¶ѻ����������ѽṹ
		return ret;
	}	
	
	int extractMaxIndex()
	{
		assert(count > 0);
		int ret = indexes[1] - 1;

		swap(indexes[1], indexes[count]); // ��һ��Ԫ�غ����һ��Ԫ�ؽ���
		reverse[indexes[1]] = 1;
		reverse[indexes[count]] = 0;
		count--;
		shiftDown(1);  // �������¶ѻ����������ѽṹ
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

		// �ҵ�indexes[j] = index��j��ʾdata[index]�ڶ��е�λ��
		// ֮��shiftUp(j)����shiftDown(j)
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
	// ����״��ӡ�����ѽṹ
	void testPrint() {

		// ���ǵ�testPrintֻ�ܴ�ӡ100��Ԫ�����ڵĶѵ���״��Ϣ
		if (size() >= 100) {
			cout << "This print function can only work for less than 100 int";
			return;
		}

		// ���ǵ�testPrintֻ�ܴ���������Ϣ
		if (typeid(Item) != typeid(int)) {
			cout << "This print function can only work for int item";
			return;
		}

		cout << "The max heap size is: " << size() << endl;
		cout << "Data in the max heap: ";
		for (int i = 1; i <= size(); i++) {
			// ���ǵ�testPrintҪ����е�����������[0, 100)�ķ�Χ��
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