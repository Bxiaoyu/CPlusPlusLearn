#include <iostream>
#include <string>

using namespace std;

// ���麯���ͳ�����
class Base {
public:
	// ���麯��
	// ֻҪ��һ�����麯����������Ϊ������
	// �������ص㣺
	// 1. �޷�ʵ��������
	// 2. ����������࣬������д�����еĴ��麯��������Ҳ���ڳ�����
	virtual void func() = 0;
};

class Son :public Base {
public:
	void func() {
		cout << "func��������" << endl;
	}
};

void test_virtual_class()
{
	//Base b; // �������޷�ʵ��������
	//new Base; // �������޷�ʵ��������
	
	Son s; // ���������д�����еĴ��麯���������޷�ʵ��������
	s.func();

	Son* s1 = new Son;
	s1->func();
}