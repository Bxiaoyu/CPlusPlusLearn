#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ����д�ļ�
void test_write()
{
	// 1. �����ļ�������
	ofstream ofs;

	// 2.ָ���򿪷�ʽ
	ofs.open("test.txt", ios::out);

	// 3.д����
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;

	// 4.�ر��ļ�
	ofs.close();
}

// ���Զ��ļ�
void test_read()
{
	// 1. �����ļ�������
	ifstream ifs;

	// 2.ָ���򿪷�ʽ�����ж��Ƿ�򿪳ɹ�
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	// 3.������
	// ��һ��
	char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}

	// �ڶ���
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}

	// ������
	string sbuf;
	while (getline(ifs, sbuf))
	{
		cout << sbuf << endl;
	}

	// �����֣������Ƽ�
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}

	// 4.�ر��ļ�
	ifs.close();
}

//int main()
//{
//	test_read();
//	return 0;
//}