#include <iostream>

using namespace std;

// 普通函数
int myAdd01(int a, int b)
{
	return a + b;
}

// 函数模板
template<typename T>
int myAdd02(int a, int b)
{
	return a + b;
}

void test_func()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	// 1.普通函数调用时可以发生自动类型转换（隐式类型转换）
	cout << myAdd01(a, c) << endl;

	// 2.函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
	//cout << myAdd02(a, c) << endl; // 错误

	// 3.如果使用显示指定类型的方式，可以发生隐式类型转换
	cout << myAdd02<int>(a, c) << endl;
}

//int main()
//{
//	test_func();
//	return 0;
//}