#include <iostream>
#include <string>

using namespace std;


class Building2;

class GoodGay {
public:
	GoodGay();

	// ��visit���Է���Building2�е�˽�г�Ա
	void visit();
	// ��visit2�����Է���Building2�е�˽�г�Ա
	void visit2();
private:
	Building2* build;
};

class Building2 {
	// ���߱�������GoodGay���µ�visit��Ա������Ϊ��������ѣ����Է���˽�г�Ա
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

Building2::Building2():m_SittingRoom("����"),m_BedRoom("����")
{
}

void GoodGay::visit()
{
	cout << "visit ���������ڷ��ʣ�" << build->m_SittingRoom << endl;
	cout << "visit ���������ڷ��ʣ�" << build->m_BedRoom << endl;
}

void GoodGay::visit2()
{
	cout << "visit2 ���������ڷ��ʣ�" << build->m_SittingRoom << endl;
	//cout << "visit2 ���������ڷ��ʣ�" << build->m_BedRoom << endl;
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