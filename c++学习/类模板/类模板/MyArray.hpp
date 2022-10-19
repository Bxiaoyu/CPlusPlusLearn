#pragma once
#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class MyArray {
public:
	// 有参构造
	MyArray(int capacity)
	{
		//cout << "MyArray有参构造调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	// 拷贝构造函数
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray拷贝构造调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;

		// 深拷贝
		this->pAddress = new T[arr.m_Capacity];
		// 将arr中的元素拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	// operator= 防止浅拷贝
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "MyArray operator= 调用" << endl;
		// 先判断原来堆区是否有数据，如果有先释放
		if (this->pAddress != nullptr)
		{
			delete[] this->pAddress;
			this->pAddress = nullptr;

			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;

		// 深拷贝
		this->pAddress = new T[arr.m_Capacity];
		// 将arr中的元素拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}

	// 析构函数
	~MyArray()
	{
		//cout << "MyArray析构函数调用" << endl;
		if (this->pAddress != nullptr)
		{
			delete[] this->pAddress;
			this->pAddress = nullptr;
		}
	}

	// 尾插法
	void push_back(const T& val)
	{
		// 判断容量是否满
		if (this->m_Size == this->m_Capacity)
			return;
		this->pAddress[this->m_Size] = val; // 将数据插入到数组末尾
		this->m_Size++; // 更新数组当前元素个数
	}

	// 尾删法
	void pop_back()
	{
		// 让用户访问不到最后一个元素，即为尾删
		if (this->m_Size == 0)
			return;
		this->m_Size--;
	}

	// 通过下标方式访问
	T& operator[](int index)
	{
		// 判断下标合法性
		assert(index >= 0 && index < this->m_Size);
		// 返回值
		return this->pAddress[index];
	}

	// 返回数组容量
	int get_capacity()
	{
		return this->m_Capacity;
	}

	// 返回数组大小
	int get_size()
	{
		return this->m_Size;
	}
private:
	T* pAddress;    // 指针指向堆区开辟的真实数组

	int m_Capacity; // 数组容量

	int m_Size;     // 数组大小
};