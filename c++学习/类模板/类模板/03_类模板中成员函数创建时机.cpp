#include <iostream>
#include <string>

using namespace std;

class Person1 {
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2 {
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<typename T>
class MyClass {
public:
	// 类模板中的成员函数调用时才创建
	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}
public:
	T obj;
};

void test_model()
{
	MyClass<Person1> m;
	m.func1();
	//m.func2(); // 编译会出错，说明函数调用才会去创建成员函数
}