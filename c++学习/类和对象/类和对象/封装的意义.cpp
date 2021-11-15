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
	People(int a)
	{
		m_age = a;
		cout << "People的有参构造函数调用" << endl;
	}

	// 拷贝构造函数
	People(const People& p)
	{
		m_age = p.m_age;
		cout << "People的拷贝构造函数调用" << endl;
	}
	~People();

private:
	int m_age;
};

void test()
{

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