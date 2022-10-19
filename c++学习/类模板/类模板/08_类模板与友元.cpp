#include <iostream>

using namespace std;

// ��ǰ�ñ�����֪��Person��Ĵ���
template<typename T1, typename T2>
class Person;

// 2.ȫ�ֺ�������ʵ��
template<typename T1, typename T2>
void printPerson2(Person<T1, T2> p)
{
	cout << endl << "����ʵ�֣�" << endl;
	cout << "Name: " << p.m_name << "\tAge: " << p.m_age << endl;
}

// ͨ��ȫ�ֺ�����ӡPerson��Ϣ
template<typename T1, typename T2>
class Person {
	// 1.ȫ�ֺ�������ʵ��
	friend void printPerson(Person<T1, T2> p)
	{
		cout << "Name: " << p.m_name << "\tAge: " << p.m_age << endl;
	}

	// 2.ȫ�ֺ�������ʵ�֣���Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
	// ��һ����ģ��Ĳ����б�
	friend void printPerson2<>(Person<T1, T2> p);
public:
	Person(T1 name, T2 age):m_name(name), m_age(age)
	{
	}

private:
	T1 m_name;
	T2 m_age;
};

// 1.ȫ�ֺ�������ʵ��
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