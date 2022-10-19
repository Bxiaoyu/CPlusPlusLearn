#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ��Ԫν��
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

	// ʹ�ú������󣬸ı��㷨���ԣ���Ϊ�������Ӵ�С
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