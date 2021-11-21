#include <iostream>

using namespace std;

class Base {
public:
	Base()
	{
		m_A = 100;
	}

	void func()
	{
		cout << "Base - func() 调用" << endl;
	}

	void func(int a)
	{
		cout << "Base - func(int a) 调用" << endl;
	}

public:
	int m_A;
};

class Son :public Base {
public:
	Son()
	{
		m_A = 200;
	}

	void func()
	{
		cout << "Son - func() 调用" << endl;
	}

public:
	int m_A;
};

void test01()
{
	Son s;
	cout << "Son 的 m_A = " << s.m_A << endl;
	cout << "Base 的 m_A = " << s.Base::m_A << endl;

	s.func(); // 直接调用，调用的是子类中的同名成员
	s.Base::func(); // 加作用域调用父类中的同名成员

	// 如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
	// 如果想访问到父类中被隐藏的同名成员函数，需要加作用域
	//s.func(100); // 错误
	s.Base::func(100);
}

//int main()
//{
//	test01();
//	return 0;
//}