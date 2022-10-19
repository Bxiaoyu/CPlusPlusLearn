#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 测试写文件
void test_write()
{
	// 1. 创建文件流对象
	ofstream ofs;

	// 2.指定打开方式
	ofs.open("test.txt", ios::out);

	// 3.写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

	// 4.关闭文件
	ofs.close();
}

// 测试读文件
void test_read()
{
	// 1. 创建文件流对象
	ifstream ifs;

	// 2.指定打开方式，并判断是否打开成功
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	// 3.读内容
	// 第一种
	char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}

	// 第二种
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}

	// 第三种
	string sbuf;
	while (getline(ifs, sbuf))
	{
		cout << sbuf << endl;
	}

	// 第四种（）不推荐
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}

	// 4.关闭文件
	ifs.close();
}

//int main()
//{
//	test_read();
//	return 0;
//}