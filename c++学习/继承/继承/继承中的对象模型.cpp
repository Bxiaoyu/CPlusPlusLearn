#include <iostream>
using namespace std;

// �̳��еĶ���ģ��
class Base {
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c; // ˽�г�Աֻ�Ǳ������������ˣ����ǻᱻ�̳���ȥ
};

class Son :public Base {
public:
	int m_d;
};

// ���ÿ�����Ա������ʾ���߲鿴����ģ��
// ��ת�̷� F��
// ��ת�ļ�·�� cd ����·��
// �鿴����
// cl /d1 reportSingleClassLayout���� �ļ���

void test()
{
	// ���������зǾ�̬��Ա���Զ��ᱻ����̳���ȥ
	// ������˽�г�Ա���� �Ǳ��������������ˣ�����Ƿ��ʲ����ģ�����ȷʵ���̳�������
	cout << "size of Son = " << sizeof(Son) << endl; // �����size of Son = 16
}