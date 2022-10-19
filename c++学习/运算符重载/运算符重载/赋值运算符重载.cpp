#include <iostream>

using namespace std;

class Person {
public:
	Person(int age)
	{
		m_age = new int(age);
	}

	~Person()
	{
		if (m_age != nullptr)
		{
			delete m_age;
			m_age = nullptr;
		}
	}

	// ���ظ�ֵ�����
	Person& operator=(Person& p)
	{
		// ���������ṩǳ����
		//m_age = p.m_age;

		// Ӧ�����ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ�������
		if (m_age != nullptr)
		{
			delete m_age;
			m_age = nullptr;
		}

		// ���
		m_age = new int(*p.m_age);

		// ���ض�����
		return *this;
	}

public:
	int* m_age;
};

//int main()
//{
//	Person p1(18);
//	Person p2(20);
//	Person p3(25);
//
//	p3 = p2 = p1; // ��ֵ��������ʽ����
//
//	cout << "p1������Ϊ��" << *p1.m_age << endl;
//	cout << "p2������Ϊ��" << *p2.m_age << endl;
//	cout << "p3������Ϊ��" << *p3.m_age << endl;
//
//	return 0;
//}