#include <iostream>

using namespace std;

class Person {
public:
	void showClassName()
	{
		cout << "this is Person class" << endl;
	}

	void showAge()
	{
		// ����ǰ�涼Ĭ�ϼ���һ��this->���ã������ָ��Ϊ�գ���������ʱ�ᱨ��
		if (this == nullptr) // �ж�thisָ���Ƿ�Ϊ�գ����Ӵ��뽡׳��
			return;
		cout << "age = " << m_age << endl;
	}

public:
	int m_age;
};

void test()
{
	Person *p = nullptr;
	p->showClassName(); // ��ȷ
	p->showAge();       // ���� �����ָ��ʱҪ��ָ��Ϸ����жϣ�����ᱨ��
}