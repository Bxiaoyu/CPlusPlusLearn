#include <iostream>
#include <string>
using namespace std;
#include "MyArray.hpp"

// 测试自定义数据类型
class Person {
public:
	Person()
	{
	}

	Person(string name, int age) :m_name(name), m_age(age)
	{
	}
public:
	string m_name;
	int m_age;
};

// 打印数据
void printArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.get_size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// 打印自定义数据
void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.get_size(); i++)
	{
		cout << "Name: " << arr[i].m_name << "\tAge: " << arr[i].m_age << endl;
	}
}

void test_array()
{
	MyArray<int> arr(10);
	for (int i = 0; i < 6; i++)
	{
		// 尾插法
		arr.push_back(i + 1);
	}

	cout << "插入的数据为：" << endl;
	printArray(arr);
	cout << "数组大小为：" << arr.get_size() << endl;
	cout << "数组容量为：" << arr.get_capacity() << endl;

	MyArray<int> arr2(arr);
	arr2.pop_back();
	cout << "arr2尾删后: " << endl;
	cout << "arr2容量为：" << arr2.get_capacity() << endl;
	cout << "arr2大小为：" << arr2.get_size() << endl;
}

void test_arry_person()
{
	MyArray<Person> arr(10);
	Person p1("悟空", 100);
	Person p2("八戒", 98);
	Person p3("沙僧", 99);
	Person p4("唐僧", 40);
	Person p5("女儿国国王", 33);
	Person p6("嫦娥", 100);

	arr.push_back(p1);
	arr.push_back(p2);
	arr.push_back(p3);
	arr.push_back(p4);
	arr.push_back(p5);
	arr.push_back(p6);

	cout << endl << "--------------------------------------" << endl;
	cout << "Arr容量为：" << arr.get_capacity() << endl;
	cout << "Arr大小为：" << arr.get_size() << endl;
	printPersonArray(arr);
}

int main()
{
	test_array();
	test_arry_person();
	return 0;
}