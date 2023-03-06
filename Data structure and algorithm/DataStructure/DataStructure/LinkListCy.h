#pragma once
#ifndef _LINKLISTCY_H
#define _LINKLISTCY_H

#include "C.h"
#include "AList.h"
#include "helper.h"

namespace NPLinkListCy
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
	 * @brief ��ѭ�������࣬����βָ�루����ͷ�������һ����㶼�ܷ��㣩
	 * @tparam T
	*/
	template<typename T>
	class LinkListCy : public AList<T>
	{
		template<typename T>
		friend void mergeList(LinkListCy<T>&, LinkListCy<T>&);

	private:
		LNode<T>* tail;  // ��β

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
			tail = tail->next;  // tailָ��ͷ���
			p = tail->next;  // pָ���һ�����
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
			LNode<T>* p = tail->next;  // pָ��ͷ���
			while (p != tail)
			{
				i++;
				p = p->next;
			}

			return i;
		}

		bool GetElem(int i, T& e) const
		{
			LNode<T>* p = tail->next->next;  // pָ���һ�����
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
			LNode<T>* p = tail->next->next;  // pָ���һ�����
			while (p != tail->next)  // pûָ��ͷ���
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
			LNode<T>* q, * p = tail->next->next;  // pָ���һ�����
			q = p->next;  // qָ��p�ĺ��
			while (q != tail->next)  // qûָ��ͷ���
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
			if (p == tail)  // ���ڱ�β
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
			if (tail == q)  // ɾ�����Ǳ�βԪ��
			{
				tail = p;
			}
			delete q;
			return true;
		}

		void ListTraverse(void(*visit) (T*)) const
		{
			LNode<T>* p = tail->next->next;  // ָ���һ�����
			while (p != tail->next)  // p��ָ��ͷ���
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
		LNode<T>* p = lb.tail->next;  // ��lb�ϲ���la�ı�β����laָʾ�±�lb�ɿձ�
		lb.tail->next = la.tail->next;  // lb��βָ��ָ��la��ͷ���
		la.tail->next = p->next;  // la��β����next��ָ��lb�ĵ�һ�����
		la.tail = lb.tail;  // lb��β����Ϊla��β���
		lb.tail = p;
		lb.tail->next = lb.tail;  // lb��Ϊ��
	}

	// ����
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