#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 仿函数，返回bool类型的仿函数称为`谓词`
// 如果operator()接受一个参数，那么叫做一元谓词

class GreaterFive {
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.emplace_back(i + 1);
	}

	// 查找容器中大于5的数
	// GreaterFive()匿名函数对象
	auto it = find_if(v.begin(), v.end(), GreaterFive());
	//auto it = find_if(v.begin(), v.end(), [](auto val) {
	//	return val > 5;
	//	}); // lambda表达式也可以达到这种效果
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到大于5的数字为：" << *it << endl;
	}
}

//int main()
//{
//	test();
//	return 0;
//}