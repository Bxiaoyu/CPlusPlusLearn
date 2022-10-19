#include <iostream>

using namespace std;

void myPrint(int a, int b)
{
	cout << "������ͨ����" << endl;
}

template<typename T>
void myPrint(T a, T b)
{
	cout << "���ú���ģ��" << endl;
}

template<typename T>
void myPrint(T a, T b, T c)
{
	cout << "�������غ���ģ��" << endl;
}

void test_normal()
{
	int a = 10;
	int b = 20;
	// 1.�������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
	myPrint(a, b);

	// 2.����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
	myPrint<>(a, b);

	// 3.����ģ��Ҳ���Է�������
	myPrint(a, b, 10);

	// 4.�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
	char c = 'c';
	char d = 'd';
	myPrint(c, d);
}

//int main()
//{
//	test_normal();
//	return 0;
//}