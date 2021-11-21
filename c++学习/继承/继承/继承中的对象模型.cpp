#include <iostream>
using namespace std;

// 继承中的对象模型
class Base {
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c; // 私有成员只是被编译器隐藏了，但是会被继承下去
};

class Son :public Base {
public:
	int m_d;
};

// 利用开发人员命令提示工具查看对象模型
// 跳转盘符 F：
// 跳转文件路径 cd 具体路径
// 查看命名
// cl /d1 reportSingleClassLayout类名 文件名

void test()
{
	// 父类中所有非静态成员属性都会被子类继承下去
	// 父类中私有成员属性 是被编译器给隐藏了，因此是访问不到的，但是确实被继承下来了
	cout << "size of Son = " << sizeof(Son) << endl; // 结果：size of Son = 16
}