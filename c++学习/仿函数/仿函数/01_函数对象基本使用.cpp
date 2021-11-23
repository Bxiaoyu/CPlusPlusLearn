#include <iostream>
#include <string>

using namespace std;

class MyAdd {
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

// 1.����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
void test01()
{
	MyAdd add;
	cout << add(10, 20) << endl;
}

// 2.�������󳬳���ͨ�����ĸ����������������Լ���״̬
class MyPrint {
public:
	MyPrint():m_count(0)
	{
	}

	void operator()(string text)
	{
		cout << text << endl;
		this->m_count++;
	}

public:
	int m_count; // �ڲ�״̬
};

void test02()
{
	MyPrint mp;
	mp("hello world!");
	mp("hello world!");
	mp("hello world!");
	mp("hello world!");
	mp("hello world!");

	cout << "MyPrint���ô���: " << mp.m_count << endl;
}

// 3.�������������Ϊ��������
void doPrint(MyPrint& mp, string text)
{
	mp(text);
}

void test03()
{
	MyPrint mp;
	doPrint(mp, "hello python");
}

//int main()
//{
//	test01();
//	test02();
//	test03();
//	return 0;
//}