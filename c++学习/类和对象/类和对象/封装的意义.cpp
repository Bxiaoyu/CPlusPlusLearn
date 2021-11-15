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
	People(int a)
	{
		m_age = a;
		cout << "People���вι��캯������" << endl;
	}

	// �������캯��
	People(const People& p)
	{
		m_age = p.m_age;
		cout << "People�Ŀ������캯������" << endl;
	}
	~People();

private:
	int m_age;
};

void test()
{

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