#include <iostream>
#include <string>

using namespace std;

template<typename T1, typename T2>
class Person {
public:
	Person(T1 name, T2 age):m_name(name), m_age(age)
	{
	}

	void showPerson()
	{
		cout << "Name：" << m_name << "\tAge: " << m_age << endl;
	}
public:
	T1 m_name;
	T2 m_age;
};

// 1.指定传入类型
void printPerson1(Person<string, int>& p)
{
	p.showPerson();
}

void test_01()
{
	Person<string, int> p("悟空", 100);
	printPerson1(p);
}

// 2.参数模板化
template<typename T1, typename T2>
void printPerson2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << "T1的类型为：" << typeid(T1).name() << endl;
	cout << "T2的类型为：" << typeid(T2).name() << endl;
}

void test_02()
{
	Person<string, int> p("八戒", 99);
	printPerson2(p);
}

// 3.整个类模板化
template<typename T>
void printPerson3(T& p)
{
	p.showPerson();
	cout << "T的数据类型为：" << typeid(T).name() << endl;
}

void test_03()
{
	Person<string, int> p("唐僧", 30);
	printPerson3(p);
}

//int main()
//{
//	test_01();
//	test_02();
//	test_03();
//	return 0;
//}