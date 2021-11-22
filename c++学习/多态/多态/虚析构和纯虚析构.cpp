#include <iostream>
#include <string>

using namespace std;

// �������ʹ�������
class Animal {
public:
	Animal()
	{
		cout << "Animal���캯������" << endl;
	}

	// �������������Խ������ָ���ͷ��������ʱ���ɾ�������
	//virtual ~Animal()
	//{
	//	cout << "Animal��������������" << endl;
	//}

	// ����������������Ҫ����Ҳ��Ҫʵ��
	// ����������������Ժ���������ڳ����࣬�޷�ʵ��������
	virtual ~Animal() = 0;

	// ���麯��
	virtual void speak() = 0;
};

Animal::~Animal()
{
	cout << "Animal����������������" << endl;
}

// Cat��
class Cat :public Animal {
public:
	Cat(string name)
	{
		cout << "Cat���캯������" << endl;
		m_name = new string(name);
	}

	~Cat()
	{
		cout << "Cat������������" << endl;
		if (m_name != nullptr)
		{
			delete m_name;
			m_name = nullptr;
		}
	}

	void speak()
	{
		cout << *m_name <<  "Сè��˵��" << endl;
	}

public:
	string *m_name;
};

void test_pure_virtual_deconstruction()
{
	Animal* animal = new Cat("Tom");
	animal->speak();

	// ͨ������ָ��ȥ�ͷţ��ᵼ�����������������ɾ�������ڴ�й¶
	// ���������������һ������������
	// ���������������������ͨ������ָ�����ͷ��������
	delete animal;
	animal = nullptr;
}

//int main()
//{
//	test_pure_virtual_deconstruction();
//	return 0;
//}