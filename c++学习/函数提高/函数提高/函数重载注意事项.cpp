#include <iostream>

using namespace std;

// 函数重载注意事项
// 1.引用作为重载条件
void func_attention(int& a)
{
	cout << "func(int& a)调用" << endl;
}

void func_attention(const int& a)
{
	cout << "func(const int& a)调用" << endl;
}

// 2.函数重载碰到默认参数，会出现二义性，会报错，要避免
void func_attention2(int a, int b = 10)
{
	cout << "func_attention2(int a, int b = 10)调用" << endl;
}

void func_attention2(int a)
{
	cout << "func_attention2(int a)调用" << endl;
}

int main()
{
	int a = 10;
	func_attention(a);
	func_attention(10);

	//func_attention2(a); // 错误：函数重载碰到默认参数，会出现二义性，编译器不知道该找哪个函数了
	func_attention2(10, 20); // 可以运行
	return 0;
}