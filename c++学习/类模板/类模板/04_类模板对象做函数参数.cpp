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
		cout << "Name��" << m_name << "\tAge: " << m_age << endl;
	}
public:
	T1 m_name;
	T2 m_age;
};

// 1.ָ����������
void printPerson1(Person<string, int>& p)
{
	p.showPerson();
}

void test_01()
{
	Person<string, int> p("���", 100);
	printPerson1(p);
}

// 2.����ģ�廯
template<typename T1, typename T2>
void printPerson2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << "T1������Ϊ��" << typeid(T1).name() << endl;
	cout << "T2������Ϊ��" << typeid(T2).name() << endl;
}

void test_02()
{
	Person<string, int> p("�˽�", 99);
	printPerson2(p);
}

// 3.������ģ�廯
template<typename T>
void printPerson3(T& p)
{
	p.showPerson();
	cout << "T����������Ϊ��" << typeid(T).name() << endl;
}

void test_03()
{
	Person<string, int> p("��ɮ", 30);
	printPerson3(p);
}

//int main()
//{
//	test_01();
//	test_02();
//	test_03();
//	return 0;
//}