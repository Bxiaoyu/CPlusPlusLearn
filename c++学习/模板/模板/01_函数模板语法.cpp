#include <iostream>

using namespace std;

// 声明一个函数模板
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	// 两种方式使用函数模板
//	// 1.自动类型推导
//	mySwap(a, b);
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//
//	// 2.显示指定类型
//	int c = 20;
//	int d = 30;
//	mySwap<int>(c, d);
//	cout << "c = " << c << endl;
//	cout << "d = " << d << endl;
//	
//	return 0;
//}