#pragma once
#ifndef _LINKLIST_H
#define _LINKLIST_H
#include "C.h"
#include "AList.h"
#include "helper.h"

namespace NPLinkList
{
	/*!
	 * @brief 单链表结点类型结构体
	 * @tparam T 数据类型
	*/
	template<typename T>
	struct LNode
	{
		T data;  // 结点数据类型
		LNode<T>* next;  // 后继指针
	};

	/*!
	 * @brief 带头结点的单链表类
	 * @tparam T 数据类型
	*/
	template<typename T>
	class LinkList : public AList<T>
	{
		template<typename T>
		friend void mergeList(LinkList<T>&, LinkList<T>&);

	protected:
		LNode<T>* head = nullptr;  // 头指针
		int length = 0;  // 当前元素个数
	public:
		LinkList()
		{
			head = new LNode<T>;  // 产生头结点
			assert(head != nullptr);
			head->next = nullptr;  // 头结点的指针域为空
		}

		~LinkList()
		{
			ClearList();
			delete head;
		}

		void ClearList()
		{
			LNode<T>* p = head->next, *q;  // p指向第一个结点
			head->next = nullptr;  // 头结点指针域为空

			while (p != nullptr)
			{
				q = p->next;
				delete p;
				p = q;
			}

			length = 0;
		}

		bool ListEmpty() const
		{
			return head->next == nullptr;
		}

		int ListLength() const
		{
			LNode<T>* p = head->next;
			int i = 0;

			while (p != nullptr)
			{
				i++;
				p = p->next;
			}

			return i;
		}

		int ListLength2() const
		{
			return length;
		}

		bool GetElem(int i, T& e) const
		{
			int j = 1;
			LNode<T>* p = head->next;
			while ( j < i && p != nullptr)
			{
				j++;
				p = p->next;
			}
			if (p == nullptr || j > i)
			{
				return false;
			}

			e = p->data;
			return true;
		}

		int LocateElem(T e, bool(*eq)(T, T)) const
		{
			int i = 0;
			LNode<T>* p = head->next;

			while (p != nullptr)
			{
				i++;
				if (eq(e, p->data))
				{
					return i;
				}
				p = p->next;
			}

			return 0;
		}

		bool PriorElem(T e, bool(*eq)(T, T), T& pre_e) const
		{
			LNode<T>* p = head->next, *q;
			while (p != nullptr && p->next != nullptr)
			{
				q = p->next;
				if (eq(e, q->data))
				{
					pre_e = p->data;
					return true;
				}
				p = q;
			}

			return false;
		}

		bool NextElem(T e, bool(*eq)(T, T), T& next_e) const
		{
			LNode<T>* p = head->next;
			while (p != nullptr && p->next != nullptr)
			{
				if (eq(e, p->data))
				{
					next_e = p->next->data;
					return true;
				}
				p = p->next;
			}
			return false;
		}

		bool ListInsert(int i, T e)
		{
			int j = 0;
			LNode<T>* p = head, * s;
			while (j < i - 1 && p != nullptr)
			{
				j++;
				p = p->next;
			}
			if (p == nullptr || j > i-1)
			{
				return false;
			}

			s = new LNode<T>;
			if (s == nullptr)
			{
				return false;
			}
			s->data = e;
			s->next = p->next;
			p->next = s;
			length++;
			return true;
		}

		bool ListDelete(int i, T& e)
		{
			int j = 0;
			LNode<T>* p = head, *q;

			while (p->next != nullptr && j < i - 1)  // 寻找第i个结点，并使p指向其前驱
			{
				j++;
				p = p->next;
			}

			if (j > i - 1 || p->next == nullptr)  // 删除位置不合理
			{
				return false;
			}

			q = p->next;
			e = q->data;
			p->next = q->next;
			delete q;
			length--;
			return true;
		}

		void ListTraverse(void(*visit) (T*)) const
		{
			LNode<T>* p = head->next;
			while (p != nullptr)
			{
				visit(&p->data);
				p = p->next;
			}
			std::cout << "\n";
		}
	};

	/*!
	 * @brief 合并两个有序链表
	 * @tparam T 数据类型
	 * @param  la 链表1
	 * @param  lb 链表2
	*/
	template<typename T>
	void mergeList(LinkList<T>& la, LinkList<T>& lb)
	{
		LNode<T>* pa = la.head->next, * pb = lb.head->next, *p;
		p = la.head;

		while (pa && pb)
		{
			if (pa->data <= pb->data)
			{
				p->next = pa;
				p = pa;
				pa = pa->next;
			}
			else
			{
				p->next = pb;
				p = pb;
				pb = pb->next;
			}
		}

		p->next = pa ? pa : pb;  // 插入剩余段
		lb.head->next = nullptr;  // lb表为空
	}

	// 测试
	void merge_test()
	{
		LinkList<int> la, lb;
		for (int i = 1; i <= 5; ++i)
		{
			la.ListInsert(i, i);
			lb.ListInsert(i, i * 2);
		}

		cout << "la=";
		la.ListTraverse(mprint<int>);
		cout << "lb=";
		lb.ListTraverse(mprint<int>);
		mergeList(la, lb);
		cout << "New la=";
		la.ListTraverse(mprint<int>);
		cout << "New lb=";
		lb.ListTraverse(mprint<int>);
	}

	void test_func()
	{
		typedef int T;
		bool i;
		int j, k;
		T e, e0;
		LinkList<T> list;
		for (j = 1; j <= 5; ++j)
		{
			list.ListInsert(1, j);
		}
		std::cout << "在L表头依次插入1-5后，L=";
		list.ListTraverse(mprint<T>);
		cout << "L是否为空？" << boolalpha << list.ListEmpty() << "，表L的长度=";
		cout << list.ListLength();
		cout << "，表L的长度=";
		cout << list.ListLength2() << endl;

		for (j = 0; j <= 1; j++)
		{
			k = list.LocateElem(j, equal);
			if (k)
			{
				cout << "值为" << j << "的元素是第" << k << "个元素" << endl;
			}
			else
			{
				cout << "没有值为" << j << "的元素，";
			}
		}

		for (j = 1; j <= 2; j++)
		{
			list.GetElem(j, e0);
			i = list.PriorElem(e0, equal, e);
			if (i)
			{
				cout << "元素" << e0 << "的前驱为" << e << endl;
			}
			else
			{
				cout << "元素" << e0 << "无前驱，";
			}
		}

		for (j = list.ListLength(); j >= list.ListLength() - 1; j--)
		{
			list.GetElem(j, e0);
			i = list.NextElem(e0, equal, e);
			if (i)
			{
				cout << "元素" << e0 << "的后继为" << e << endl;
			}
			else
			{
				cout << "元素" << e0 << "无后继，";
			}
		}

		k = list.ListLength2();
		for (j = k+1; j >= k; j--)
		{
			i = list.ListDelete(j, e);
			if (i)
			{
				cout << "删除第" << j << "个元素成功，其值为" << e << endl;
			}
			else
			{
				cout << "删除第" << j << "个元素失败（不存在此元素），";
			}
		}

		cout << "删除元素后表L的长度=" << list.ListLength() << "，表L的长度=" << list.ListLength2() << endl;
		list.ClearList();
		cout << "清空表L后，L是否为空？" << boolalpha << list.ListEmpty() << "，表L的长度=" << list.ListLength() << "，表L的长度=" <<
			list.ListLength2() << endl;

		cout << endl;
		merge_test();
	}
}

#endif