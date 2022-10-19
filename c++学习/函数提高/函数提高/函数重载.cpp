#include <iostream>

using namespace std;

// 函数重载条件
// 1.同一作用域下
// 2.函数名称相同
// 3.函数参数`类型不同`或者`个数不同`或者`顺序不同`
void func_override()
{
	cout << "func调用" << endl;
}

void func_override(int  a)
{
	cout << "func(int a)调用" << endl;
}

void func_override(double a)
{
	cout << "func(double a)调用" << endl;
}

void func_override(int a, double b)
{
	cout << "func(int a, double b)调用" << endl;
}

void func_override(double a, int b)
{
	cout << "func(double a, int b)调用" << endl;
}

// 注意：函数的返回值不可以作为函数重载的条件
//int func_override(double a, int b) // 错误
//{
//	cout << "func(double a, int b)调用" << endl;
//}