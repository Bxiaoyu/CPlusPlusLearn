#pragma once
#ifndef _SQQUEUECY_H_
#define _SQQUEUECY_H_
#include "C.h"
#include "AQueue.h"
#include "helper.h"


namespace NPSqQueueCy
{
	/*!
	 * @brief ���е�˳��洢�ṹ���γ�ѭ������һ�ֺ�ʵ�õĶ���
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
			// +queuesizeȷ����rear<frontʱ���طǸ�ֵ��%queuesizeȷ������ֵС��queuesize
			return (rear - front + queuesize) % queuesize;
		}

		bool GetHead(T& e) const
		{
			if (front == rear)  // ���п�
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
			if ((rear + 1) % queuesize == front)  // �����������Ӵ洢����
			{
				newBase = new T[queuesize * 2];  // ����Ϊԭ����2��
				if (newBase == nullptr)
				{
					return false;
				}
				for (i = 0; i < queuesize - 1; ++i)  // ��ԭ����Ԫ�ظ��Ƶ��¶���
				{
					*(newBase + i) = *(base + (front + i) % queuesize);
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

		bool DeQueue(T& e)
		{
			if (front == rear)
			{
				return false;
			}
			e = *(base + front);
			front = ++front % queuesize;  // �ƶ�ͷָ��
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
	 * @brief ��ѭ�����У����Ӷ�ͷԪ�ص�ʱ����Ҫ�ƶ������Ԫ�أ����������ʱ��ʱ�俪���ܾ���
	 * @tparam T ��������
	*/
	template<typename T>
	class SqQueue
	{
	private:
		T* base;  // ��ʼ���Ķ�̬����洢�ռ�
		int rear;  // βָ��
		int queuesize;  // ��ǰ����Ĵ洢�ռ�
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
			if (rear == 0)  // �ӿ�
			{
				return false;
			}
			e = *base;  // ��ͷԪ�ظ���e
			for (int i = 1; i < rear; ++i)
			{
				*(base + i - 1) = *(base + i);  // ����ǰ�ƶ���Ԫ��
			}
			rear--;  // βָ��ǰ��
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
			// ���캯�������û�����вι��캯��
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

	// ����
	void test_func()
	{
		bool i;
		int d;
		SqQueueCy<int> q{ 3 };
		for (int k = 0; k < 5; ++k)
		{
			assert(q.EnQueue(k));
		}
		cout << "���5��Ԫ�غ󣬶��е�Ԫ������Ϊ��";
		q.QueueTraverse(mprint<int>);
		cout << "�����Ƿ�Ϊ�գ�" << boolalpha << q.QueueEmpty();
		cout << "�����еĳ���Ϊ��" << q.QueueLength() << endl;
		q.DeQueue(d);
		cout << "�����˶�ͷԪ�أ���ֵΪ��" << d;
		i = q.GetHead(d);
		if (i)
		{
			cout << "���µĶ�ͷԪ����" << d << endl;
		}
		q.ClearQueue();
		cout << "��ն��к��Ƿ�ն��У�" << boolalpha << q.QueueEmpty();
		cout << "�����еĳ���Ϊ��" << q.QueueLength() << endl;
	}
}

#endif