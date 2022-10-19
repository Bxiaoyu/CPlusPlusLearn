#include <iostream>
#include <fstream>

using namespace std;

class Person {
public:
	char m_name[64]; // ����
	int m_age; // ����
};

// ���Զ�����д�ļ�
void test_write_binary()
{
	// 1. �����ļ�������
	ofstream ofs("person.txt", ios::out | ios::binary);

	// 2.ָ���򿪷�ʽ���򿪷�ʽ����
	//ofs.open("person.txt", ios::out | ios::binary);

	// 3.д����
	Person p = { "����", 18 };
	ofs.write((const char*)&p, sizeof(Person));

	// 4.�ر��ļ�
	ofs.close();
}

// ���Զ����ƶ��ļ�
void test_read_binary()
{
	// 1. �����ļ�������
	ifstream ifs("person.txt", ios::out | ios::binary);

	// 2.ָ���򿪷�ʽ���򿪷�ʽ���֣����ж��ļ��Ƿ�򿪳ɹ�
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	// 3.������
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "������" << p.m_name << endl;
	cout << "���䣺" << p.m_age << endl;

	// 4.�ر��ļ�
	ifs.close();
}

int main()
{
	test_read_binary();
	return 0;
}