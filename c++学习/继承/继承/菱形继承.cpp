#include <iostream>

using namespace std;

// ���μ̳�
// ������
class Animal {
public:
	int m_Age;
};

// ������̳У����Խ�����μ̳е�����
// �ڼ̳�֮ǰ�����Ϲؼ��� virtual ��Ϊ��̳У���Animal���Ϊ�����
// ����
class Sheep :virtual public Animal {

};

// ����
class Camel :virtual public Animal {

};

// ������
class Alpaca :public Sheep, public Camel {

};

void test_diamond_inheritance()
{
	Alpaca ap;
	// �����μ̳У���������ӵ����ͬ���ݣ���Ҫ��������������
	ap.Sheep::m_Age = 18;
	ap.Camel::m_Age = 28;
	cout << "ap.Sheep::m_Age = " << ap.Sheep::m_Age << endl;
	cout << "ap.Camel::m_Age = " << ap.Camel::m_Age << endl;

	// ��Щ����ֻҪ��һ�ݾͿ��ԣ����μ̳е������������ݣ��˷���Դ
	// ������μ̳к�
	cout << ap.m_Age << endl; // ����ֻ��һ���ˣ��Ͳ�����ֶ�����ȷ����
}

//int main()
//{
//	test_diamond_inheritance();
//	return 0;
//}