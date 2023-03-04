#pragma once
#ifndef _LINKLIST_H
#define _LINKLIST_H
#include "C.h"
#include "AList.h"
#include "helper.h"

namespace NPLinkList
{
	/*!
	 * @brief �����������ͽṹ��
	 * @tparam T ��������
	*/
	template<typename T>
	struct LNode
	{
		T data;  // �����������
		LNode<T>* next;  // ���ָ��
	};

	/*!
	 * @brief ��ͷ���ĵ�������
	 * @tparam T ��������
	*/
	template<typename T>
	class LinkList : public AList<T>
	{
		template<typename T>
		friend void mergeList(LinkList<T>&, LinkList<T>&);

	protected:
		LNode<T>* head = nullptr;  // ͷָ��
		int length = 0;  // ��ǰԪ�ظ���
	public:
		LinkList()
		{
			head = new LNode<T>;  // ����ͷ���
			assert(head != nullptr);
			head->next = nullptr;  // ͷ����ָ����Ϊ��
		}

		~LinkList()
		{
			ClearList();
			delete head;
		}

		void ClearList()
		{
			LNode<T>* p = head->next, *q;  // pָ���һ�����
			head->next = nullptr;  // ͷ���ָ����Ϊ��

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

			while (p->next != nullptr && j < i - 1)  // Ѱ�ҵ�i����㣬��ʹpָ����ǰ��
			{
				j++;
				p = p->next;
			}

			if (j > i - 1 || p->next == nullptr)  // ɾ��λ�ò�����
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
	 * @brief �ϲ�������������
	 * @tparam T ��������
	 * @param  la ����1
	 * @param  lb ����2
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

		p->next = pa ? pa : pb;  // ����ʣ���
		lb.head->next = nullptr;  // lb��Ϊ��
	}

	// ����
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
		std::cout << "��L��ͷ���β���1-5��L=";
		list.ListTraverse(mprint<T>);
		cout << "L�Ƿ�Ϊ�գ�" << boolalpha << list.ListEmpty() << "����L�ĳ���=";
		cout << list.ListLength();
		cout << "����L�ĳ���=";
		cout << list.ListLength2() << endl;

		for (j = 0; j <= 1; j++)
		{
			k = list.LocateElem(j, equal);
			if (k)
			{
				cout << "ֵΪ" << j << "��Ԫ���ǵ�" << k << "��Ԫ��" << endl;
			}
			else
			{
				cout << "û��ֵΪ" << j << "��Ԫ�أ�";
			}
		}

		for (j = 1; j <= 2; j++)
		{
			list.GetElem(j, e0);
			i = list.PriorElem(e0, equal, e);
			if (i)
			{
				cout << "Ԫ��" << e0 << "��ǰ��Ϊ" << e << endl;
			}
			else
			{
				cout << "Ԫ��" << e0 << "��ǰ����";
			}
		}

		for (j = list.ListLength(); j >= list.ListLength() - 1; j--)
		{
			list.GetElem(j, e0);
			i = list.NextElem(e0, equal, e);
			if (i)
			{
				cout << "Ԫ��" << e0 << "�ĺ��Ϊ" << e << endl;
			}
			else
			{
				cout << "Ԫ��" << e0 << "�޺�̣�";
			}
		}

		k = list.ListLength2();
		for (j = k+1; j >= k; j--)
		{
			i = list.ListDelete(j, e);
			if (i)
			{
				cout << "ɾ����" << j << "��Ԫ�سɹ�����ֵΪ" << e << endl;
			}
			else
			{
				cout << "ɾ����" << j << "��Ԫ��ʧ�ܣ������ڴ�Ԫ�أ���";
			}
		}

		cout << "ɾ��Ԫ�غ��L�ĳ���=" << list.ListLength() << "����L�ĳ���=" << list.ListLength2() << endl;
		list.ClearList();
		cout << "��ձ�L��L�Ƿ�Ϊ�գ�" << boolalpha << list.ListEmpty() << "����L�ĳ���=" << list.ListLength() << "����L�ĳ���=" <<
			list.ListLength2() << endl;

		cout << endl;
		merge_test();
	}
}

#endif