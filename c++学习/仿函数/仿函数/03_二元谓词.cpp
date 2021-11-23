#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 二元谓词
class MyCompare {
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

void test04()
{
	vector<int> v;
	v.emplace_back(10);
	v.emplace_back(50);
	v.emplace_back(80);
	v.emplace_back(20);
	v.emplace_back(30);
	v.emplace_back(40);

	sort(v.begin(), v.end());
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl <<"-------------------------" << endl;

	// 使用函数对象，改变算法策略，变为排序规则从大到小
	sort(v.begin(), v.end(), MyCompare());
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//int main()
//{
//	test04();
//	return 0;
//}