#include <iostream>

using namespace std;

// ��������ע������
// 1.������Ϊ��������
void func_attention(int& a)
{
	cout << "func(int& a)����" << endl;
}

void func_attention(const int& a)
{
	cout << "func(const int& a)����" << endl;
}

// 2.������������Ĭ�ϲ���������ֶ����ԣ��ᱨ��Ҫ����
void func_attention2(int a, int b = 10)
{
	cout << "func_attention2(int a, int b = 10)����" << endl;
}

void func_attention2(int a)
{
	cout << "func_attention2(int a)����" << endl;
}

int main()
{
	int a = 10;
	func_attention(a);
	func_attention(10);

	//func_attention2(a); // ���󣺺�����������Ĭ�ϲ���������ֶ����ԣ���������֪�������ĸ�������
	func_attention2(10, 20); // ��������
	return 0;
}