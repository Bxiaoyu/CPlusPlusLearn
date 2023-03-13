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
		LNode<T>* rear;  // 队尾指针
	public:
		LinkQueue()
		{
			rear = head;  // 由基类LinkList的构造函数构造空的链表后，rear指向单链表头结点
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
			p->next = nullptr;  // 新节点指针域为空
			rear->next = p;
			rear = p;
			return true;
		}

		bool DeQueue(T& e)
		{
			bool flag = ListDelete(1, e);  // 删除单链表第一个元素
			if (head->next == nullptr)  // 删除后如果成空表
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

	// 测试
	void test_func()
	{
		bool i;
		int d;
		LinkQueue<int> q;
		for (int k = 0; k < 5; ++k)
			assert(q.EnQueue(k));
		cout << "入队5个元素后，队列的元素依次为：";
		q.QueueTraverse(mprint<int>);
		cout << "队列是否为空？" << boolalpha << q.QueueEmpty();
		cout << "对列的长度为：" << q.QueueLength() << endl;
		q.DeQueue(d);
		cout << "出队了队头元素，其值为：" << d;
		i = q.GetHead(d);
		if (i)
		{
			cout << "新的队头元素是：" << d << endl;
		}
		q.ClearQueue();
		cout << "清空队列后，是否空队列？" << boolalpha << q.QueueEmpty();
		cout << "。队列的长度为：" << q.QueueLength() << endl;
	}
}

#endif