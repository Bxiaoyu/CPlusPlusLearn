#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �º���������bool���͵ķº�����Ϊ`ν��`
// ���operator()����һ����������ô����һԪν��

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

	// ���������д���5����
	// GreaterFive()������������
	auto it = find_if(v.begin(), v.end(), GreaterFive());
	//auto it = find_if(v.begin(), v.end(), [](auto val) {
	//	return val > 5;
	//	}); // lambda���ʽҲ���Դﵽ����Ч��
	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�����5������Ϊ��" << *it << endl;
	}
}

//int main()
//{
//	test();
//	return 0;
//}