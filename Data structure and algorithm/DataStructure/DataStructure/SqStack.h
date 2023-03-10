#pragma once
#ifndef _SQSTACK_H_
#define _SQSTACK_H_
#include "AStack.h"
#include "C.h"
#include "helper.h"

namespace NPSQSTACK
{
	template<typename T>
	class SqStack : public AStack<T>
	{
	private:
		T* base;  // ջ�洢�ռ��ַ
		T* top;   // ջ��ָ��
		int stackSize;  // ջ��ǰ�Ĵ洢����
	public:
		SqStack(int k=1)
		{
			base = new T[k];
			assert(base != nullptr);
			top = base;  // ջ��ָ��ջ�ף���ջ��
			stackSize = k;  // ��ʼ�洢����
		}

		~SqStack()
		{
			delete[] base;
		}

		void ClearStack()
		{
			top = base;  // ջ��ָ��ָ��ջ��
		}

		bool StackEmpty() const
		{
			return top == base;
		}

		int StackLength() const
		{
			return top - base;
		}

		bool GetTop(T& e) const
		{
			if (top > base)  // ջ����
			{
				e = *(top - 1);  // ��ջ��Ԫ�ظ���e
				return true;
			}
			else
			{
				return false;
			}
		}

		bool Push(T e)
		{
			T* newBase;
			if ((top-base) == stackSize)  // ջ��
			{
				newBase = new T[stackSize * 2];  // �¿ռ�Ϊԭ����2��
				if (newBase == nullptr)
				{
					return false;
				}
				for (int j = 0; j < top-base; ++j)  // ��ԭջ�ռ�����ݸ��Ƶ��¿ռ�
				{
					*(newBase + j) = *(base + j);
				}
				delete[] base;  // �ͷ�ԭջ�ռ�
				base = newBase;  // �»�ַ����base
				top = base + stackSize;  // �޸�ջ��ָ��
				stackSize *= 2;
			}
			*top++ = e;  // ��e��ջ
			return true;
		}

		bool Pop(T& e)
		{
			if (top == base)  // ջ��
			{
				return false;
			}
			e = *--top;  // ջ��ָ������һ����Ԫ��ջ��Ԫ�ظ���e
			return true;
		}

		void StackTraverse(void(*visit)(T*)) const
		{
			T* p = base;
			while (p < top)
			{
				visit(p++);
			}
			cout << endl;
		}
	};

	// ����
	void test_func()
	{
		int j;
		SqStack<int> s(3);
		int e;
		for (j = 1; j <= 5; ++j)
		{
			s.Push(j);
		}
		cout << "ջ��Ԫ����ջ�׵�ջ������Ϊ��";
		s.StackTraverse(mprint<int>);
		s.Pop(e);
		cout << "������ջ��Ԫ��Ϊ��" << e;
		cout << "��ջ�շ�" << boolalpha << s.StackEmpty() << endl;
		s.GetTop(e);
		cout << "�µ�ջ��Ԫ��e=" << e << "��ջ�ĳ���Ϊ��" << s.StackLength() << endl;
		s.ClearStack();
		cout << "���ջ��ջ�Ƿ�Ϊ�գ�" << boolalpha << s.StackEmpty() << endl;
	}
}

#endif