#include <iostream>

using namespace std;

// ������������
// 1.ͬһ��������
// 2.����������ͬ
// 3.��������`���Ͳ�ͬ`����`������ͬ`����`˳��ͬ`
void func_override()
{
	cout << "func����" << endl;
}

void func_override(int  a)
{
	cout << "func(int a)����" << endl;
}

void func_override(double a)
{
	cout << "func(double a)����" << endl;
}

void func_override(int a, double b)
{
	cout << "func(int a, double b)����" << endl;
}

void func_override(double a, int b)
{
	cout << "func(double a, int b)����" << endl;
}

// ע�⣺�����ķ���ֵ��������Ϊ�������ص�����
//int func_override(double a, int b) // ����
//{
//	cout << "func(double a, int b)����" << endl;
//}