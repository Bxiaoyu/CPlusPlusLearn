#include <iostream>
#include <functional>

using namespace std;

// 内建算数仿函数

// negate 一元仿函数 取反仿函数
void test_negate()
{
	negate<int> n;
	cout << n(10) << endl;
}

// plus 二元仿函数 加法
void test_plus()
{
	plus<int>p;
	cout << p(10, 20) << endl;
}

//int main()
//{
//	test_negate();
//	test_plus();
//
//	return 0;
//}
