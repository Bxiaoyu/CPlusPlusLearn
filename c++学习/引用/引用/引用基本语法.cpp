#include <iostream>
#include <string>

using namespace std;

// ���û���ʹ��
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

// ����ע������
void test2()
{
    // 1.���ñ����ʼ��
    int a = 10;
    int& b = a;

    // 2.�����ڳ�ʼ���󣬲����Ըı�
    int c = 20; // һ����ʼ����Ͳ����Ը���
    b = c; // ��ֵ�����������Ǹ������ã�����

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}

// ��������������
// ֵ����
void myswap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// ��ַ����
void myswap2(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ���ô���
void myswap3(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// ��ӡ���
void printInfo(string func, int a, int b)
{
    cout << func << " after" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

// ��������������ֵ
// 1.��Ҫ���ؾֲ���������
int& test01()
{
    int a = 10; // �ֲ����������ջ��
    return a;
}

// 2.�����ĵ��ÿ�����Ϊ��ֵ
int& test02()
{
    static int a = 10; // ��̬���������ȫ������ȫ�����ϵ������ڳ����������ϵͳ�ͷ�
    return a;
}

// ��������
void showValue(const int& val)
{
    //val = 1000; // ���󣬲��ܸ���
    cout << "val = " << val << endl;
}

int main()
{
    int& ref = 10; // ���󣬲�����˳�ʼ�������ñ�����һ��Ϸ����ڴ�ռ�
    // ����const֮�󣬱������������޸�Ϊ int temp = 10; const int& ref = temp;
    const int& ref = 10; // ���ԣ����ñ�����һ��Ϸ����ڴ�ռ�
    ref = 10; // ���󣬼���const֮���Ϊֻ�����������޸�

    int a = 100;
    showValue(a);
    return 0;
}