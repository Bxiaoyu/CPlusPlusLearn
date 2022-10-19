#include <iostream>

using namespace std;

// 多继承语法
class Base1 {
public:
	Base1()
	{
		m_A = 100;
	}
public:
	int m_A;
};

class Base2 {
public:
	Base2()
	{
		m_A = 200;
	}

public:
	int m_A;
};

// 子类，需要继承Base1和Base2
class Son :public Base1, public Base2 {
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}

public:
	int m_C;
	int m_D;
};

// 测试多继承
void test_multiple_inheritance()
{
	Son s;
	cout << "sizeof Son: " << sizeof(s) << endl;
	// 当父类中出现同名成员，需要加作用域区分

	cout << "Base1--m_A = " << s.Base1::m_A << endl;
	cout << "Base2--m_A = " << s.Base2::m_A << endl;
}

//int main()
//{
//	test_multiple_inheritance();
//	return 0;
//}

