#include <iostream>

using namespace std;

class Base {
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

// 公共继承
class Son1 :public Base {
public:
	void func()
	{
		m_a = 10; // 父类中的公共权限成员，到子类中依然是 公共权限
		m_b = 10; // 父类中的保护权限成员，到子类中依然是 保护权限
		//m_c = 10; // 父类中的私有权限成员，子类中访问不到
	}
};

//void test01()
//{
//	Son1 s;
//	s.m_a = 100;
//	//s.m_b = 100; // 到Son1中，m_b是保护权限，类外访问不到
//}

// 保护继承
class Son2 :protected Base {
public:
	void func()
	{
		m_a = 10; // 父类中的公共权限成员，到子类中变为 保护权限
		m_b = 10; // 父类中的保护权限成员，到子类中变为 保护权限
		//m_c = 10; // 父类中的私有权限成员，子类中访问不到
	}
};

//void test02()
//{
//	//Son2 s;
//	//s.m_a = 100; // 在Son2中，m_a变为保护权限，类外不可访问
//	//s.m_b = 100; // 在Son2中，m_b变为保护权限，类外不可访问
//}

// 私有继承
class Son3 :private Base {
public:
	void func()
	{
		m_a = 100; // 父类中公共成员，到子类中变为 私有成员
		m_b = 100; // 父类中保护成员，到子类中变为 私有成员
		//m_c = 100; // 父类中的私有权限成员，子类中访问不到
	}
};

class GrandSon :public Son3 {
public:
	void func()
	{
		//m_a = 1000; // 到了Son3中，m_a变为私有，即使是儿子，也访问不到
		//m_b = 1000; // 到了Son3中，m_b变为私有，即使是儿子，也访问不到
	}
};

//void test03()
//{
//	//Son3 s;
//	//s.m_a = 1000; // 在Son3中，m_a变为私有成员，类外访问不到
//	//s.m_b = 1000; // 在Son3中，m_B变为私有成员，类外访问不到
//	//s.m_c = 1000; // 父类中的私有权限成员，子类中访问不到
//}