#pragma once
#ifndef _SQQUEUECY_H_
#define _SQQUEUECY_H_
#include "C.h"
#include "AQueue.h"


namespace NPSqQueueCy
{
	/*!
	 * @brief 队列的顺序存储结构
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

		void clearQueue()
		{
			front = rear = 0;
		}

		bool queueEmpty() const
		{
			return front == rear;
		}

		int queueLength() const
		{
			// +queuesize确保在rear<front时返回非负值，%queuesize确保返回值小于queuesize
			return (rear - front + queuesize) % queuesize;
		}

		bool getHead(T& e) const
		{
			if (front == rear)  // 队列空
			{
				return false;
			}
			e = *(base + front);
			return true;
		}

		bool enQueue(T e)
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
					*(newBase + i) = *(base + (front + i) % queuesize)
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

		bool deQueue(T& e)
		{
			if (front == rear)
			{
				return false;
			}
			e = *(base + front);
			front = ++front % queuesize;  // 移动头指针
			return true;
		}

		void queueTraverse(void(*visit)(T*)) const
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
}

#endif