#include <iostream>
#include <fstream>

using namespace std;

class Person {
public:
	char m_name[64]; // 姓名
	int m_age; // 年龄
};

// 测试二进制写文件
void test_write_binary()
{
	// 1. 创建文件流对象
	ofstream ofs("person.txt", ios::out | ios::binary);

	// 2.指定打开方式，打开方式两种
	//ofs.open("person.txt", ios::out | ios::binary);

	// 3.写内容
	Person p = { "张三", 18 };
	ofs.write((const char*)&p, sizeof(Person));

	// 4.关闭文件
	ofs.close();
}

// 测试二进制读文件
void test_read_binary()
{
	// 1. 创建文件流对象
	ifstream ifs("person.txt", ios::out | ios::binary);

	// 2.指定打开方式，打开方式两种，并判断文件是否打开成功
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	// 3.读内容
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "姓名：" << p.m_name << endl;
	cout << "年龄：" << p.m_age << endl;

	// 4.关闭文件
	ifs.close();
}

int main()
{
	test_read_binary();
	return 0;
}