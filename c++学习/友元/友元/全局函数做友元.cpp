#include <iostream>
#include <string>

using namespace std;

// ȫ�ֺ�������Ԫ
class Building {
	// ���߱���������ȫ�ֺ�����Building�ĺ����ѣ����Է���Building˽�г�Ա
	friend void goodFriend(const Building& build);
public:
	Building()
	{
		m_SettingRoom = "����";
		m_BedRoom = "����";
	}
public:
	string m_SettingRoom;
private:
	string m_BedRoom;
};

void goodFriend(const Building& build)
{
	cout << "ȫ�ֺ������ڷ���: " << build.m_SettingRoom << endl;
	cout << "ȫ�ֺ������ڷ���: " << build.m_BedRoom << endl;
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