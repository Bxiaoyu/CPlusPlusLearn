#include <iostream>

using namespace std;

// ����һ������ģ��
template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	// ���ַ�ʽʹ�ú���ģ��
//	// 1.�Զ������Ƶ�
//	mySwap(a, b);
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//
//	// 2.��ʾָ������
//	int c = 20;
//	int d = 30;
//	mySwap<int>(c, d);
//	cout << "c = " << c << endl;
//	cout << "d = " << d << endl;
//	
//	return 0;
//}