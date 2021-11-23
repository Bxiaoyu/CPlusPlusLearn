#include <iostream>

using namespace std;

template<class NameType, class AgeType>
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

void test01()
{
	Person<string, int> p("ÄÄß¸", 500);
	p.showPerson();
}

//int main()
//{
//	test01();
//	return 0;
//}