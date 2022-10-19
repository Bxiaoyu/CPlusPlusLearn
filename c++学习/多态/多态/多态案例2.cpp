#include <iostream>
#include <string>

using namespace std;


// 抽象不同零件类
// 抽象cpu类
class CPU {
public:
	// 抽象计算函数
	virtual void calc() = 0;
};

// 抽象Gpu类
class GPU {
public:
	// 抽象计算函数
	virtual void display() = 0;
};

// 抽象Memory类
class Memory {
public:
	// 抽象计算函数
	virtual void storage() = 0;
};

// 电脑类
class Computer {
public:
	Computer(CPU* cpu, GPU* gpu, Memory* memory)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_memory = memory;
	}

	// 析构，释放堆区数据
	~Computer()
	{
		// 释放cpu指针
		if (m_cpu != nullptr)
		{
			delete m_cpu;
			m_cpu = nullptr;
		}

		// 释放gpu指针
		if (m_gpu != nullptr)
		{
			delete m_gpu;
			m_gpu = nullptr;
		}

		// 释放memory指针
		if (m_memory != nullptr)
		{
			delete m_memory;
			m_memory = nullptr;
		}
	}

	// 提供一个工作函数
	void work()
	{
		// 让零件工作，调用接口
		m_cpu->calc();
		m_gpu->display();
		m_memory->storage();
	}

private:
	CPU* m_cpu;    // CPU零件指针
	GPU* m_gpu;    // GPU零件指针
	Memory* m_memory; // 内存零件指针
};

// 具体厂商
class IntelCpu :public CPU {
public:
	void calc()
	{
		cout << "Intel的CPU开始工作" << endl;
	}
};

class IntelGpu :public GPU {
public:
	void display()
	{
		cout << "Intel的显卡开始工作" << endl;
	}
};

class IntelMemory :public Memory {
public:
	void storage()
	{
		cout << "Intel的内存条开始工作" << endl;
	}
};

class LenovoCpu :public CPU {
public:
	void calc()
	{
		cout << "Lenovo的CPU开始工作" << endl;
	}
};

class LenovoGpu :public GPU {
public:
	void display()
	{
		cout << "Lenovo的显卡开始工作" << endl;
	}
};

class LenovoMemory :public Memory {
public:
	void storage()
	{
		cout << "Lenovo的内存条开始工作" << endl;
	}
};

void test_computer()
{
	// 第一台电脑零件
	cout << "第一台电脑开始工作" << endl;
	CPU* intelcpu = new IntelCpu;
	GPU* intelgpu = new IntelGpu;
	Memory* intelMem = new IntelMemory;
	// 创建第一台电脑
	Computer* com1 = new Computer(intelcpu, intelgpu, intelMem);
	com1->work();
	delete com1;

	// 第二台电脑
	cout << endl << "第二台电脑开始工作" << endl;
	Computer* com2 = new Computer(new LenovoCpu, new LenovoGpu, new LenovoMemory);
	com2->work();
	delete com2;

	// 第三台电脑
	cout << endl << "第三台电脑开始工作" << endl;
	Computer* com3 = new Computer(new IntelCpu, new IntelGpu, new LenovoMemory);
	com3->work();
	delete com3;
}

int main()
{
	test_computer();
	return 0;
}