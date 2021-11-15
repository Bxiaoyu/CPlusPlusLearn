#include <iostream>
#include <string>

using namespace std;

// 引用基本使用
void test1()
{
    int a = 10;
    int& b = a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 100;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

// 引用注意事项
void test2()
{
    // 1.引用必须初始化
    int a = 10;
    int& b = a;

    // 2.引用在初始化后，不可以改变
    int c = 20; // 一旦初始化后就不可以更改
    b = c; // 赋值操作，而不是更改引用，可以

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}

// 引用做函数参数
// 值传递
void myswap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 地址传递
void myswap2(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 引用传递
void myswap3(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 打印结果
void printInfo(string func, int a, int b)
{
    cout << func << " after" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

// 引用做函数返回值
// 1.不要返回局部变量引用
int& test01()
{
    int a = 10; // 局部变量存放在栈区
    return a;
}

// 2.函数的调用可以作为左值
int& test02()
{
    static int a = 10; // 静态变量存放在全局区，全局区上的数据在程序结束后由系统释放
    return a;
}

// 常量引用
void showValue(const int& val)
{
    //val = 1000; // 错误，不能更改
    cout << "val = " << val << endl;
}

int main()
{
    int& ref = 10; // 错误，不能如此初始化，引用必须引一块合法的内存空间
    // 加上const之后，编译器将代码修改为 int temp = 10; const int& ref = temp;
    const int& ref = 10; // 可以，引用必须引一块合法的内存空间
    ref = 10; // 错误，加上const之后变为只读，不可以修改

    int a = 100;
    showValue(a);
    return 0;
}