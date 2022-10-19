#include <iostream>
#include <string>

using namespace std;

// 全局变量
int g_a = 10;
int g_b = 10;

// 全局常量
const int c_g_a = 10;
const int c_g_b = 10;

// 测试
void test()
{
	// 局部变量
	int l_a = 10;
	int l_b = 10;
	cout << "局部变量 l_a 的地址为：" << &l_a << endl;
	cout << "局部变量 l_b 的地址为：" << &l_b << endl;

	cout << "全局变量 g_a 的地址为：" << &g_a << endl;
	cout << "全局变量 g_b 的地址为：" << &g_b << endl;

	// 静态变量
	static int s_a = 10;
	static int s_b = 10;
	cout << "静态变量 s_a 的地址为：" << &s_a << endl;
	cout << "静态变量 s_b 的地址为：" << &s_b << endl;


	/*
		常量：
			1.字符串常量
			2.const 修饰的变量：
				2.1 const 修饰的局部变量
				2.2 const 修饰的全部变量
	*/
	cout << "字符串常量的地址为：" << &"hello world" << endl;

	// const 修饰的全局变量
	cout << "全局常量 c_g_a 的地址为：" << &c_g_a << endl;
	cout << "全局常量 c_g_b 的地址为：" << &c_g_b << endl;

	// const 修饰的局部变量
	const int c_l_a = 10;
	const int c_l_b = 10;

	cout << "局部常量 c_l_a 的地址为：" << &c_l_a << endl;
	cout << "局部常量 c_l_b 的地址为：" << &c_l_b << endl;
}

// 测试返回局部变量地址（开发中禁止这么做）
int* func()
{
	int a = 10;  // 局部变量存放在栈区，栈区的数据在函数执行完成后自定释放
	return &a;   // 返回局部变量的地址
}

// 在堆区分配内存，返回堆区数据地址
int* func2()
{
	// 利用new关键字，可以将数据开辟到堆区
	// 指针 本质也是局部变量，放在栈区，指针保存的数据是放在堆区
	int *p = new int(10);
	return p;
}

int main()
{
	// 接收func函数返回值
	int *p = func();

	cout << "*p = " << *p << endl; // 第一次可以打印正确值，是因为编译器做了保留
	cout << "*p = " << *p << endl; // 第二次这个数字就不保留了

	int *p1 = func2();
	cout << "*p1 = " << *p1 << endl;
	cout << "*p1 = " << *p1 << endl;
	return 0;
}