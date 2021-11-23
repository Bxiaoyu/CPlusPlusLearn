#include <iostream>
#include <string>
using namespace std;
#include "MyArray.hpp"

// �����Զ�����������
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

// ��ӡ����
void printArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.get_size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// ��ӡ�Զ�������
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
		// β�巨
		arr.push_back(i + 1);
	}

	cout << "���������Ϊ��" << endl;
	printArray(arr);
	cout << "�����СΪ��" << arr.get_size() << endl;
	cout << "��������Ϊ��" << arr.get_capacity() << endl;

	MyArray<int> arr2(arr);
	arr2.pop_back();
	cout << "arr2βɾ��: " << endl;
	cout << "arr2����Ϊ��" << arr2.get_capacity() << endl;
	cout << "arr2��СΪ��" << arr2.get_size() << endl;
}

void test_arry_person()
{
	MyArray<Person> arr(10);
	Person p1("���", 100);
	Person p2("�˽�", 98);
	Person p3("ɳɮ", 99);
	Person p4("��ɮ", 40);
	Person p5("Ů��������", 33);
	Person p6("�϶�", 100);

	arr.push_back(p1);
	arr.push_back(p2);
	arr.push_back(p3);
	arr.push_back(p4);
	arr.push_back(p5);
	arr.push_back(p6);

	cout << endl << "--------------------------------------" << endl;
	cout << "Arr����Ϊ��" << arr.get_capacity() << endl;
	cout << "Arr��СΪ��" << arr.get_size() << endl;
	printPersonArray(arr);
}

int main()
{
	test_array();
	test_arry_person();
	return 0;
}