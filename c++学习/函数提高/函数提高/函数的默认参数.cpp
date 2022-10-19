#include <iostream>
using namespace std;

// 默认参数函数
// 如果我们传入自己的数据，就用自己的数据，如果没有，那么就用默认值
int func(int a, int b = 20, int c = 30)
{
	return a + b + c;
}

// 如果某个位置已有了默认参数，那么从这个位置往后，从左到右必须有默认值
//int func2(int a, int b = 10, int c) // 错误
//{
//}

// 如果函数声明有默认参数，函数实现就不能有默认参数
// 声明和实现只能有一个有默认参数
int func3(int a = 10, int b = 10);

//int func3(int a = 10, int b = 10) // 错误
//{
//	return a + b;
//}

int func3(int a, int b) // 正确
{
	return a + b;
}

//int main()
//{
//	cout << func(10) << endl;
//	return 0;
//}