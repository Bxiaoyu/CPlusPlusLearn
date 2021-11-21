#include <iostream>

using namespace std;

// �̳��е�ͬ����̬��Ա����ʽ
class Base {
public:
	static void func()
	{
		cout << "Base -- static void func()" << endl;
	}

	static void func(int a)
	{
		cout << "Base -- static void func(int a)" << endl;
	}
public:
	static int m_A;
};

int Base::m_A = 100;


class Son :public Base {
public:
	static void func()
	{
		cout << "Son -- static void func()" << endl;
	}
public:
	static int m_A;
};

int Son::m_A = 200;

// ͬ����̬��Ա����
void test_static_member()
{
	// 1.ͨ���������
	Son s;
	cout << "ͨ��������ʣ�" << endl;
	cout << "Son �� m_A = " << s.m_A << endl;
	cout << "Base �� m_A = " << s.Base::m_A << endl;

	// 2.ͨ����������
	cout << "ͨ���������ʣ�" << endl;
	cout << "Son �� m_A = " << Son::m_A << endl;
	// ��һ��::����ͨ�������ķ�ʽ���ʣ��ڶ���::������ʸ����������µ�����
	cout << "Base �� m_A = " << Son::Base::m_A << endl;
}

// ͬ����̬��Ա����
void test_static_func()
{
	// 1.ͨ���������
	Son s;
	s.func();
	s.Base::func();

	// 2.ͨ����������
	Son::func();
	Son::Base::func();
	// ������ֺ͸���ͬ���ľ�̬��Ա������Ҳ�����ظ����е�����ͬ����Ա����
	// �������ʸ����б����ص�ͬ����Ա��������Ҫ��������
	Son::Base::func(100);
}

//int main()
//{
//	test_static_member();
//	cout << endl;
//	test_static_func();
//	return 0;
//}