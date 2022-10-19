#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

void test_greater()
{
	vector<int> v;
	v.emplace_back(10);
	v.emplace_back(50);
	v.emplace_back(80);
	v.emplace_back(20);
	v.emplace_back(30);
	v.emplace_back(40);

	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << "------------------" << endl;

	// ½µÐò
	sort(v.begin(), v.end(), greater<int>());
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//int main()
//{
//	test_greater();
//	return 0;
//}