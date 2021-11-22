#include <iostream>
#include <string>

using namespace std;

// 计算器的抽象类
class AbstractCalculator {
public:
	virtual int getResult()
	{
		return 0;
	}
public:
	int m_Num1;
	int m_Num2;
};

// 加法计算器类
class AddCalculator :public AbstractCalculator {
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};

// 减法计算器类
class SubCalculator :public AbstractCalculator {
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

// 乘法计算器类
class MulCalculator :public AbstractCalculator {
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};

void test_calc()
{
	// 多态使用条件
	// 父类指针或者引用指向子类对象

	// 加法运算
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
	abc = nullptr;

	// 减法运算
	abc = new SubCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
	abc = nullptr;

	// 乘法运算
	abc = new MulCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
	abc = nullptr;
}

//int main()
//{
//	test_calc();
//	return 0;
//}