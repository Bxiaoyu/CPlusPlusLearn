#include <iostream>
#include <functional>

using namespace std;

// �ڽ������º���

// negate һԪ�º��� ȡ���º���
void test_negate()
{
	negate<int> n;
	cout << n(10) << endl;
}

// plus ��Ԫ�º��� �ӷ�
void test_plus()
{
	plus<int>p;
	cout << p(10, 20) << endl;
}

//int main()
//{
//	test_negate();
//	test_plus();
//
//	return 0;
//}
