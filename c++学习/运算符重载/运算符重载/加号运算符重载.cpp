#include <iostream>

using namespace std;

class Person {
public:
	// 成员函数重载+号运算符
	Person operator+(Person& p)
	{
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
public:
	int m_A;
	int m_B;
};

// 全局函数重载+号运算符
//Person operator+(Person& p1, Person& p2)
//{
//	Person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}

// 函数重载（运算符重载也可以发生函数重载）
Person operator+(Person& p, int num)
{
	Person temp;
	temp.m_A = p.m_A + num;
	temp.m_B = p.m_B + num;
	return temp;
}

void test()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person p2;
	p2.m_A = 10;
	p2.m_B = 10;

	// 成员函数重载本质调用
	Person p3 = p1.operator+(p2);

	// 全局函数重载本质调用
	Person p4 = p1.operator+(p2);

	// 简化写法
	Person p5 = p1 + p2 + p2;
	cout << "p5 m_A = " << p5.m_A << endl;
	cout << "p5 m_B = " << p5.m_B << endl;

	Person p6 = p1 + 10;
}