#include <iostream>
#include <string>

using namespace std;

// ָ�붨��
void define_pointer()
{
	int a = 10; // �������α���a
	int* p = &a; // ����ָ��p����¼����a�ĵ�ַ

	cout << "a�ĵ�ַ��" << &a << endl;
	cout << "ָ��pΪ��" << p << endl;

	// ʹ��ָ��
	// ָ��ǰ�� * ��������ã��ҵ�ָ��ָ����ڴ��е�����
	cout << "*p=" << *p << endl;

	*p = 20;
	cout << "a=" << a << endl;
	cout << "*p=" << *p << endl;
}

// ָ����ռ�ռ��С
void pointer_size()
{
	cout << "sizeof(int*) = " << sizeof(int*) << endl;
	cout << "sizeof(float*) = " << sizeof(float*) << endl;
	cout << "sizeof(double*) = " << sizeof(double*) << endl;
	cout << "sizeof(char*) = " << sizeof(char*) << endl;
	cout << "sizeof(string*) = " << sizeof(string*) << endl;
}

// ��ָ��
void empty_pointer()
{
	// 1.��ָ�����ڳ�ʼ��ָ�����
	int *p = nullptr;

	// 2.��ָ�벻���Խ��з���
	// 0~255֮����ڴ�����ϵͳռ�õģ���˲����Է���
	*p = 100; // ����ִ�л����
}

// Ұָ��
void wild_pointer()
{
	// Ұָ��
	// �ڳ�����Ҫ�����������
	int *p = (int*)0x1100; // ���ָ��һ����ַ
	cout << *p << endl; // ����Ұָ�뱨��
}

// const �� ָ��
void const_and_pointer()
{
	int a = 10;
	int b = 10;
	// 1.const ����ָ�룬����ָ��
	// ָ��ָ����Ը��ģ�ָ��ָ���ֵ���ܸ�
	const int* p = &a;
	p = &b; // ��ȷ
	//*p = 20; // ����

	// 2.const���γ�����ָ�볣��
	// ָ���ָ�򲻿��Ըģ�ָ��ָ���ֵ���Ը�
	int* const p1 = &a;
	*p1 = 20; // ��ȷ
	//p1 = &b; // ����

	// 3.const����ָ��ͳ���
	// ָ���ָ���ָ��ָ���ֵ �������Ը�
	const int* const p2 = &a;
	//p2 = &b;  // ����
	//*p2 = 20; // ����
}

// ָ�������
void pointer_and_array()
{
	int arr[5] = { 1,2,3,4,5 };
	// ����ָ���������
	int *p = arr;

	for (int i = 0; i < 5; i++)
	{
		cout << *p << endl;
		p++; // ָ��ƫ��
	}
}

// ֵ����
void swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

// ��ַ����
void swap2(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// ð������
void bubble_sort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// ��ӡ
void printArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
}


int main()
{
	int arr[5] = { 10,2,1,25,0 };
	bubble_sort(arr, 5);
	printArray(arr, 5);
	return 0;
}