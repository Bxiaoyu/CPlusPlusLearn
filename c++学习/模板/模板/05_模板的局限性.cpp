#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	Person(string name, int age) :m_name(name), m_age(age)
	{
	}

public:
	string m_name;
	int m_age;
};

template<typename T>
bool myCompare(T& a, T& b)
{
	if (a != b)
		return false;
	return true;
}

// ���þ��廯��Person�������Ͱ汾��ʵ�ִ��룬���廯���ȵ���
template<> bool myCompare(Person& p1, Person& p2)
{
	if (p1.m_name == p2.m_name && p1.m_age == p2.m_age)
		return true;
	return false;
}


void test_myCompare()
{
	Person p1("Tom", 18);
	Person p2("Jack", 20);

	if (myCompare(p1, p2))
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}
}

int main()
{
	test_myCompare();
	return 0;
}