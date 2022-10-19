#include <iostream>

using namespace std;

// 函数占位参数
void func01(int a, int)
{
	cout << "this is func" << endl;
}

// 占位参数也可以有默认参数
void func02(int a, int = 10)
{
	cout << "this is func1" << endl;
}

//int main()
//{
//	func01(10, 20); // 占位参数必须填补
//	func02(10); // 占位参数有默认参数
//	return 0;
//}