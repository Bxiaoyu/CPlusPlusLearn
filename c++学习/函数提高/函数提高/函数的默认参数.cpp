#include <iostream>
using namespace std;

// Ĭ�ϲ�������
// ������Ǵ����Լ������ݣ������Լ������ݣ����û�У���ô����Ĭ��ֵ
int func(int a, int b = 20, int c = 30)
{
	return a + b + c;
}

// ���ĳ��λ��������Ĭ�ϲ�������ô�����λ�����󣬴����ұ�����Ĭ��ֵ
//int func2(int a, int b = 10, int c) // ����
//{
//}

// �������������Ĭ�ϲ���������ʵ�־Ͳ�����Ĭ�ϲ���
// ������ʵ��ֻ����һ����Ĭ�ϲ���
int func3(int a = 10, int b = 10);

//int func3(int a = 10, int b = 10) // ����
//{
//	return a + b;
//}

int func3(int a, int b) // ��ȷ
{
	return a + b;
}

//int main()
//{
//	cout << func(10) << endl;
//	return 0;
//}