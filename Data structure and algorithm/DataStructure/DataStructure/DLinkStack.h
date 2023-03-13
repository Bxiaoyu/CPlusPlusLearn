#pragma once
#ifndef _DLINKSTACK_H_
#define _DLINKSTACK_H_
#include "AStack.h"
#include "DLinkList.h"


namespace NPDLinkStack
{
	/*!
	 * @brief 用双向循环链表实现链式栈
	 * @tparam T 数据类型
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

	// 测试
	void test_func()
	{
		int j;
		DLinkStack<int> s;
		int e;
		for (j = 1; j <= 5; ++j)
		{
			s.Push(j);
		}
		cout << "栈中元素由栈底到栈顶依次为：";
		s.StackTraverse(mprint<int>);
		s.Pop(e);
		cout << "弹出的栈顶元素e=" << e;
		cout << "。栈空否？" << boolalpha << s.StackEmpty() << endl;
		s.GetTop(e);
		cout << "新的栈顶元素e=" << e << "，栈的长度为" << s.StackLength() << endl;
		s.ClearStack();
		cout << "清空栈后，栈是否为空？" << boolalpha << s.StackEmpty() << endl;
	}
}

#endif