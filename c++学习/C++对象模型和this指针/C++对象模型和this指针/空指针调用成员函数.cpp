#include <iostream>

using namespace std;

class Person {
public:
	void showClassName()
	{
		cout << "this is Person class" << endl;
	}

	void showAge()
	{
		// 属性前面都默认加了一个this->调用，传入的指针为空，访问属性时会报错
		if (this == nullptr) // 判断this指针是否为空，增加代码健壮性
			return;
		cout << "age = " << m_age << endl;
	}

public:
	int m_age;
};

void test()
{
	Person *p = nullptr;
	p->showClassName(); // 正确
	p->showAge();       // 错误 传入空指针时要做指针合法性判断，否则会报错
}