#pragma once
#ifndef _LINKLISTNH_H_
#define _LINKLISTNH_H_
#include "C.h"
#include "helper.h"

using namespace std;

namespace NPLinkListNH
{
	/*!
	 * @brief ���������ͽṹ��
	 * @tparam T ��������
	*/
	template<typename T>
	struct LNode
	{
		T data;
		LNode<T>* next;
	};

	/*!
	 * @brief ����ͷ���ĵ������ࣨ���ڲ����ɾ��Ԫ��������ͬ���ڱ���ϻ����һЩ�鷳��
	 * @tparam T ��������
	*/
	template<typename T>
	class LinkListNH
	{
	private:
		LNode<T>* head;  // ͷָ��
	public:
		LinkListNH()
		{
			head = nullptr;  // ָ��Ϊ��
		}

		~LinkListNH()
		{
			ClearList();
		}

		void ClearList()
		{
			LNode<T>*p;
			while (head != nullptr)  // ��Ϊ�ձ�
			{
				p = head;  // pָ���һ�����
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
		 * @brief ���ұ��е�һ����e����eq()��ϵ�Ľ�㣬�ҵ��򷵻�ָ��ý���ָ��
		 * @param e Ŀ��Ԫ��
		 * @param eq �ȽϺ���ָ��
		 * @param p ָ��������������ǰ��
		 * @return ʧ�ܷ���nullptr
		*/
		LNode<T>* Point(T e, bool(*eq)(T, T), LNode<T>*& p) const
		{
			if (head)  // ����
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
			if (i < 1)  // iֵ���Ϸ�
			{
				return false;
			}
			s = new LNode<T>;
			if (s == nullptr)
			{
				return false;
			}
			s->data = e;
			if (i == 1)  // ���ڱ�ͷ
			{
				s->next = head;
				head = s;
			}
			else
			{
				while (p != nullptr && j < i-1)  // Ѱ�ҵ�i-1�����
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
			q = Point(e, eq, p);  // pָ���ɾ������ǰ��
			if (q == nullptr)  // û�ҵ���ɾ�����
			{
				return false;
			}
			else
			{
				if (p == nullptr)  // ��ɾ������ǵ�һ�����
				{
					head = q->next;  // ɾ�����
				}
				else
				{
					p->next = q->next;  // ɾ�����
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

	// ����
	void test_func()
	{
		LinkListNH<int> list;
		bool i;
		int j, k;
		for (j = 1; j <= 5; ++j)
		{
			list.ListInsert(j, j);
		}
		cout << "�ڱ�β���β���1-5��L=";
		list.ListTraverse(mprint<int>);
		cout << "��=" << list.ListLength() << endl;

		for (j = 6; j >= 5; --j)
		{
			k = list.LocateElem(j, equal);
			if (k)
			{
				cout << "ֵΪ" << j << "��Ԫ���Ǳ�L�ĵ�" << k << "��Ԫ�أ�";
			}
			else
			{
				cout << "û��ֵΪ" << j << "��Ԫ�أ�";
			}
			i = list.ListDelete(j, equal);
			if (i == false)
			{
				cout << "ɾ��Ԫ��" << j << "ʧ�ܣ������ڴ�Ԫ�أ�" << endl;
			}
			else
			{
				cout << "�ɹ�ɾ��Ԫ��" << j << endl;
			}
		}

		cout << "ɾ��Ԫ�غ�L=";
		list.ListTraverse(mprint<int>);
		list.ClearList();
		cout << "��ձ�L�󣬱�L�ĳ���=" << list.ListLength() << endl;
	}
}

#endif