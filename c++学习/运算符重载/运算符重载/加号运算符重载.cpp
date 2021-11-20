#include <iostream>

using namespace std;

class Person {
public:
	// 成员函数重载+号运算符
	Person operator+(Person& p)
	{

	}
public:
	int m_A;
	int m_B;
};

// 全局函数重载+号运算符
Person operator+(Person& p1, Person& p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
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
}