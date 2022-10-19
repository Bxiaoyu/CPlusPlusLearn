#include <iostream>

using namespace std;

class Person {
public:
	// this 指针的本质是 指针常量 指针的指向是不可以修改的
	// const Person * const this;
	// 在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
	void showPerson() const
	{
		//this->m_A = 100; // 错误 常函数中this指针指向的值不可以改变
		//this = nullptr; // 错误 this指针不可以修改指针的指向
	}
	void func()
	{
	}

public:
	int m_A;
	mutable int m_B; // 特殊变量，即使在常函数和常对象中，也可以修改这个值
};

void test()
{
	const Person p; // 常对象
	//p.m_A = 10; // 错误
	p.m_B = 10; // 正确 m_B是特殊值，在常对象下也可以修改

	// 常对象只能调用常函数
	//p.func(); // 错误 常对象不可以调用普通的成员函数，因为普通成员函数可以修改成员属性
	p.showPerson(); // 正确
}