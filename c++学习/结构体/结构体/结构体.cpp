#include <iostream>
#include <string>

using namespace std;


// ѧ���ṹ��
struct Student {
	// ����
	int age;
	// ����
	int score;
	// ����
	string name;
}; // ˳�㴴���ṹ�����

struct Teacher {
	// ��ʦ���
	int id;
	// ��ʦ����
	int age;
	// ��ʦ����
	string name;
	// ѧ����Ϣ
	struct Student stu;
};

// ��ӡ��Ϣ��ֵ���ݣ�
void printInfo(Student s)
{
	cout << "ֵ����" << endl;
	cout << "����\t����\t����" << endl;
	cout << s.name << "\t" << s.age << "\t" << s.score << endl;
}

// ��ӡ��Ϣ����ַ���ݣ�
void printInfo2(Student* s)
{
	cout << "��ַ����" << endl;
	cout << "����\t����\t����" << endl;
	cout << s->name << "\t" << s->age << "\t" << s->score << endl;
}

int main()
{
	// ����ѧ����Ϣ
	Student s{ 18, 95, "����" };
	printInfo(s);
	cout << endl;
	printInfo2(&s);
	return 0;
}