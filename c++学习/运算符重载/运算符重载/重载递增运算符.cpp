#include <iostream>

using namespace std;

class MyInteger {
	friend ostream& operator<<(ostream& out, MyInteger mi);
public:
	MyInteger()
	{
		m_num = 0;
	}

	// 重载前置++运算符，前置递增返回引用
	// 返回引用是为了一直对一个数据进行递增操作
	MyInteger& operator++()
	{
		// 先进行++运算
		m_num++;
		// 再将自身做返回
		return *this;
	}

	// 重载后置++运算符，后置递增返回值
	// void operator++(int) int代表占位参数，可以用于区分前置和后置递增
	MyInteger operator++(int)
	{
		// 先记录当时结果
		MyInteger temp = *this;
		//后递增
		m_num++;
		// 最后将记录结果返回
		return temp;
	}
private:
	int m_num;
};

// 重载<<运算符
ostream& operator<<(ostream& out, MyInteger mi)
{
	out << mi.m_num;
	return out;
}

// 测试前置++
void test01()
{
	MyInteger mi;
	cout << "前置++" << endl;
	cout << ++(++mi) << endl;
	cout << mi << endl;
}

// 测试后置++
void test02()
{
	MyInteger mi;
	cout << "后置++" << endl;
	cout << mi++ << endl;
	cout << mi << endl;
}

//int main()
//{
//	test01();
//	test02();
//
//	return 0;
//}