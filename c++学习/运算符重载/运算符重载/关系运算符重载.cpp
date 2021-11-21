#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	Person(string name, int age):m_name(name),m_age(age)
	{}

	// 重载 == 运算符
	bool operator==(Person& p)
	{
		if (this->m_name == p.m_name && this->m_age == p.m_age)
		{
			return true;
		}
		return false;
	}

	// 重载 != 运算符
	bool operator!=(Person& p)
	{
		if (this->m_name == p.m_name && this->m_age == p.m_age)
		{
			return false;
		}
		return true;
	}

public:
	string m_name;
	int m_age;
};

//int main()
//{
//	Person p1("Tom", 18);
//	Person p2("Tom", 18);
//
//	if (p1 == p2)
//	{
//		cout << "p1 和 p2是相等的!" << endl;
//	}
//
//	Person p3("Jack", 18);
//	if (p1 != p3)
//	{
//		cout << "p1 和 p3不相等!" << endl;
//	}
//
//	return 0;
//}