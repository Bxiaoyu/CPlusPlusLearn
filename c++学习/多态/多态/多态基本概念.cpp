#include <iostream>
#include <string>

using namespace std;

// ������
class Animal {
public:
	// �麯��
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

// è��
class Cat :public Animal {
public:
	// ��д ������������ ������ �����б� ��ȫ��ͬ
	void speak()
	{
		cout << "è��˵��" << endl;
	}
};

// ����
class Dog :public Animal {
public:
	void speak()
	{
		cout << "����˵��" << endl;
	}
};

// ִ��˵���ĺ���
// ��ַ��󶨣��ڱ���׶�ȷ��������ַ
// �����ִ����è˵������ô���������ַҪ�����н׶ΰ󶨣���ַ���

/*
* ��̬��̬����������
* 1. �м̳й�ϵ
* 2. ������д������麯��
* 
* ��̬��̬ʹ�ã�
* �����ָ���������ָ���������
*/
void doSpeak(Animal& animal)
{
	animal.speak();
}

// ���Ժ���
void test()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

int main()
{
	test();
	return 0;
}