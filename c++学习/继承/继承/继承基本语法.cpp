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

// Pythonҳ��
class Python :public BasePage {
public:
	void center()
	{
		cout << "Pythonѧ����Ƶ" << endl;
	}
};

// c++ҳ��
class Cpp :public BasePage {
public:
	void center()
	{
		cout << "C++ѧ����Ƶ" << endl;
	}
};

//int main()
//{
//	cout << "javaҳ��" << endl;
//	Java ja;
//	ja.header();
//	ja.left();
//	ja.center();
//	ja.footer();
//
//	cout << "Pythonҳ��" << endl;
//	Python py;
//	py.header();
//	py.left();
//	py.center();
//	py.footer();
//
//	cout << "C++ҳ��" << endl;
//	Cpp cp;
//	cp.header();
//	cp.left();
//	cp.center();
//	cp.footer();
//
//	return 0;
//}