#pragma once
#ifndef _LINKLISTCY_H
#define _LINKLISTCY_H

#include "C.h"
#include "AList.h"
#include "helper.h"

namespace NPLinkListCy
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
	 * @brief 单循环链表类，设置尾指针（查找头结点和最后一个结点都很方便）
	 * @tparam T
	*/
	template<typename T>
	class LinkListCy : public AList<T>
	{
		template<typename T>
		friend void mergeList(LinkListCy<T>&, LinkListCy<T>&);

	private:
		LNode<T>* tail;  // 表尾

	public:
		LinkListCy()
		{
			tail = new LNode<T>;
			assert(tail != nullptr);
			tail->next = tail;
		}

		~LinkListCy()
		{
			ClearList();
			delete tail;
		}

		void ClearList()
		{
			LNode<T>* p, * q;
			tail = tail->next;  // tail指向头结点
			p = tail->next;  // p指向第一个结点
			while (p != tail)
			{
				q = p->next;
				delete p;
				p = q;
			}
			tail->next = tail;
		}

		bool ListEmpty() const
		{
			return tail->next == tail;
		}

		int ListLength() const
		{
			int i = 0;
			LNode<T>* p = tail->next;  // p指向头结点
			while (p != tail)
			{
				i++;
				p = p->next;
			}

			return i;
		}

		bool GetElem(int i, T& e) const
		{
			LNode<T>* p = tail->next->next;  // p指向第一个结点
			int j = 1;
			if (i <= 0 || i > ListLength())
			{
				return false;
			}

			while (j < i)
			{
				j++;
				p = p->next;
			}

			e = p->data;

			return true;
		}

		int LocateElem(T e, bool(*eq)(T, T)) const
		{
			int i = 0;
			LNode<T>* p = tail->next->next;  // p指向第一个结点
			while (p != tail->next)  // p没指向头结点
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
			LNode<T>* q, * p = tail->next->next;  // p指向第一个结点
			q = p->next;  // q指向p的后继
			while (q != tail->next)  // q没指向头结点
			{
				if (eq(e, q->data))
				{
					pre_e = p->data;
					return true;
				}
				p = q;
				q = q->next;
			}
			return false;
		}

		bool NextElem(T e, bool(*eq)(T, T), T& next_e) const
		{
			LNode<T>* p = tail->next->next;
			while (p != tail)
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
			LNode<T>* p = tail->next, * s;
			if (i <= 0 || i > ListLength() + 1)
			{
				return false;
			}
			while (j < i - 1)
			{
				j++;
				p = p->next;
			}

			s = new LNode<T>;
			if (s == nullptr)
			{
				return false;
			}
			s->data = e;
			s->next = p->next;
			p->next = s;
			if (p == tail)  // 插在表尾
			{
				tail = s;
			}
			return true;
		}

		bool ListDelete(int i, T& e)
		{
			int j = 0;
			LNode<T>* q, * p = tail->next;
			if (i <= 0 || i > ListLength())
			{
				return false;
			}

			while (j < i-1)
			{
				j++;
				p = p->next;
			}
			q = p->next;
			p->next = q->next;
			e = q->data;
			if (tail == q)  // 删除的是表尾元素
			{
				tail = p;
			}
			delete q;
			return true;
		}

		void ListTraverse(void(*visit) (T*)) const
		{
			LNode<T>* p = tail->next->next;  // 指向第一个结点
			while (p != tail->next)  // p不指向头结点
			{
				visit(&p->data);
				p = p->next;
			}

			cout << endl;
		}
	};

	template<typename T>
	void mergeList(LinkListCy<T>& la, LinkListCy<T>& lb)
	{
		LNode<T>* p = lb.tail->next;  // 将lb合并到la的表尾，由la指示新表，lb成空表
		lb.tail->next = la.tail->next;  // lb的尾指针指向la的头结点
		la.tail->next = p->next;  // la的尾结点的next域指向lb的第一个结点
		la.tail = lb.tail;  // lb的尾结点成为la的尾结点
		lb.tail = p;
		lb.tail->next = lb.tail;  // lb表为空
	}

	// 测试
	void test_merge()
	{
		LinkListCy<int> la, lb;
		for (int i = 1; i <= 3; ++i)
		{
			la.ListInsert(i, i);
			lb.ListInsert(i, i + 3);
		}

		cout << "la=";
		la.ListTraverse(mprint<int>);
		cout << "lb=";
		lb.ListTraverse(mprint<int>);
		mergeList(la, lb);
		cout << "New la=";
		la.ListTraverse(mprint<int>);
	}

	void test_func()
	{
		test_merge();
	}
}

#endif