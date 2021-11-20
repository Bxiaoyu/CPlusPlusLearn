#include <iostream>

using namespace std;

class Person {
public:
	Person(int age)
	{
		// this指针指向 被调用的成员函数所属的对象
		// 当形参和成员变量同名时，可以用this指针来区分，解决名称冲突
		this->age = age;
	}

	// 要实现链式调用，要返回对象引用，不能返回值
	Person& addAge(const Person& p)
	{
		this->age += p.age;
		// this指向p2的指针，而*this指向的就是p2这个对象本体
		return *this;
	}

public:
	int age;
};

void test()
{
	Person p1(20);
	Person p2(20);

	// 链式编程思想
	p2.addAge(p1).addAge(p1).addAge(p1);

	cout << "p2的年龄为：" << p2.age << endl;
}