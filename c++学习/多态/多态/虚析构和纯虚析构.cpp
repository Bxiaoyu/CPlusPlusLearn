#include <iostream>
#include <string>

using namespace std;

// 虚析构和纯虚析构
class Animal {
public:
	Animal()
	{
		cout << "Animal构造函数调用" << endl;
	}

	// 利用虚析构可以解决父类指针释放子类对象时不干净的问题
	//virtual ~Animal()
	//{
	//	cout << "Animal虚析构函数调用" << endl;
	//}

	// 纯虚析构函数，需要声明也需要实现
	// 有了这个纯虚析构以后，这个类属于抽象类，无法实例化对象
	virtual ~Animal() = 0;

	// 纯虚函数
	virtual void speak() = 0;
};

Animal::~Animal()
{
	cout << "Animal纯虚析构函数调用" << endl;
}

// Cat类
class Cat :public Animal {
public:
	Cat(string name)
	{
		cout << "Cat构造函数调用" << endl;
		m_name = new string(name);
	}

	~Cat()
	{
		cout << "Cat析构函数调用" << endl;
		if (m_name != nullptr)
		{
			delete m_name;
			m_name = nullptr;
		}
	}

	void speak()
	{
		cout << *m_name <<  "小猫在说话" << endl;
	}

public:
	string *m_name;
};

void test_pure_virtual_deconstruction()
{
	Animal* animal = new Cat("Tom");
	animal->speak();

	// 通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄露
	// 解决：给基类增加一个虚析构函数
	// 虚析构函数就是用来解决通过父类指针来释放子类对象
	delete animal;
	animal = nullptr;
}

//int main()
//{
//	test_pure_virtual_deconstruction();
//	return 0;
//}