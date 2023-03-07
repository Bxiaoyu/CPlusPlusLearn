#pragma once
#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_
#include <iostream>
#include "AList.h"
#include "helper.h"

using namespace std;

namespace NPDLinkList
{
	/*!
	 * @brief 双向结点类型结构体
	 * @tparam T 数据类型
	*/
	template<typename T>
	struct DLNode
	{
		T data;
		DLNode<T>* prior, * next;  // 前驱后继指针
	};

	template<typename T>
	class DLinkList : public AList<T>
	{
	private:
		DLNode<T>* head;  // 头指针

	private:
		/*!
		 * @brief 返回第i个结点的地址
		 * @param i 位序
		 * @return i为0，返回头结点地址，成功返回地址，失败返回nullptr
		*/
		DLNode<T>* GetElemP(int i) const
		{
			int j = 0;
			DLNode<T>* p = head;  // p指向头结点
			if (i < 0)  // 值非法
			{
				return nullptr;
			}

			if (i == 0)
			{
				return p;  // 返回头结点
			}

			do 
			{
				p = p->next;
				j++;
			} while (j < i && p != head);  // p没返回到头结点且还没到第i个结点

			if (p == head)  // 不存在
			{
				return nullptr;
			}
			else
			{
				return p;
			}
		}

		/*!
		 * @brief 返回第一个与e满足定义的eq()相等关系的数据元素的地址
		 * @param e 目标元素
		 * @param eq 比较函数
		 * @return 存在返回地址，不存在返回nullptr
		*/
		DLNode<T>* GetElemE(T e, bool(*eq)(T, T)) const
		{
			DLNode<T>* p = head->next;  // p指向第一个结点
			while (p != head && !eq(e, p->data))
			{
				p = p->next;
			}

			if (p == head)  // 等于e的元素不存在
			{
				return nullptr;
			}
			else
			{
				return p;
			}
		}

	public:
		DLinkList()
		{
			head = new DLNode<T>;
			assert(head != nullptr);
			head->prior = head->next = head;
		}

		~DLinkList()
		{
			ClearList();
			delete head;
		}

		void ClearList() const
		{
			DLNode<T>* p = head->next;
			while (p != head)
			{
				p = p->next;
				delete p->prior;
			}
			head->next = head->prior = head;
		}

		bool ListEmpty() const
		{
			return head->next == head;
		}

		int ListLength() const
		{
			int i = 0;
			DLNode<T>* p = head->next;  // p指向第一个结点
			while (p != head)
			{
				i++;
				p = p->next;
			}
			return i;
		}

		bool GetElem(int i, T& e) const
		{
			DLNode<T>* p = GetElemP(i);
			if (p != nullptr && i > 0)
			{
				e = p->data;
				return true;
			}
			return false;
		}

		int LocateElem(T e, bool(*eq)(T, T)) const
		{
			int i = 0;
			DLNode<T>* p = head->next;

			while (p != head)
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
			DLNode<T>* p = GetElemE(e, eq);
			if (p != nullptr && p->prior != head)  // p指向值为e的结点且该结点不是第一个结点
			{
				pre_e = p->prior->data;
				return true;
			}
			return false;
		}

		bool NextElem(T e, bool(*eq)(T, T), T& next_e) const
		{
			DLNode<T>* p = GetElemE(e, eq);
			if (p != nullptr && p->next != head)  // p指向值为e的结点并且该结点不是最后一个结点
			{
				next_e = p->next->data;
				return true;
			}
			return false;
		}

		bool ListInsert(int i, T e)
		{
			DLNode<T>* p = GetElemP(i-1), *s;
			if (p == nullptr)  // 第i个结点的前驱不存在
			{
				return false;
			}
			s = new DLNode<T>;
			if (s == nullptr)
			{
				return false;
			}
			s->data = e;
			s->prior = p;
			s->next = p->next;
			p->next->prior = s;
			p->next = s;
			return true;
		}

		bool ListDelete(int i, T& e) const
		{
			DLNode<T>* p = GetElemP(i);
			if (i <= 0 || p == nullptr)
			{
				return false;
			}
			e = p->data;
			p->prior->next = p->next;
			p->next->prior = p->prior;
			delete p;
			return true;
		}

		void ListTraverse(void(*visit) (T*)) const
		{
			DLNode<T>* p = head->next;
			while (p != head)
			{
				visit(&p->data);
				p = p->next;
			}
			cout << endl;
		}

		void ListBackTraverse(void(*visit) (T*)) const
		{
			DLNode<T>* p = head->prior;
			while (p != head)
			{
				visit(&p->data);
				p = p->prior;
			}
			cout << endl;
		}
	};

	// 测试
	void test_func()
	{
		DLinkList<int> list;
		int i, n = 4;
		bool j;
		int e;
		for (i = 1; i <= 5; ++i)
		{
			list.ListInsert(i, i);
		}
		cout << "在表尾依次插入1-5后，l=";
		list.ListTraverse(mprint<int>);
		j = list.GetElem(2, e);
		if (j)
		{
			cout << "链表的第二个元素值为" << e << endl;
		}
		else
		{
			cout << "不存在第2个元素" << endl;
		}
		i = list.LocateElem(n, equal);
		if (i)
		{
			cout << "等于" << n << "的元素是第" << i << "个" << endl;
		}
		else
		{
			cout << "没有等于" << n << "的元素" << endl;
		}
		j = list.PriorElem(n, equal, e);
		if (j)
		{
			cout << n << "的前驱是" << e << endl;
		}
		else
		{
			cout << "不存在" << n << "的前驱" << endl;
		}
		j = list.NextElem(n, equal, e);
		if (j)
		{
			cout << n << "的后继是" << e << endl;
		}
		else
		{
			cout << "不存在" << n << "的后继" << endl;
		}

		list.ListDelete(2, e);
		cout << "删除第2个结点，值为" << e << "，逆序输出其余结点：";
		list.ListBackTraverse(mprint<int>);
		cout << "链表的元素个数为" << list.ListLength() << "，";
		cout << "链表是否为空？" << boolalpha << list.ListEmpty() << endl;
		list.ClearList();
		cout << "清空后，链表是否为空？" << boolalpha << list.ListEmpty() << endl;
	}
}

#endif