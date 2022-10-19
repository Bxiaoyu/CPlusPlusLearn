#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Base {
public:
	T m;
};

// 1.当子类继承的父类是一个模板时，子类在声明的时候，要指定出父类中T的类型
// 如果不指定类型，编译器无法给子类分配内存
//class Son:public Base // 错误，必须要知道父类中T的类型，才能继承给子类
class Son :public Base<int>
{

};

// 2.如果想灵活的指出父类中T的类型，子类也需要变为类模板
template<typename T1, typename T2>
class Son2 :public Base<T2> {
public:
	Son2()
	{
		cout << "T1的类型为：" << typeid(T1).name() << endl;
		cout << "T2的类型为：" << typeid(T2).name() << endl;
	}
public:
	T1 obj;
};

void test_func()
{
	Son2<int, char> s;
}

//int main()
//{
//	test_func();
//	return 0;
//}