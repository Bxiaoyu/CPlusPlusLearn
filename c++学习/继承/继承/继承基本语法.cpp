#include <iostream>

using namespace std;

// ����ҳ����
class BasePage {
public:
	void header()
	{
		cout << "��ҳ�������Σ���¼��ע��...(����ͷ��)" << endl;
	}

	void footer()
	{
		cout << "�������ģ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
	}

	void left()
	{
		cout << "Java��Python��C++��...(���������б�)" << endl;
	}
};

// Javaҳ��
class Java :public BasePage {
public:
	void center()
	{
		cout << "Javaѧ����Ƶ" << endl;
	}
};