#include <iostream>

using namespace std;

class MyInteger {
	friend ostream& operator<<(ostream& out, MyInteger mi);
public:
	MyInteger()
	{
		m_num = 0;
	}

	// ����ǰ��++�������ǰ�õ�����������
	// ����������Ϊ��һֱ��һ�����ݽ��е�������
	MyInteger& operator++()
	{
		// �Ƚ���++����
		m_num++;
		// �ٽ�����������
		return *this;
	}

	// ���غ���++����������õ�������ֵ
	// void operator++(int) int����ռλ������������������ǰ�úͺ��õ���
	MyInteger operator++(int)
	{
		// �ȼ�¼��ʱ���
		MyInteger temp = *this;
		//�����
		m_num++;
		// ��󽫼�¼�������
		return temp;
	}
private:
	int m_num;
};

// ����<<�����
ostream& operator<<(ostream& out, MyInteger mi)
{
	out << mi.m_num;
	return out;
}

// ����ǰ��++
void test01()
{
	MyInteger mi;
	cout << "ǰ��++" << endl;
	cout << ++(++mi) << endl;
	cout << mi << endl;
}

// ���Ժ���++
void test02()
{
	MyInteger mi;
	cout << "����++" << endl;
	cout << mi++ << endl;
	cout << mi << endl;
}

//int main()
//{
//	test01();
//	test02();
//
//	return 0;
//}