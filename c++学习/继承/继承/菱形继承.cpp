#include <iostream>

using namespace std;

// 菱形继承
// 动物类
class Animal {
public:
	int m_Age;
};

// 利用虚继承，可以解决菱形继承的问题
// 在继承之前，加上关键字 virtual 变为虚继承，则Animal类变为虚基类
// 羊类
class Sheep :virtual public Animal {

};

// 驼类
class Camel :virtual public Animal {

};

// 羊驼类
class Alpaca :public Sheep, public Camel {

};

void test_diamond_inheritance()
{
	Alpaca ap;
	// 当菱形继承，两个父类拥有相同数据，需要加以作用域区分
	ap.Sheep::m_Age = 18;
	ap.Camel::m_Age = 28;
	cout << "ap.Sheep::m_Age = " << ap.Sheep::m_Age << endl;
	cout << "ap.Camel::m_Age = " << ap.Camel::m_Age << endl;

	// 这些数据只要有一份就可以，菱形继承导致数据有两份，浪费资源
	// 解决菱形继承后
	cout << ap.m_Age << endl; // 数据只有一份了，就不会出现对象不明确问题
}

//int main()
//{
//	test_diamond_inheritance();
//	return 0;
//}