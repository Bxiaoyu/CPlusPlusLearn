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
			if (i == 1)
			{
			}
		}
	};
}

#endif