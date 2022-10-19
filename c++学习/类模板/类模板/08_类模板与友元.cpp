#include <iostream>

using namespace std;

// 提前让编译器知道Person类的存在
template<typename T1, typename T2>
class Person;

// 2.全局函数类外实现
template<typename T1, typename T2>
void printPerson2(Person<T1, T2> p)
{
	cout << endl << "类外实现：" << endl;
	cout << "Name: " << p.m_name << "\tAge: " << p.m_age << endl;
}

// 通过全局函数打印Person信息
template<typename T1, typename T2>
class Person {
	// 1.全局函数类内实现
	friend void printPerson(Person<T1, T2> p)
	{
		cout << "Name: " << p.m_name << "\tAge: " << p.m_age << endl;
	}

	// 2.全局函数类外实现，需要提前让编译器知道全局函数的存在
	// 加一个空模板的参数列表
	friend void printPerson2<>(Person<T1, T2> p);
public:
	Person(T1 name, T2 age):m_name(name), m_age(age)
	{
	}

private:
	T1 m_name;
	T2 m_age;
};

// 1.全局函数类内实现
void test_inner()
{
	Person<string, int> p("Tom", 20);
	printPerson(p);
}

void test_outer()
{
	Person<string, int> p("Jack", 18);
	printPerson2(p);
}

//int main()
//{
//	test_inner();
//	test_outer();
//	return 0;
//}