#include <iostream>

using namespace std;

// ��ͨ����
int myAdd01(int a, int b)
{
	return a + b;
}

// ����ģ��
template<typename T>
int myAdd02(int a, int b)
{
	return a + b;
}

void test_func()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	// 1.��ͨ��������ʱ���Է����Զ�����ת������ʽ����ת����
	cout << myAdd01(a, c) << endl;

	// 2.����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
	//cout << myAdd02(a, c) << endl; // ����

	// 3.���ʹ����ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��
	cout << myAdd02<int>(a, c) << endl;
}

//int main()
//{
//	test_func();
//	return 0;
//}