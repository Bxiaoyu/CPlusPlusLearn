#include <iostream>
#include <string>

using namespace std;

// 设计一个学生类,属性有姓名和学号
// 可以给姓名和学号赋值，可以显示学生的姓名和学号

class Student {
public: // 公共权限
	// 行为，显示姓名和学号
	void show()
	{
		cout << "学号\t姓名" << endl;
		cout << m_id << "\t" << m_name << endl;
	}

	// 设置姓名
	void set_name(const string& name)
	{
		m_name = name;
	}

	// 设置ID
	void set_id(const string& id)
	{
		m_id = id;
	}

private: // 私有权限
	// 属性
	string m_name; // 姓名
	string m_id;   // 学号
};

class Person {
public:
	Person()
	{
		// 类内访问
		m_name = "张三";
		m_car = "奥迪";
		m_password = "123456";
	}
public:
	string m_name; // 姓名
protected:
	string m_car; // 车
private:
	string m_password; // 密码
};

class PersonInfo {
public:
	PersonInfo():m_name("张三"), m_age(38),m_lover("")
	{
		
	}

	// 设置姓名
	void set_name(const string& name)
	{
		m_name = name;
	}

	// 获取姓名
	string get_name()
	{
		return m_name;
	}

	// 设置年龄
	void set_age(const int age)
	{
		// 验证数据有效性
		if (age < 0 || age > 150)
		{
			m_age = 0;
			cout << "输入的年龄不合法" << endl;
			return;
		}
		m_age = age;
	}

	// 获取年龄
	int get_age()
	{
		return m_age;
	}

	// 设置情人
	void set_lover(const string& lover)
	{
		m_lover = lover;
	}
private:
	// 姓名，可读可写
	string m_name;
	// 年龄，只读
	int m_age;
	// 情人，只写
	string m_lover;
};

class People
{
public:
	// 默认构造
	People()
	{
		cout << "People的无参构造函数调用" << endl;
	}
	// 有参构造
	People(int a, int height)
	{
		m_age = a;
		m_height = new int(height);
		cout << "People的有参构造函数调用" << endl;
	}

	// 拷贝构造函数
	People(const People& p)
	{
		m_age = p.m_age;
		//m_height = p.m_height; // 浅拷贝，编译器默认实现就是这行代码
		m_height = new int(*p.m_height); // 深拷贝
		cout << "People的拷贝构造函数调用" << endl;
	}
	
	// 析构函数
	~People()
	{
		if (m_height != nullptr)
		{
			delete m_height;
			m_height = nullptr;
		}
		cout << "People的析构函数调用" << endl;
	}

public:
	int m_age;
	int *m_height;
};

void test01()
{
	People p(18, 180);
	People p1(p);
}

// 三种调用方式
void test()
{
	// 括号法
	People p1;     // 调用默认构造函数，不要加()，否则编译器会认为这是一个函数声明，不会认为是在创建对象
	People p2(10); // 有参构造函数
	People p3(p1); // 调用拷贝构造函数

	// 显示法
	People p4; // 调用默认构造函数，不要加()，否则编译器会认为这是一个函数声明，不会认为是在创建对象
	People p5 = People(10); // 有参构造函数
	People p6 = People(2); // 调用拷贝构造函数
	People(10); // 匿名对象 特点：当前行执行结束后，系统会立即回收匿名对象
	// 注意事项：不要利用拷贝构造函数初始化匿名对象，编译器会认为是对象声明，即： People(p3) == People p3;
	People(p6);// 错误

	// 隐式转换法
	People p7 = 10; // 调用有参构造，相当于写了 People p7  = People(10)
	People p8 = p7; // 调用拷贝构造
}

class Phone {
public:
	Phone(string name):m_phoneName(name)
	{
		cout << "Phone 构造哈数调用" << endl;
	}

public:
	string m_phoneName;
};

class Person1
{
public:
	// Phone m_phone = phone 隐式转换法
	Person1(string name, string phone):m_name(name), m_phone(phone)
	{
		cout << "Person 构造函数调用" << endl;
	}

public:
	string m_name;
	Phone m_phone;
};

class A {
public:
	// 静态成员函数
	static void func()
	{
		m_A = 100; // 正确 静态成员函数可以访问 静态成员变量
		//m_B = 10;  // 错误 静态成员函数不可以访问 非静态成员变量，因为编译器无法区分m_B到底是哪个对象的属性
		cout << "static void func 调用" << endl;
	}

private:
	// 私有静态成员函数
	static void func2()
	{
		cout << "static void func2 调用" << endl;
	}

public:
	static int m_A; // 静态成员变量
	int m_B; // 非静态成员变量

private:
	static int m_C;
};

int A::m_A = 0;
int A::m_C = 0;

void test2()
{
	// 1. 通过对象访问
	A a;
	a.func();
	// 2. 通过类名访问
	A::func();

	//a.func2();  // 错误 类外访问不到私有静态成员函数
	//A::func2(); // 错误 类外访问不到私有静态成员函数
}

class B {
public:
	void func() // 非静态成员函数 不属于类的对象
	{
	}

public:
	int m_a;        // 非静态成员变量 属于类的对象
	static int m_b; // 静态成员变量 不属于类的对象
};

void test3()
{
	B b;
	/*
	空对象占用内存空间为1
	C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	每个空对象也应该有一个独一无二的内存地址
	*/
	cout << "sizeof b = " << sizeof(b) << endl;
}

void test4()
{
	B b;
	cout << "sizeof b = " << sizeof(b) << endl;
}

void test5()
{
	B b;
	cout << "sizeof b = " << sizeof(b) << endl;
}

int main()
{
	// 创建一个学生实例对象
	Student s;
	// 设置信息
	s.set_name("张三");
	s.set_id("1001");
	// 显示信息
	s.show();

	// 创建实例化对象
	Person p;
	p.m_name = "李四";
	//p.m_car = "";      // 错误：保护权限内容，类外不可访问
	//p.m_password = ""; // 错误：私有权限内容，类外不可访问

	return 0;
}