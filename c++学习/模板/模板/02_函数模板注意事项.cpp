#include <iostream>

using namespace std;

// 1.自动类型推导，必须推导出一致的数据类型T，才可以使用
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	float c = 2.0;
	mySwap(a, b); // 正确
	//mySwap(a, c); // 错误，推到不出一致的T
}


// 2.模板必须要确定出T的数据类型，才可以使用
template<typename T>
void func()
{
	cout << "func调用" << endl;
}

void test02()
{
	//func(); // 错误，虽说没用到T类型，但是也要指定类型，所以自动类型推导推导不出来，报错
	func<int>(); // 正确，随便指定一个确定的类型，这样就可以正常调用
}