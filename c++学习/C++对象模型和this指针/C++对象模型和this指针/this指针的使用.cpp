#include <iostream>

using namespace std;

class Person {
public:
	Person(int age)
	{
		// thisָ��ָ�� �����õĳ�Ա���������Ķ���
		// ���βκͳ�Ա����ͬ��ʱ��������thisָ�������֣�������Ƴ�ͻ
		this->age = age;
	}

	// Ҫʵ����ʽ���ã�Ҫ���ض������ã����ܷ���ֵ
	Person& addAge(const Person& p)
	{
		this->age += p.age;
		// thisָ��p2��ָ�룬��*thisָ��ľ���p2���������
		return *this;
	}

public:
	int age;
};

void test()
{
	Person p1(20);
	Person p2(20);

	// ��ʽ���˼��
	p2.addAge(p1).addAge(p1).addAge(p1);

	cout << "p2������Ϊ��" << p2.age << endl;
}