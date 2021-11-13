#include <iostream>
#include <string>

using namespace std;


// 学生结构体
struct Student {
	// 年龄
	int age;
	// 分数
	int score;
	// 姓名
	string name;
}; // 顺便创建结构体变量

struct Teacher {
	// 教师编号
	int id;
	// 教师年龄
	int age;
	// 教师姓名
	string name;
	// 学生信息
	struct Student stu;
};

// 打印信息（值传递）
void printInfo(Student s)
{
	cout << "值传递" << endl;
	cout << "姓名\t年龄\t分数" << endl;
	cout << s.name << "\t" << s.age << "\t" << s.score << endl;
}

// 打印消息（地址传递）
void printInfo2(Student* s)
{
	cout << "地址传递" << endl;
	cout << "姓名\t年龄\t分数" << endl;
	cout << s->name << "\t" << s->age << "\t" << s->score << endl;
}

int main()
{
	// 创建学生信息
	Student s{ 18, 95, "张三" };
	printInfo(s);
	cout << endl;
	printInfo2(&s);
	return 0;
}