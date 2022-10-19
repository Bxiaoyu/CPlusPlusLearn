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

// 1. ��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
void test011()
{
	//Person p("���", 1000); // �����޷����Զ������Ƶ�

	Person<string, int> p("���", 1000);
	p.showPerson();
}

// 2.��ģ����ģ������б��п�����Ĭ�ϲ���
void test012()
{
	Person<string> p("�˽�", 999);
	p.showPerson();
}

//int main()
//{
//	test011();
//	test012();
//	return 0;
//}