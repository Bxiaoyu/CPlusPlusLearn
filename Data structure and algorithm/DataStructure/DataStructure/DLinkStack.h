#pragma once
#ifndef _DLINKSTACK_H_
#define _DLINKSTACK_H_
#include "AStack.h"
#include "DLinkList.h"


namespace NPDLinkStack
{
	/*!
	 * @brief ��˫��ѭ������ʵ����ʽջ
	 * @tparam T ��������
	*/
	template<typename T>
	class DLinkStack : public AStack<T>, public NPDLinkList::DLinkList<T>
	{
	public:
		void ClearStack() const
		{
			NPDLinkList::DLinkList<T>::ClearList();
		}

		bool StackEmpty() const
		{
			return NPDLinkList::DLinkList<T>::ListEmpty();
		}

		int StackLength() const
		{
			return NPDLinkList::DLinkList<T>::ListLength();
		}

		bool GetTop(T& e) const
		{
			return NPDLinkList::DLinkList<T>::GetElem(1, e);
		}

		bool Push(T e)
		{
			return NPDLinkList::DLinkList<T>::ListInsert(1, e);
		}

		bool Pop(T& e) const
		{
			return NPDLinkList::DLinkList<T>::ListDelete(1, e);
		}

		void StackTraverse(void(*visit)(T*)) const
		{
			NPDLinkList::DLinkList<T>::ListBackTraverse(visit);
		}
	};

	// ����
	void test_func()
	{
		int j;
		DLinkStack<int> s;
		int e;
		for (j = 1; j <= 5; ++j)
		{
			s.Push(j);
		}
		cout << "ջ��Ԫ����ջ�׵�ջ������Ϊ��";
		s.StackTraverse(mprint<int>);
		s.Pop(e);
		cout << "������ջ��Ԫ��e=" << e;
		cout << "��ջ�շ�" << boolalpha << s.StackEmpty() << endl;
		s.GetTop(e);
		cout << "�µ�ջ��Ԫ��e=" << e << "��ջ�ĳ���Ϊ" << s.StackLength() << endl;
		s.ClearStack();
		cout << "���ջ��ջ�Ƿ�Ϊ�գ�" << boolalpha << s.StackEmpty() << endl;
	}
}

#endif