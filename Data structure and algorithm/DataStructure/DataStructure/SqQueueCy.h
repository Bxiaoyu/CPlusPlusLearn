#pragma once
#ifndef _SQQUEUECY_H_
#define _SQQUEUECY_H_
#include "C.h"
#include "AQueue.h"


namespace NPSqQueueCy
{
	/*!
	 * @brief ���е�˳��洢�ṹ
	 * @tparam T ��������
	*/
	template<typename T>
	class SqQueueCy : public AQueue<T>
	{
	protected:
		T* base;  // ��ʼ���Ķ�̬����洢�ռ�
		int front;  // ͷָ�룬�����в�Ϊ�գ�ָʾ����ͷԪ�ص�λ��
		int rear;   // βָ�룬�����в�Ϊ�գ�ָʾ����βԪ�ص���һ��λ��
		int queuesize;  // ��ǰ����Ĵ洢����
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
			// +queuesizeȷ����rear<frontʱ���طǸ�ֵ��%queuesizeȷ������ֵС��queuesize
			return (rear - front + queuesize) % queuesize;
		}

		bool getHead(T& e) const
		{
			if (front == rear)  // ���п�
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
			if ((rear + 1) % queuesize == front)  // �����������Ӵ洢����
			{
				newBase = new T[queuesize * 2];  // ����Ϊԭ����2��
				if (newBase == nullptr)
				{
					return false;
				}
				for (i = 0; i < queuesize - 1; ++i)  // ��ԭ����Ԫ�ظ��Ƶ��¶���
				{
					*(newBase + i) = *(base + (front + i) % queuesize)
				}
				delete[] base;
				base = newBase;
				front = 0;
				rear = queuesize - 1;  // ��βԪ��+1��λ��
				queuesize *= 2;
			}
			*(base + rear) = e;
			rear = ++rear % queuesize;  // �ƶ�βָ��
			return true;
		}

		bool deQueue(T& e)
		{
			if (front == rear)
			{
				return false;
			}
			e = *(base + front);
			front = ++front % queuesize;  // �ƶ�ͷָ��
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