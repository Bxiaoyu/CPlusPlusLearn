#include <iostream>
#include <string>

using namespace std;

// ȫ�ֱ���
int g_a = 10;
int g_b = 10;

// ȫ�ֳ���
const int c_g_a = 10;
const int c_g_b = 10;

// ����
void test()
{
	// �ֲ�����
	int l_a = 10;
	int l_b = 10;
	cout << "�ֲ����� l_a �ĵ�ַΪ��" << &l_a << endl;
	cout << "�ֲ����� l_b �ĵ�ַΪ��" << &l_b << endl;

	cout << "ȫ�ֱ��� g_a �ĵ�ַΪ��" << &g_a << endl;
	cout << "ȫ�ֱ��� g_b �ĵ�ַΪ��" << &g_b << endl;

	// ��̬����
	static int s_a = 10;
	static int s_b = 10;
	cout << "��̬���� s_a �ĵ�ַΪ��" << &s_a << endl;
	cout << "��̬���� s_b �ĵ�ַΪ��" << &s_b << endl;


	/*
		������
			1.�ַ�������
			2.const ���εı�����
				2.1 const ���εľֲ�����
				2.2 const ���ε�ȫ������
	*/
	cout << "�ַ��������ĵ�ַΪ��" << &"hello world" << endl;

	// const ���ε�ȫ�ֱ���
	cout << "ȫ�ֳ��� c_g_a �ĵ�ַΪ��" << &c_g_a << endl;
	cout << "ȫ�ֳ��� c_g_b �ĵ�ַΪ��" << &c_g_b << endl;

	// const ���εľֲ�����
	const int c_l_a = 10;
	const int c_l_b = 10;

	cout << "�ֲ����� c_l_a �ĵ�ַΪ��" << &c_l_a << endl;
	cout << "�ֲ����� c_l_b �ĵ�ַΪ��" << &c_l_b << endl;
}

// ���Է��ؾֲ�������ַ�������н�ֹ��ô����
int* func()
{
	int a = 10;  // �ֲ����������ջ����ջ���������ں���ִ����ɺ��Զ��ͷ�
	return &a;   // ���ؾֲ������ĵ�ַ
}

// �ڶ��������ڴ棬���ض������ݵ�ַ
int* func2()
{
	// ����new�ؼ��֣����Խ����ݿ��ٵ�����
	// ָ�� ����Ҳ�Ǿֲ�����������ջ����ָ�뱣��������Ƿ��ڶ���
	int *p = new int(10);
	return p;
}

int main()
{
	// ����func��������ֵ
	int *p = func();

	cout << "*p = " << *p << endl; // ��һ�ο��Դ�ӡ��ȷֵ������Ϊ���������˱���
	cout << "*p = " << *p << endl; // �ڶ���������־Ͳ�������

	int *p1 = func2();
	cout << "*p1 = " << *p1 << endl;
	cout << "*p1 = " << *p1 << endl;
	return 0;
}