#pragma once
#ifndef _LINKLISTNH_H_
#define _LINKLISTNH_H_
#include "C.h"
#include "helper.h"

using namespace std;

namespace NPLinkListNH
{
	/*!
	 * @brief 链表结点类型结构体
	 * @tparam T 数据类型
	*/
	template<typename T>
	struct LNode
	{
		T data;
		LNode<T>* next;
	};

	/*!
	 * @brief 不设头结点的单链表类（对于插入和删除元素有所不同，在编程上会带来一些麻烦）
	 * @tparam T 数据类型
	*/
	template<typename T>
	class LinkListNH
	{
	private:
		LNode<T>* head;  // 头指针
	public:
		LinkListNH()
		{
			head = nullptr;  // 指针为空
		}

		~LinkListNH()
		{
			ClearList();
		}

		void ClearList()
		{
			LNode<T>*p;
			while (head != nullptr)  // 不为空表
			{
				p = head;  // p指向第一个结点
				head = head->next;
				delete p;
			}
		}

		int ListLength() const
		{
			int i = 0;
			LNode<T>* p = head;
			while (p != nullptr)
			{
				i++;
				p = p->next;
			}
			return i;
		}

		int LocateElem(T e, bool(*eq)(T, T)) const
		{
			int i = 0;
			LNode<T>* p = head;
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

		/*!
		 * @brief 查找表中第一个与e满足eq()关系的结点，找到则返回指向该结点的指针
		 * @param e 目标元素
		 * @param eq 比较函数指针
		 * @param p 指向满足条件结点的前驱
		 * @return 失败返回nullptr
		*/
		LNode<T>* Point(T e, bool(*eq)(T, T), LNode<T>*& p) const
		{
			if (head)  // 表不空
			{
				if (eq(e, head->data))
				{
					p = nullptr;
					return head;
				}
				else
				{
					p = head;
					while (p->next != nullptr)
					{
						if (eq(e, p->next->data))
						{
							return p->next;
						}
						else
						{
							p = p->next;
						}
					}
				}
			}
			return nullptr;
		}

		bool ListInsert(int i, T e)
		{
			int j = 1;
			LNode<T>* s, * p = head;
			if (i < 1)  // i值不合法
			{
				return false;
			}
			s = new LNode<T>;
			if (s == nullptr)
			{
				return false;
			}
			s->data = e;
			if (i == 1)  // 插在表头
			{
				s->next = head;
				head = s;
			}
			else
			{
				while (p != nullptr && j < i-1)  // 寻找第i-1个结点
				{
					j++;
					p = p->next;
				}
				if (p == nullptr)
				{
					return false;
				}
				else
				{
					s->next = p->next;
					p->next = s;
				}
			}
			return true;
		}

		bool ListDelete(T e, bool(*eq)(T, T))
		{
			LNode<T>* p, *q;
			q = Point(e, eq, p);  // p指向待删除结点的前驱
			if (q == nullptr)  // 没找到待删除结点
			{
				return false;
			}
			else
			{
				if (p == nullptr)  // 待删除结点是第一个结点
				{
					head = q->next;  // 删除结点
				}
				else
				{
					p->next = q->next;  // 删除结点
				}
				delete q;
				return true;
			}
		}

		void ListTraverse(void(*visit)(T*)) const
		{
			LNode<T>* p = head;
			while (p != nullptr)
			{
				visit(&p->data);
				p = p->next;
			}
			std::cout << std::endl;
		}
	};

	// 测试
	void test_func()
	{
		LinkListNH<int> list;
		bool i;
		int j, k;
		for (j = 1; j <= 5; ++j)
		{
			list.ListInsert(j, j);
		}
		cout << "在表尾依次插入1-5后，L=";
		list.ListTraverse(mprint<int>);
		cout << "表长=" << list.ListLength() << endl;

		for (j = 6; j >= 5; --j)
		{
			k = list.LocateElem(j, equal);
			if (k)
			{
				cout << "值为" << j << "的元素是表L的第" << k << "个元素，";
			}
			else
			{
				cout << "没有值为" << j << "的元素，";
			}
			i = list.ListDelete(j, equal);
			if (i == false)
			{
				cout << "删除元素" << j << "失败（不存在此元素）" << endl;
			}
			else
			{
				cout << "成功删除元素" << j << endl;
			}
		}

		cout << "删除元素后，L=";
		list.ListTraverse(mprint<int>);
		list.ClearList();
		cout << "清空表L后，表L的长度=" << list.ListLength() << endl;
	}
}

#endif