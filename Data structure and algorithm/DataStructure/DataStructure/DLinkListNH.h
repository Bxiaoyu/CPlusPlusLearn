#pragma once
#ifndef _DLINKLISTNH_H_
#define _DLINKLISTNH_H_
#include "C.h"
#include "helper.h"

using namespace std;

namespace NPDLinkListNH
{
	/*!
	* @brief 双向结点类型结构体
	* @tparam T 数据类型
	*/
	template<typename T>
	struct DLNode
	{
		T data;
		DLNode<T>* prior, * next;
	};

	/*!
	 * @brief 不设头结点的双向链表类
	 * @tparam T 数据类型
	*/
	template<typename T>
	class DLinkListNH
	{
		friend void Joseph(int, int);
		friend class BoundaryLogo;
		friend class BuddySystem;
	private:
		DLNode<T>* head;
	private:
		/*!
		 * @brief 在双向链表中返回第i个结点的地址
		 * @param i 位序
		 * @return 若第i个结点不存在，返回nullptr
		*/
		DLNode<T>* GetElemP(int i) const
		{
			int j = 1;
			DLNode<T>* p = head;
			if (i <= 0 || head == nullptr)
			{
				return nullptr;
			}
			if (i == 1)  // 第一个结点
			{
				return p;
			}

			do 
			{
				p = p->next;
				j++;
			} while (p != head && j < i);
			if (p == head)
			{
				return nullptr;
			}
			else
			{
				return p;
			}
		}

	public:
		/*!
		 * @brief 构造一个空的双向循环
		*/
		DLinkListNH()
		{
			head = nullptr;
		}

		~DLinkListNH()
		{
			ClearList();
		}

		void ClearList()
		{
			DLNode<T>* p = head;
			if (head != nullptr)
			{
				head->prior->next = nullptr;  // 打开循环链表为单链表
				while (p != nullptr)
				{
					p = p->next;
					delete head;
					head = p;
				}
			}
		}

		int ListLength() const
		{
			int i = 0;
			DLNode<T>* p = head;
			if (head != nullptr)  // 表不为空
			{
				do 
				{
					i++;
					p = p->next;
				} while (p != head);  // p没指向第一个结点
			}
			return i;
		}

		bool ListInsert(int i, T e)
		{
			DLNode<T>* s, * p = GetElemP(i-1);
			s = new DLNode<T>;
			if (s == nullptr)
			{
				return false;
			}
			s->data = e;
			if (i == 1)  // 在第一个结点前插入
			{
				if (head == nullptr)  // 表空
				{
					s->prior = s->next = s;
				}
				else  // 表不空，插在表头
				{
					s->prior = head->prior;
					s->next = head;
					s->prior->next = s;
					s->next->prior = s;
				}
				head = s;
				return true;
			}
			else  // i > 1
			{
				if (p == nullptr)  // 第i-1个结点不存在
				{
					return false;
				}
				else  // 第i-1个结点存在，将s插在其后
				{
					s->next = p->next;
					s->next->prior = s;
					s->prior = p;
					p->next = s;
					return true;
				}
			}
		}

		void ListInsert(int i, DLNode<T>* s)
		{
			DLNode<T>* p;
			assert(i >= 1 || i <= ListLength() + 1);
			if (head == nullptr)  // 空表
			{
				head = s;
				s->prior = s->next = s;
			}
			else
			{
				p = GetElemP(i);  // 使p指向第i个结点
				if (p != nullptr)  // 第i个结点存在
				{
					s->prior = p->prior;
					s->next = p;
					p->prior->next = s;
					p->prior = s;
				}
				else  // 插在表尾
				{
					s->next = head;
					s->prior = head->prior;
					head->prior->next = s;
					head->prior = s;
				}
				if (i == 1)  // 插在表头
				{
					head = s;  // 使head指向新的首元结点
				}
			}
		}

		bool ListDelete(int i, T& e)
		{
			DLNode<T>* p = GetElemP(i);
			if (p == nullptr)
			{
				return false;
			}
			e = p->data;
			if (p->next == p)  // 表中只有一个元素，且将被删除
			{
				head = nullptr;
			}
			else
			{
				p->next->prior = p->prior;
				p->prior->next = p->next;
				if (p == head)  // 删除的是第一个结点
				{
					head = p->next;  // 头指针指向原第二个结点
				}
			}
			delete p;
			return true;
		}

		void ListDelete(DLNode<T>* p)
		{
			if (ListLength() == 1)  // 表中仅有一个元素
			{
				head = nullptr;
			}
			else
			{
				if (p == head)  // 待删除结点是首元结点，但表中不止一个元素
				{
					head = p->next;
				}
				p->prior->next = p->next;
				p->next->prior = p->prior;
			}
		}

		void ListTraverse(void(*visit)(T*)) const
		{
			DLNode<T>* p = head;
			if (head != nullptr)
			{
				do 
				{
					visit(&p->data);
					p = p->next;
				} while (p != head);
			}
			cout << endl;
		}
	};

	// 测试
	void test_func()
	{
		DLinkListNH<int> list;
		bool i;
		int j;
		int e;
		for (j = 1; j <= 5; j++)
		{
			list.ListInsert(j, j);
		}
		cout << "在L的表尾依次插入1-5后，L=";
		list.ListTraverse(mprint<int>);
		cout << "表长=" << list.ListLength() << endl;
		for (j = 0; j <= 3; j++)
		{
			i = list.ListDelete(j, e);
			if (i == false)
			{
				cout << "删除第" << j << "个元素失败（不存在此元素）" << endl;
			}
			else
			{
				cout << "成功删除第" << j << "个元素" << endl;
			}
		}
		cout << "删除3个元素后，L=";
		list.ListTraverse(mprint<int>);
		list.ClearList();
		cout << "清空表L后，表L的长度=" << list.ListLength() << endl;
	}
}

#endif