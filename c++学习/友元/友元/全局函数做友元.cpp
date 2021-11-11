#include <iostream>
#include <string>

using namespace std;

// 全局函数做友元
class Building {
	// 告诉编译器，此全局函数是Building的好朋友，可以访问Building私有成员
	friend void goodFriend(const Building& build);
public:
	Building()
	{
		m_SettingRoom = "客厅";
		m_BedRoom = "卧室";
	}
public:
	string m_SettingRoom;
private:
	string m_BedRoom;
};

void goodFriend(const Building& build)
{
	cout << "全局函数正在访问: " << build.m_SettingRoom << endl;
	cout << "全局函数正在访问: " << build.m_BedRoom << endl;
}

void test01()
{
	Building build;
	goodFriend(build);
}

//int main()
//{
//	test01();
//	return 0;
//}