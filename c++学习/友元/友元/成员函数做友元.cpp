#include <iostream>
#include <string>

using namespace std;


class Building2;

class GoodGay {
public:
	GoodGay();

	// 让visit可以访问Building2中的私有成员
	void visit();
	// 让visit2不可以访问Building2中的私有成员
	void visit2();
private:
	Building2* build;
};

class Building2 {
	// 告诉编译器，GoodGay类下的visit成员函数作为本类好朋友，可以访问私有成员
	friend void GoodGay::visit();
public:
	Building2();

public:
	string m_SittingRoom;

private:
	string m_BedRoom;
};

GoodGay::GoodGay()
{
	build = new Building2();
}

Building2::Building2():m_SittingRoom("客厅"),m_BedRoom("卧室")
{
}

void GoodGay::visit()
{
	cout << "visit 好朋友正在访问：" << build->m_SittingRoom << endl;
	cout << "visit 好朋友正在访问：" << build->m_BedRoom << endl;
}

void GoodGay::visit2()
{
	cout << "visit2 好朋友正在访问：" << build->m_SittingRoom << endl;
	//cout << "visit2 好朋友正在访问：" << build->m_BedRoom << endl;
}

void test()
{
	GoodGay gg;
	gg.visit();
	gg.visit2();
}

int main()
{
	test();
	return 0;
}