#include <iostream>
using namespace std;

// �����ʽ1��ֱ�Ӱ���.cppԴ�ļ�
#include "person.hpp"

void test_mul()
{
	Person<string, int>p("Tom", 18);
	p.showPerson();
}

// �����ʽ2����������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp

//int main()
//{
//	test_mul();
//	return 0;
//}