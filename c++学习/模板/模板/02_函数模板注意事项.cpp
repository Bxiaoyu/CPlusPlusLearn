#include <iostream>

using namespace std;

// 1.�Զ������Ƶ��������Ƶ���һ�µ���������T���ſ���ʹ��
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	float c = 2.0;
	mySwap(a, b); // ��ȷ
	//mySwap(a, c); // �����Ƶ�����һ�µ�T
}


// 2.ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
template<typename T>
void func()
{
	cout << "func����" << endl;
}

void test02()
{
	//func(); // ������˵û�õ�T���ͣ�����ҲҪָ�����ͣ������Զ������Ƶ��Ƶ�������������
	func<int>(); // ��ȷ�����ָ��һ��ȷ�������ͣ������Ϳ�����������
}