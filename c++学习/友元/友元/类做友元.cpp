#include <iostream>
#include <string>

using namespace std;

// ������Ԫ
class Building1;

class GoodFriend {
public:
	GoodFriend();

	// �ιۺ���������Building�е�����
	void visit();
public:
	Building1 *build;
};

class Building1 {
	// GoodFriend����Building��ĺ����ѣ����Է���Building�������
	friend class GoodFriend;
public:
	Building1();
public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

Building1::Building1()
{
	this->m_SittingRoom = "����";
	this->m_BedRoom = "����";
}

GoodFriend::GoodFriend()
{
	build = new Building1();
}

void GoodFriend::visit() // �ιۺ���������Building�е�����
{
	cout << "���������ڷ��ʣ�" << build->m_SittingRoom << endl;
	cout << "���������ڷ��ʣ�" << build->m_BedRoom << endl;
}

void test0()
{
	GoodFriend gf;
	gf.visit();
}

//int main()
//{
//	test0();
//	return 0;
//}