#include <iostream>

using namespace std;

// 打印类
class MyPrint {
public:
	// 重载函数调用运算符，也称仿函数
	void operator()(string text)
	{
		cout << text << endl;
	}
};

// 仿函数非常灵活，没有固定写法
// 加法类
class MyAdd {
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

int main()
{
	MyPrint mp;
	mp("hello world!");

	MyAdd md;
	int ret = md(100, 100);
	cout << "MyAdd result: " << ret << endl;

	// 匿名函数对象
	cout << "MyAdd()(100,100): " << MyAdd()(100, 100) << endl;

	return 0;
}