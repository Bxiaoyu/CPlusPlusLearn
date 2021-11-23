#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Base {
public:
	T m;
};

// 1.������̳еĸ�����һ��ģ��ʱ��������������ʱ��Ҫָ����������T������
// �����ָ�����ͣ��������޷�����������ڴ�
//class Son:public Base // ���󣬱���Ҫ֪��������T�����ͣ����ܼ̳и�����
class Son :public Base<int>
{

};

// 2.���������ָ��������T�����ͣ�����Ҳ��Ҫ��Ϊ��ģ��
template<typename T1, typename T2>
class Son2 :public Base<T2> {
public:
	Son2()
	{
		cout << "T1������Ϊ��" << typeid(T1).name() << endl;
		cout << "T2������Ϊ��" << typeid(T2).name() << endl;
	}
public:
	T1 obj;
};

void test_func()
{
	Son2<int, char> s;
}

//int main()
//{
//	test_func();
//	return 0;
//}