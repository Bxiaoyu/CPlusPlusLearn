#include <iostream>

using namespace std;

class Person {
public:
	// this ָ��ı����� ָ�볣�� ָ���ָ���ǲ������޸ĵ�
	// const Person * const this;
	// �ڳ�Ա���������const�����ε���thisָ����ָ��ָ���ֵҲ�������޸�
	void showPerson() const
	{
		//this->m_A = 100; // ���� ��������thisָ��ָ���ֵ�����Ըı�
		//this = nullptr; // ���� thisָ�벻�����޸�ָ���ָ��
	}
	void func()
	{
	}

public:
	int m_A;
	mutable int m_B; // �����������ʹ�ڳ������ͳ������У�Ҳ�����޸����ֵ
};

void test()
{
	const Person p; // ������
	//p.m_A = 10; // ����
	p.m_B = 10; // ��ȷ m_B������ֵ���ڳ�������Ҳ�����޸�

	// ������ֻ�ܵ��ó�����
	//p.func(); // ���� �����󲻿��Ե�����ͨ�ĳ�Ա��������Ϊ��ͨ��Ա���������޸ĳ�Ա����
	p.showPerson(); // ��ȷ
}