#include <iostream>

using namespace std;

// 公共页面类
class BasePage {
public:
	void header()
	{
		cout << "首页，公开课，登录，注册...(公共头部)" << endl;
	}

	void footer()
	{
		cout << "帮助中心，交流合作，站内地图...(公共底部)" << endl;
	}

	void left()
	{
		cout << "Java，Python，C++，...(公共分类列表)" << endl;
	}
};

// Java页面
class Java :public BasePage {
public:
	void center()
	{
		cout << "Java学科视频" << endl;
	}
};

// Python页面
class Python :public BasePage {
public:
	void center()
	{
		cout << "Python学科视频" << endl;
	}
};

// c++页面
class Cpp :public BasePage {
public:
	void center()
	{
		cout << "C++学科视频" << endl;
	}
};

//int main()
//{
//	cout << "java页面" << endl;
//	Java ja;
//	ja.header();
//	ja.left();
//	ja.center();
//	ja.footer();
//
//	cout << "Python页面" << endl;
//	Python py;
//	py.header();
//	py.left();
//	py.center();
//	py.footer();
//
//	cout << "C++页面" << endl;
//	Cpp cp;
//	cp.header();
//	cp.left();
//	cp.center();
//	cp.footer();
//
//	return 0;
//}