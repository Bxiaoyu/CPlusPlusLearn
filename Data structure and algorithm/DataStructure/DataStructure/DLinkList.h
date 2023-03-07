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

			do 
			{
				p = p->next;
				j++;
			} while (j < i && p != head);  // pû���ص�ͷ����һ�û����i�����

			if (p == head)  // ������
			{
				return nullptr;
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

		bool ListInsert(int i, T e)
		{
			DLNode<T>* p = GetElemP(i-1), *s;
			if (p == nullptr)  // ��i������ǰ��������
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

	// ����
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
		cout << "�ڱ�β���β���1-5��l=";
		list.ListTraverse(mprint<int>);
		j = list.GetElem(2, e);
		if (j)
		{
			cout << "����ĵڶ���Ԫ��ֵΪ" << e << endl;
		}
		else
		{
			cout << "�����ڵ�2��Ԫ��" << endl;
		}
		i = list.LocateElem(n, equal);
		if (i)
		{
			cout << "����" << n << "��Ԫ���ǵ�" << i << "��" << endl;
		}
		else
		{
			cout << "û�е���" << n << "��Ԫ��" << endl;
		}
		j = list.PriorElem(n, equal, e);
		if (j)
		{
			cout << n << "��ǰ����" << e << endl;
		}
		else
		{
			cout << "������" << n << "��ǰ��" << endl;
		}
		j = list.NextElem(n, equal, e);
		if (j)
		{
			cout << n << "�ĺ����" << e << endl;
		}
		else
		{
			cout << "������" << n << "�ĺ��" << endl;
		}

		list.ListDelete(2, e);
		cout << "ɾ����2����㣬ֵΪ" << e << "��������������㣺";
		list.ListBackTraverse(mprint<int>);
		cout << "�����Ԫ�ظ���Ϊ" << list.ListLength() << "��";
		cout << "�����Ƿ�Ϊ�գ�" << boolalpha << list.ListEmpty() << endl;
		list.ClearList();
		cout << "��պ������Ƿ�Ϊ�գ�" << boolalpha << list.ListEmpty() << endl;
	}
}

#endif