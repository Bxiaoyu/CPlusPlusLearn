#include <iostream>

using namespace std;

// ��ӡ��
class MyPrint {
public:
	// ���غ��������������Ҳ�Ʒº���
	void operator()(string text)
	{
		cout << text << endl;
	}
};

// �º����ǳ���û�й̶�д��
// �ӷ���
class MyAdd {
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

int main()
{
	MyPrint mp;
	mp("hello world!");

	MyAdd md;
	int ret = md(100, 100);
	cout << "MyAdd result: " << ret << endl;

	// ������������
	cout << "MyAdd()(100,100): " << MyAdd()(100, 100) << endl;

	return 0;
}