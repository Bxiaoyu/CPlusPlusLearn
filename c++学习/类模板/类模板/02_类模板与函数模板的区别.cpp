#include <iostream>
#include <string>

using namespace std;

template<typename NameType, typename AgeType=int>
class Person {
public:
	Person(NameType name, AgeType age):m_name(name), m_age(age)
	{
	}

	void showPerson()
	{
		cout << "Name: " << m_name << "\tAge: " << m_age << endl;
	}

public:
	NameType m_name;
	AgeType m_age;
};

// 1. 类模板没有自动类型推导的使用方式
void test011()
{
	//Person p("悟空", 1000); // 错误，无法用自动类型推导

	Person<string, int> p("悟空", 1000);
	p.showPerson();
}

// 2.类模板在模板参数列表中可以有默认参数
void test012()
{
	Person<string> p("八戒", 999);
	p.showPerson();
}

//int main()
//{
//	test011();
//	test012();
//	return 0;
//}