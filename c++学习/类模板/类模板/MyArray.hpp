#pragma once
#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class MyArray {
public:
	// �вι���
	MyArray(int capacity)
	{
		//cout << "MyArray�вι������" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	// �������캯��
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray�����������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;

		// ���
		this->pAddress = new T[arr.m_Capacity];
		// ��arr�е�Ԫ�ؿ�������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	// operator= ��ֹǳ����
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "MyArray operator= ����" << endl;
		// ���ж�ԭ�������Ƿ������ݣ���������ͷ�
		if (this->pAddress != nullptr)
		{
			delete[] this->pAddress;
			this->pAddress = nullptr;

			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;

		// ���
		this->pAddress = new T[arr.m_Capacity];
		// ��arr�е�Ԫ�ؿ�������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}

	// ��������
	~MyArray()
	{
		//cout << "MyArray������������" << endl;
		if (this->pAddress != nullptr)
		{
			delete[] this->pAddress;
			this->pAddress = nullptr;
		}
	}

	// β�巨
	void push_back(const T& val)
	{
		// �ж������Ƿ���
		if (this->m_Size == this->m_Capacity)
			return;
		this->pAddress[this->m_Size] = val; // �����ݲ��뵽����ĩβ
		this->m_Size++; // �������鵱ǰԪ�ظ���
	}

	// βɾ��
	void pop_back()
	{
		// ���û����ʲ������һ��Ԫ�أ���Ϊβɾ
		if (this->m_Size == 0)
			return;
		this->m_Size--;
	}

	// ͨ���±귽ʽ����
	T& operator[](int index)
	{
		// �ж��±�Ϸ���
		assert(index >= 0 && index < this->m_Size);
		// ����ֵ
		return this->pAddress[index];
	}

	// ������������
	int get_capacity()
	{
		return this->m_Capacity;
	}

	// ���������С
	int get_size()
	{
		return this->m_Size;
	}
private:
	T* pAddress;    // ָ��ָ��������ٵ���ʵ����

	int m_Capacity; // ��������

	int m_Size;     // �����С
};