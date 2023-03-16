#pragma once
#ifndef _SQQUEUECY_H_
#define _SQQUEUECY_H_
#include "C.h"
#include "AQueue.h"
#include "helper.h"


namespace NPSqQueueCy
{
	/*!
	 * @brief 队列的顺序存储结构，形成循环，是一种很实用的队列
	 * @tparam T 数据类型
	*/
	template<typename T>
	class SqQueueCy : public AQueue<T>
	{
	protected:
		T* base;  // 初始化的动态分配存储空间
		int front;  // 头指针，若队列不为空，指示队列头元素的位置
		int rear;   // 尾指针，若队列不为空，指示队列尾元素的下一个位置
		int queuesize;  // 当前分配的存储容量
	public:
		SqQueueCy(int k = 1)
		{
			base = new T[k];
			assert(base != nullptr);
			front = rear = 0;
			queuesize = k;
		}

		~SqQueueCy()
		{
			delete[] base;
		}

		void ClearQueue()
		{
			front = rear = 0;
		}

		bool QueueEmpty() const
		{
			return front == rear;
		}

		int QueueLength() const
		{
			// +queuesize确保在rear<front时返回非负值，%queuesize确保返回值小于queuesize
			return (rear - front + queuesize) % queuesize;
		}

		bool GetHead(T& e) const
		{
			if (front == rear)  // 队列空
			{
				return false;
			}
			e = *(base + front);
			return true;
		}

		bool EnQueue(T e)
		{
			T* newBase;
			int i;
			if ((rear + 1) % queuesize == front)  // 队列满，增加存储容量
			{
				newBase = new T[queuesize * 2];  // 扩容为原来的2倍
				if (newBase == nullptr)
				{
					return false;
				}
				for (i = 0; i < queuesize - 1; ++i)  // 将原队列元素复制到新队列
				{
					*(newBase + i) = *(base + (front + i) % queuesize);
				}
				delete[] base;
				base = newBase;
				front = 0;
				rear = queuesize - 1;  // 队尾元素+1的位置
				queuesize *= 2;
			}
			*(base + rear) = e;
			rear = ++rear % queuesize;  // 移动尾指针
			return true;
		}

		bool DeQueue(T& e)
		{
			if (front == rear)
			{
				return false;
			}
			e = *(base + front);
			front = ++front % queuesize;  // 移动头指针
			return true;
		}

		void QueueTraverse(void(*visit)(T*)) const
		{
			int i = front;
			while (i != rear)
			{
				visit(base + i);
				i = ++i % queuesize;
			}
			cout << endl;
		}
	};

	/*!
	 * @brief 非循环队列，出队队头元素的时候，需要移动后面的元素，数据量大的时候时间开销很惊人
	 * @tparam T 数据类型
	*/
	template<typename T>
	class SqQueue
	{
	private:
		T* base;  // 初始化的动态分配存储空间
		int rear;  // 尾指针
		int queuesize;  // 当前分配的存储空间
	public:
		SqQueue(int k = 1)
		{
			base = new T[k];
			assert(base != nullptr);
			rear = 0;
			queuesize = k;
		}

		~SqQueue()
		{
			delete[] base;
		}

		bool EnQueue(T e)
		{
			if (rear == queuesize)
			{
				return false;
			}
			*(base + rear++) = e;
			return true;
		}

		bool DeQueue(T& e)
		{
			if (rear == 0)  // 队空
			{
				return false;
			}
			e = *base;  // 队头元素赋给e
			for (int i = 1; i < rear; ++i)
			{
				*(base + i - 1) = *(base + i);  // 依次前移队列元素
			}
			rear--;  // 尾指针前移
			return true;
		}

		void QueueTraverse(void(*visit)(T*)) const
		{
			for (int i = 0; i < rear; ++i)
			{
				visit(base + i);
			}
			cout << endl;
		}
	};

	template<typename T>
	class SqQueueNM : public SqQueueCy<T>
	{
	public:
		SqQueueNM(int k) : SqQueueCy<T>(k)
		{
			// 构造函数，调用基类的有参构造函数
		}

		bool EnQueue(T e)
		{
			if (rear == queuesize)
			{
				return false;
			}
			*(base + rear++) = e;
			return true;
		}

		bool DeQueue(T& e)
		{
			if (front == rear)
			{
				return false;
			}
			e = *(base + front++);
			return true;
		}

		int QueueLength() const
		{
			return rear - front;
		}

		void QueueTraverse(void(*visit)(T*)) const
		{
			for (int i = front; i < rear; ++i)
			{
				visit(base + i);
			}
			cout << endl;
		}
	};

	// 测试
	void test_func()
	{
		bool i;
		int d;
		SqQueueCy<int> q{ 3 };
		for (int k = 0; k < 5; ++k)
		{
			assert(q.EnQueue(k));
		}
		cout << "入队5个元素后，队列的元素依次为：";
		q.QueueTraverse(mprint<int>);
		cout << "队列是否为空？" << boolalpha << q.QueueEmpty();
		cout << "。队列的长度为：" << q.QueueLength() << endl;
		q.DeQueue(d);
		cout << "出队了队头元素，其值为：" << d;
		i = q.GetHead(d);
		if (i)
		{
			cout << "。新的队头元素是" << d << endl;
		}
		q.ClearQueue();
		cout << "清空队列后，是否空队列？" << boolalpha << q.QueueEmpty();
		cout << "。队列的长度为：" << q.QueueLength() << endl;
	}
}

#endif