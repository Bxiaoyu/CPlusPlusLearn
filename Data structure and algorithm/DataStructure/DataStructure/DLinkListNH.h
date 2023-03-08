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
			if (i == 1)  // �ڵ�һ�����ǰ����
			{
				if (head == nullptr)  // ���
				{
					s->prior = s->next = s;
				}
				else  // ���գ����ڱ�ͷ
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
				if (p == nullptr)  // ��i-1����㲻����
				{
					return false;
				}
				else  // ��i-1�������ڣ���s�������
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
			if (head == nullptr)  // �ձ�
			{
				head = s;
				s->prior = s->next = s;
			}
			else
			{
				p = GetElemP(i);  // ʹpָ���i�����
				if (p != nullptr)  // ��i��������
				{
					s->prior = p->prior;
					s->next = p;
					p->prior->next = s;
					p->prior = s;
				}
				else  // ���ڱ�β
				{
					s->next = head;
					s->prior = head->prior;
					head->prior->next = s;
					head->prior = s;
				}
				if (i == 1)  // ���ڱ�ͷ
				{
					head = s;  // ʹheadָ���µ���Ԫ���
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
			if (p->next == p)  // ����ֻ��һ��Ԫ�أ��ҽ���ɾ��
			{
				head = nullptr;
			}
			else
			{
				p->next->prior = p->prior;
				p->prior->next = p->next;
				if (p == head)  // ɾ�����ǵ�һ�����
				{
					head = p->next;  // ͷָ��ָ��ԭ�ڶ������
				}
			}
			delete p;
			return true;
		}

		void ListDelete(DLNode<T>* p)
		{
			if (ListLength() == 1)  // ���н���һ��Ԫ��
			{
				head = nullptr;
			}
			else
			{
				if (p == head)  // ��ɾ���������Ԫ��㣬�����в�ֹһ��Ԫ��
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

	// ����
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
		cout << "��L�ı�β���β���1-5��L=";
		list.ListTraverse(mprint<int>);
		cout << "��=" << list.ListLength() << endl;
		for (j = 0; j <= 3; j++)
		{
			i = list.ListDelete(j, e);
			if (i == false)
			{
				cout << "ɾ����" << j << "��Ԫ��ʧ�ܣ������ڴ�Ԫ�أ�" << endl;
			}
			else
			{
				cout << "�ɹ�ɾ����" << j << "��Ԫ��" << endl;
			}
		}
		cout << "ɾ��3��Ԫ�غ�L=";
		list.ListTraverse(mprint<int>);
		list.ClearList();
		cout << "��ձ�L�󣬱�L�ĳ���=" << list.ListLength() << endl;
	}
}

#endif