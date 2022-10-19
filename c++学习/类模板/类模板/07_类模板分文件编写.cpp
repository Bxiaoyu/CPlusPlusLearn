#include <iostream>
using namespace std;

// 解决方式1：直接包含.cpp源文件
#include "person.hpp"

void test_mul()
{
	Person<string, int>p("Tom", 18);
	p.showPerson();
}

// 解决方式2：将声明和实现写在同一个文件中，并更改后缀名为.hpp

//int main()
//{
//	test_mul();
//	return 0;
//}