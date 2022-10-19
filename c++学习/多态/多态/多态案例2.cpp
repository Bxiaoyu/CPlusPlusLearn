#include <iostream>
#include <string>

using namespace std;


// ����ͬ�����
// ����cpu��
class CPU {
public:
	// ������㺯��
	virtual void calc() = 0;
};

// ����Gpu��
class GPU {
public:
	// ������㺯��
	virtual void display() = 0;
};

// ����Memory��
class Memory {
public:
	// ������㺯��
	virtual void storage() = 0;
};

// ������
class Computer {
public:
	Computer(CPU* cpu, GPU* gpu, Memory* memory)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_memory = memory;
	}

	// �������ͷŶ�������
	~Computer()
	{
		// �ͷ�cpuָ��
		if (m_cpu != nullptr)
		{
			delete m_cpu;
			m_cpu = nullptr;
		}

		// �ͷ�gpuָ��
		if (m_gpu != nullptr)
		{
			delete m_gpu;
			m_gpu = nullptr;
		}

		// �ͷ�memoryָ��
		if (m_memory != nullptr)
		{
			delete m_memory;
			m_memory = nullptr;
		}
	}

	// �ṩһ����������
	void work()
	{
		// ��������������ýӿ�
		m_cpu->calc();
		m_gpu->display();
		m_memory->storage();
	}

private:
	CPU* m_cpu;    // CPU���ָ��
	GPU* m_gpu;    // GPU���ָ��
	Memory* m_memory; // �ڴ����ָ��
};

// ���峧��
class IntelCpu :public CPU {
public:
	void calc()
	{
		cout << "Intel��CPU��ʼ����" << endl;
	}
};

class IntelGpu :public GPU {
public:
	void display()
	{
		cout << "Intel���Կ���ʼ����" << endl;
	}
};

class IntelMemory :public Memory {
public:
	void storage()
	{
		cout << "Intel���ڴ�����ʼ����" << endl;
	}
};

class LenovoCpu :public CPU {
public:
	void calc()
	{
		cout << "Lenovo��CPU��ʼ����" << endl;
	}
};

class LenovoGpu :public GPU {
public:
	void display()
	{
		cout << "Lenovo���Կ���ʼ����" << endl;
	}
};

class LenovoMemory :public Memory {
public:
	void storage()
	{
		cout << "Lenovo���ڴ�����ʼ����" << endl;
	}
};

void test_computer()
{
	// ��һ̨�������
	cout << "��һ̨���Կ�ʼ����" << endl;
	CPU* intelcpu = new IntelCpu;
	GPU* intelgpu = new IntelGpu;
	Memory* intelMem = new IntelMemory;
	// ������һ̨����
	Computer* com1 = new Computer(intelcpu, intelgpu, intelMem);
	com1->work();
	delete com1;

	// �ڶ�̨����
	cout << endl << "�ڶ�̨���Կ�ʼ����" << endl;
	Computer* com2 = new Computer(new LenovoCpu, new LenovoGpu, new LenovoMemory);
	com2->work();
	delete com2;

	// ����̨����
	cout << endl << "����̨���Կ�ʼ����" << endl;
	Computer* com3 = new Computer(new IntelCpu, new IntelGpu, new LenovoMemory);
	com3->work();
	delete com3;
}

int main()
{
	test_computer();
	return 0;
}