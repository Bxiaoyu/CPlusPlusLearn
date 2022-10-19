#include <iostream>
#include <string>

using namespace std;

class MyAdd {
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

// 1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01()
{
	MyAdd add;
	cout << add(10, 20) << endl;
}

// 2.函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint {
public:
	MyPrint():m_count(0)
	{
	}

	void operator()(string text)
	{
		cout << text << endl;
		this->m_count++;
	}

public:
	int m_count; // 内部状态
};

void test02()
{
	MyPrint mp;
	mp("hello world!");
	mp("hello world!");
	mp("hello world!");
	mp("hello world!");
	mp("hello world!");

	cout << "MyPrint调用次数: " << mp.m_count << endl;
}

// 3.函数对象可以作为参数传递
void doPrint(MyPrint& mp, string text)
{
	mp(text);
}

void test03()
{
	MyPrint mp;
	doPrint(mp, "hello python");
}

//int main()
//{
//	test01();
//	test02();
//	test03();
//	return 0;
//}