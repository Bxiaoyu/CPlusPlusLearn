#include <iostream>
#include <string>

using namespace std;

// ���һ��ѧ����,������������ѧ��
// ���Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��

class Student {
public: // ����Ȩ��
	// ��Ϊ����ʾ������ѧ��
	void show()
	{
		cout << "ѧ��\t����" << endl;
		cout << m_id << "\t" << m_name << endl;
	}

	// ��������
	void set_name(const string& name)
	{
		m_name = name;
	}

	// ����ID
	void set_id(const string& id)
	{
		m_id = id;
	}

private: // ˽��Ȩ��
	// ����
	string m_name; // ����
	string m_id;   // ѧ��
};

class Person {
public:
	Person()
	{
		// ���ڷ���
		m_name = "����";
		m_car = "�µ�";
		m_password = "123456";
	}
public:
	string m_name; // ����
protected:
	string m_car; // ��
private:
	string m_password; // ����
};

class PersonInfo {
public:
	PersonInfo():m_name("����"), m_age(38),m_lover("")
	{
		
	}

	// ��������
	void set_name(const string& name)
	{
		m_name = name;
	}

	// ��ȡ����
	string get_name()
	{
		return m_name;
	}

	// ��������
	void set_age(const int age)
	{
		// ��֤������Ч��
		if (age < 0 || age > 150)
		{
			m_age = 0;
			cout << "��������䲻�Ϸ�" << endl;
			return;
		}
		m_age = age;
	}

	// ��ȡ����
	int get_age()
	{
		return m_age;
	}

	// ��������
	void set_lover(const string& lover)
	{
		m_lover = lover;
	}
private:
	// �������ɶ���д
	string m_name;
	// ���䣬ֻ��
	int m_age;
	// ���ˣ�ֻд
	string m_lover;
};

class People
{
public:
	// Ĭ�Ϲ���
	People()
	{
		cout << "People���޲ι��캯������" << endl;
	}
	// �вι���
	People(int a, int height)
	{
		m_age = a;
		m_height = new int(height);
		cout << "People���вι��캯������" << endl;
	}

	// �������캯��
	People(const People& p)
	{
		m_age = p.m_age;
		//m_height = p.m_height; // ǳ������������Ĭ��ʵ�־������д���
		m_height = new int(*p.m_height); // ���
		cout << "People�Ŀ������캯������" << endl;
	}
	
	// ��������
	~People()
	{
		if (m_height != nullptr)
		{
			delete m_height;
			m_height = nullptr;
		}
		cout << "People��������������" << endl;
	}

public:
	int m_age;
	int *m_height;
};

void test01()
{
	People p(18, 180);
	People p1(p);
}

// ���ֵ��÷�ʽ
void test()
{
	// ���ŷ�
	People p1;     // ����Ĭ�Ϲ��캯������Ҫ��()���������������Ϊ����һ������������������Ϊ���ڴ�������
	People p2(10); // �вι��캯��
	People p3(p1); // ���ÿ������캯��

	// ��ʾ��
	People p4; // ����Ĭ�Ϲ��캯������Ҫ��()���������������Ϊ����һ������������������Ϊ���ڴ�������
	People p5 = People(10); // �вι��캯��
	People p6 = People(2); // ���ÿ������캯��
	People(10); // �������� �ص㣺��ǰ��ִ�н�����ϵͳ������������������
	// ע�������Ҫ���ÿ������캯����ʼ���������󣬱���������Ϊ�Ƕ������������� People(p3) == People p3;
	People(p6);// ����

	// ��ʽת����
	People p7 = 10; // �����вι��죬�൱��д�� People p7  = People(10)
	People p8 = p7; // ���ÿ�������
}

class Phone {
public:
	Phone(string name):m_phoneName(name)
	{
		cout << "Phone �����������" << endl;
	}

public:
	string m_phoneName;
};

class Person1
{
public:
	// Phone m_phone = phone ��ʽת����
	Person1(string name, string phone):m_name(name), m_phone(phone)
	{
		cout << "Person ���캯������" << endl;
	}

public:
	string m_name;
	Phone m_phone;
};

class A {
public:
	// ��̬��Ա����
	static void func()
	{
		m_A = 100; // ��ȷ ��̬��Ա�������Է��� ��̬��Ա����
		//m_B = 10;  // ���� ��̬��Ա���������Է��� �Ǿ�̬��Ա��������Ϊ�������޷�����m_B�������ĸ����������
		cout << "static void func ����" << endl;
	}

private:
	// ˽�о�̬��Ա����
	static void func2()
	{
		cout << "static void func2 ����" << endl;
	}

public:
	static int m_A; // ��̬��Ա����
	int m_B; // �Ǿ�̬��Ա����

private:
	static int m_C;
};

int A::m_A = 0;
int A::m_C = 0;

void test2()
{
	// 1. ͨ���������
	A a;
	a.func();
	// 2. ͨ����������
	A::func();

	//a.func2();  // ���� ������ʲ���˽�о�̬��Ա����
	//A::func2(); // ���� ������ʲ���˽�о�̬��Ա����
}

class B {
public:
	void func() // �Ǿ�̬��Ա���� ��������Ķ���
	{
	}

public:
	int m_a;        // �Ǿ�̬��Ա���� ������Ķ���
	static int m_b; // ��̬��Ա���� ��������Ķ���
};

void test3()
{
	B b;
	/*
	�ն���ռ���ڴ�ռ�Ϊ1
	C++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
	ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	*/
	cout << "sizeof b = " << sizeof(b) << endl;
}

void test4()
{
	B b;
	cout << "sizeof b = " << sizeof(b) << endl;
}

void test5()
{
	B b;
	cout << "sizeof b = " << sizeof(b) << endl;
}

int main()
{
	// ����һ��ѧ��ʵ������
	Student s;
	// ������Ϣ
	s.set_name("����");
	s.set_id("1001");
	// ��ʾ��Ϣ
	s.show();

	// ����ʵ��������
	Person p;
	p.m_name = "����";
	//p.m_car = "";      // ���󣺱���Ȩ�����ݣ����ⲻ�ɷ���
	//p.m_password = ""; // ����˽��Ȩ�����ݣ����ⲻ�ɷ���

	return 0;
}