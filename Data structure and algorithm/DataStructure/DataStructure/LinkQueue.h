#pragma once
#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_
#include "AQueue.h"
#include "LinkList.h"

using namespace NPLinkList;

namespace NPLinkQueue
{
	template<typename T>
	class LinkQueue : public AQueue<T>, public LinkList<T>
	{
	private:
		LNode<T>* rear;  // ��βָ��
	public:
		LinkQueue()
		{
			rear = head;  // �ɻ���LinkList�Ĺ��캯������յ������rearָ������ͷ���
		}

		void ClearQueue()
		{
			ClearList();
			rear = head;
		}
		
		bool QueueEmpty() const
		{
			return ListEmpty();
		}

		int QueueLength() const
		{
			return ListLength();
		}

		bool GetHead(T& e) const
		{
			return GetElem(1, e);
		}

		bool EnQueue(T e)
		{
			LNode<T>* p;
			p = new LNode<T>;
			if (p == nullptr)
			{
				return false;
			}
			p->data = e;
			p->next = nullptr;  // �½ڵ�ָ����Ϊ��
			rear->next = p;
			rear = p;
			return true;
		}

		bool DeQueue(T& e)
		{
			bool flag = ListDelete(1, e);  // ɾ���������һ��Ԫ��
			if (head->next == nullptr)  // ɾ��������ɿձ�
			{
				rear = head;
			}
			return flag;
		}

		void QueueTraverse(void(*visit)(T*)) const
		{
			ListTraverse(visit);
		}
	};

	// ����
	void test_func()
	{
		bool i;
		int d;
		LinkQueue<int> q;
		for (int k = 0; k < 5; ++k)
			assert(q.EnQueue(k));
		cout << "���5��Ԫ�غ󣬶��е�Ԫ������Ϊ��";
		q.QueueTraverse(mprint<int>);
		cout << "�����Ƿ�Ϊ�գ�" << boolalpha << q.QueueEmpty();
		cout << "���еĳ���Ϊ��" << q.QueueLength() << endl;
		q.DeQueue(d);
		cout << "�����˶�ͷԪ�أ���ֵΪ��" << d;
		i = q.GetHead(d);
		if (i)
		{
			cout << "�µĶ�ͷԪ���ǣ�" << d << endl;
		}
		q.ClearQueue();
		cout << "��ն��к��Ƿ�ն��У�" << boolalpha << q.QueueEmpty();
		cout << "�����еĳ���Ϊ��" << q.QueueLength() << endl;
	}
}

#endif