#include <iostream>
#include <string>

using namespace std;

// 类做友元
class Building1;

class GoodFriend {
public:
	GoodFriend();

	// 参观函数，访问Building中的属性
	void visit();
public:
	Building1 *build;
};

class Building1 {
	// GoodFriend类是Building类的好朋友，可以访问Building类的属性
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
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧室";
}

GoodFriend::GoodFriend()
{
	build = new Building1();
}

void GoodFriend::visit() // 参观函数，访问Building中的属性
{
	cout << "好朋友正在访问：" << build->m_SittingRoom << endl;
	cout << "好朋友正在访问：" << build->m_BedRoom << endl;
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