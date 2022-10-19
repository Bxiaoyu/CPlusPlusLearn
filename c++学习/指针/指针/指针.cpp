#include <iostream>
#include <string>

using namespace std;

// 指针定义
void define_pointer()
{
	int a = 10; // 定义整形变量a
	int* p = &a; // 定义指针p，记录变量a的地址

	cout << "a的地址：" << &a << endl;
	cout << "指针p为：" << p << endl;

	// 使用指针
	// 指针前加 * 代表解引用，找到指针指向的内存中的数据
	cout << "*p=" << *p << endl;

	*p = 20;
	cout << "a=" << a << endl;
	cout << "*p=" << *p << endl;
}

// 指针所占空间大小
void pointer_size()
{
	cout << "sizeof(int*) = " << sizeof(int*) << endl;
	cout << "sizeof(float*) = " << sizeof(float*) << endl;
	cout << "sizeof(double*) = " << sizeof(double*) << endl;
	cout << "sizeof(char*) = " << sizeof(char*) << endl;
	cout << "sizeof(string*) = " << sizeof(string*) << endl;
}

// 空指针
void empty_pointer()
{
	// 1.空指针用于初始化指针变量
	int *p = nullptr;

	// 2.空指针不可以进行访问
	// 0~255之间的内存编号是系统占用的，因此不可以访问
	*p = 100; // 错误，执行会出错
}

// 野指针
void wild_pointer()
{
	// 野指针
	// 在程序中要避免这种情况
	int *p = (int*)0x1100; // 随便指向一个地址
	cout << *p << endl; // 访问野指针报错
}

// const 和 指针
void const_and_pointer()
{
	int a = 10;
	int b = 10;
	// 1.const 修饰指针，常量指针
	// 指针指向可以更改，指针指向的值不能改
	const int* p = &a;
	p = &b; // 正确
	//*p = 20; // 错误

	// 2.const修饰常量，指针常量
	// 指针的指向不可以改，指针指向的值可以改
	int* const p1 = &a;
	*p1 = 20; // 正确
	//p1 = &b; // 错误

	// 3.const修饰指针和常量
	// 指针的指向和指针指向的值 都不可以改
	const int* const p2 = &a;
	//p2 = &b;  // 错误
	//*p2 = 20; // 错误
}

// 指针和数组
void pointer_and_array()
{
	int arr[5] = { 1,2,3,4,5 };
	// 利用指针访问数组
	int *p = arr;

	for (int i = 0; i < 5; i++)
	{
		cout << *p << endl;
		p++; // 指针偏移
	}
}

// 值传递
void swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 地址传递
void swap2(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 冒泡排序
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

// 打印
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