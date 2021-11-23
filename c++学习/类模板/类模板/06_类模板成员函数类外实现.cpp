#include <iostream>

using namespace std;

template<typename T1, typename T2>
class Person {
public:
	Person(T1 name, T2 age);

	void showPerson();
public:
	T1 m_name;
	T2 m_age;
};

// 构造函数类外实现
template<typename T1, typename T2>
Person<T1, T2>::Person(T1 name, T2 age):m_name(name), m_age(age)
{
}

// 成员函数类外实现
template<typename T1, typename T2>
void Person<T1, T2>::showPerson()
{
	cout << "Name: " << m_name << "\tAge: " << m_age << endl;
}

//int main()
//{
//	Person<string, int> p("Tom", 22);
//	p.showPerson();
//	return 0;
//}