#include <iostream>

using namespace std;

// ����ռλ����
void func01(int a, int)
{
	cout << "this is func" << endl;
}

// ռλ����Ҳ������Ĭ�ϲ���
void func02(int a, int = 10)
{
	cout << "this is func1" << endl;
}

//int main()
//{
//	func01(10, 20); // ռλ���������
//	func02(10); // ռλ������Ĭ�ϲ���
//	return 0;
//}