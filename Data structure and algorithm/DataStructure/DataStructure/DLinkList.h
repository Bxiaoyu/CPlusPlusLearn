#pragma once
#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_
#include "AList.h"
#include "helper.h"

namespace NPDLinkList
{
	/*!
	 * @brief ˫�������ͽṹ��
	 * @tparam T ��������
	*/
	template<typename T>
	struct DLNode
	{
		T data;
		DLNode<T>* prior, * next;  // ǰ�����ָ��
	};

	template<typename T>
	class DLinkList : public AList<T>
	{
	private:
		DLNode<T>* head;  // ͷָ��

	private:
		/*!
		 * @brief ���ص�i�����ĵ�ַ
		 * @param i λ��
		 * @return iΪ0������ͷ����ַ���ɹ����ص�ַ��ʧ�ܷ���nullptr
		*/
		DLNode<T>* GetElemP(int i) const
		{
			int j = 0;
			DLNode<T>* p = head;  // pָ��ͷ���
			if (i < 0)  // ֵ�Ƿ�
			{
				return nullptr;
			}

			if (i == 0)
			{
				return p;  // ����ͷ���
			}

			while (j < i && p != head)
			{
				j++;
				p = p->next;
			}

			if (p == head)  // ������
			{
				return nullptr
			}
			else
			{
				return p;
			}
		}

		/*!
		 * @brief ���ص�һ����e���㶨���eq()��ȹ�ϵ������Ԫ�صĵ�ַ
		 * @param e Ŀ��Ԫ��
		 * @param eq �ȽϺ���
		 * @return ���ڷ��ص�ַ�������ڷ���nullptr
		*/
		DLNode<T>* GetElemE(T e, bool(*eq)(T, T)) const
		{
			DLNode<T>* p = head->next;  // pָ���һ�����
			while (p != head && !eq(e, p->data))
			{
				p = p->next;
			}

			if (p == head)  // ����e��Ԫ�ز�����
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
			DLNode<T>* p = head->next;  // pָ���һ�����
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
			if (p != nullptr && p->prior != head)  // pָ��ֵΪe�Ľ���Ҹý�㲻�ǵ�һ�����
			{
				pre_e = p->prior->data;
				return true;
			}
			return false;
		}

		bool NextElem(T e, bool(*eq)(T, T), T& next_e) const
		{
			DLNode<T>* p = GetElemE(e, eq);
			if (p != nullptr && p->next != head)  // pָ��ֵΪe�Ľ�㲢�Ҹý�㲻�����һ�����
			{
				next_e = p->next->data;
				return true;
			}
			return false;
		}
	};
}

#endif