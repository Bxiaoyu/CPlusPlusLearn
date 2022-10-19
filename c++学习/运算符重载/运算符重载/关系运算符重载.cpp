#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	Person(string name, int age):m_name(name),m_age(age)
	{}

	// ���� == �����
	bool operator==(Person& p)
	{
		if (this->m_name == p.m_name && this->m_age == p.m_age)
		{
			return true;
		}
		return false;
	}

	// ���� != �����
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
//		cout << "p1 �� p2����ȵ�!" << endl;
//	}
//
//	Person p3("Jack", 18);
//	if (p1 != p3)
//	{
//		cout << "p1 �� p3�����!" << endl;
//	}
//
//	return 0;
//}