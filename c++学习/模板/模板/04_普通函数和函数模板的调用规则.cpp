#include <iostream>

using namespace std;

void myPrint(int a, int b)
{
	cout << "调用普通函数" << endl;
}

template<typename T>
void myPrint(T a, T b)
{
	cout << "调用函数模板" << endl;
}

template<typename T>
void myPrint(T a, T b, T c)
{
	cout << "调用重载函数模板" << endl;
}

void test_normal()
{
	int a = 10;
	int b = 20;
	// 1.如果函数模板和普通函数都可以实现，优先调用普通函数
	myPrint(a, b);

	// 2.可以通过空模板参数列表来强制调用函数模板
	myPrint<>(a, b);

	// 3.函数模板也可以发生重载
	myPrint(a, b, 10);

	// 4.如果函数模板可以产生更好的匹配，优先调用函数模板
	char c = 'c';
	char d = 'd';
	myPrint(c, d);
}

//int main()
//{
//	test_normal();
//	return 0;
//}