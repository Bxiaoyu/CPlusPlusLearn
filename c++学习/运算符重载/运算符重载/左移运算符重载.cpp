#include <iostream>

using namespace std;

class Person {
	friend ostream& operator << (ostream& out, Person& p);
public:
	Person(int a, int b):m_A(a),m_B(b)
	{
	}

private:
	int m_A;
	int m_B;
};

// 只能用全局函数来重载左移运算符，out对象为全局只有一个，只能用引用调用
// 返回引用，支持链式调用
ostream& operator << (ostream& out, Person& p)
{
	out << "m_A = " << p.m_A << " m_B = " << p.m_B;
	return out;
}

//int main()
//{
//	Person p(10, 10);
//	cout << p << " hello world" << endl; // 链式调用
//}