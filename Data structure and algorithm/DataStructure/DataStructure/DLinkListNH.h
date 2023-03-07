#pragma once
#ifndef _DLINKLISTNH_H_
#define _DLINKLISTNH_H_
#include "C.h"
#include "helper.h"

using namespace std;

namespace NPDLinkListNH
{
	/*!
	* @brief ˫�������ͽṹ��
	* @tparam T ��������
	*/
	template<typename T>
	struct DLNode
	{
		T data;
		DLNode<T>* prior, * next;
	};

	/*!
	 * @brief ����ͷ����˫��������
	 * @tparam T ��������
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
		 * @brief ��˫�������з��ص�i�����ĵ�ַ
		 * @param i λ��
		 * @return ����i����㲻���ڣ�����nullptr
		*/
		DLNode<T>* GetElemP(int i) const
		{
			int j = 1;
			DLNode<T>* p = head;
			if (i <= 0 || head == nullptr)
			{
				return nullptr;
			}
			if (i == 1)  // ��һ�����
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
		 * @brief ����һ���յ�˫��ѭ��
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
				head->prior->next = nullptr;  // ��ѭ������Ϊ������
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
			if (head != nullptr)  // ��Ϊ��
			{
				do 
				{
					i++;
					p = p->next;
				} while (p != head);  // pûָ���һ�����
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