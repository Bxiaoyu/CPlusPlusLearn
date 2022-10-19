#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

// 逻辑仿函数
void test_logical()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (auto it : v)
	{
		cout << it << " ";
	}
	cout << endl << "------------------" << endl;

	// 利用逻辑非 将容器v中的元素搬运到容器v2中，并执行取反操作
	vector<bool> v2;
	v2.resize(v.size());

	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	for (auto it : v2)
	{
		cout << it << " ";
	}
}

int main()
{
	test_logical();
	return 0;
}