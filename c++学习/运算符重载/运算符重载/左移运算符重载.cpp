#include <iostream>

using namespace std;

class Person {
	friend ostream& operator << (ostream& out, Person& p);
public:
	Person(int a, int b):m_A(a),m_B(b)
	{
	}

private:
	int m_A;
	int m_B;
};

// ֻ����ȫ�ֺ��������������������out����Ϊȫ��ֻ��һ����ֻ�������õ���
// �������ã�֧����ʽ����
ostream& operator << (ostream& out, Person& p)
{
	out << "m_A = " << p.m_A << " m_B = " << p.m_B;
	return out;
}

//int main()
//{
//	Person p(10, 10);
//	cout << p << " hello world" << endl; // ��ʽ����
//}