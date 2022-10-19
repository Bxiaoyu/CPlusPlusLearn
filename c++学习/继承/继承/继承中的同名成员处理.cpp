#include <iostream>

using namespace std;

class Base {
public:
	Base()
	{
		m_A = 100;
	}

	void func()
	{
		cout << "Base - func() ����" << endl;
	}

	void func(int a)
	{
		cout << "Base - func(int a) ����" << endl;
	}

public:
	int m_A;
};

class Son :public Base {
public:
	Son()
	{
		m_A = 200;
	}

	void func()
	{
		cout << "Son - func() ����" << endl;
	}

public:
	int m_A;
};

void test01()
{
	Son s;
	cout << "Son �� m_A = " << s.m_A << endl;
	cout << "Base �� m_A = " << s.Base::m_A << endl;

	s.func(); // ֱ�ӵ��ã����õ��������е�ͬ����Ա
	s.Base::func(); // ����������ø����е�ͬ����Ա

	// ��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա�����ص�����������ͬ����Ա����
	// �������ʵ������б����ص�ͬ����Ա��������Ҫ��������
	//s.func(100); // ����
	s.Base::func(100);
}

//int main()
//{
//	test01();
//	return 0;
//}