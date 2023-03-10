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
		T* base;  // 栈存储空间基址
		T* top;   // 栈顶指针
		int stackSize;  // 栈当前的存储容量
	public:
		SqStack(int k=1)
		{
			base = new T[k];
			assert(base != nullptr);
			top = base;  // 栈顶指向栈底（空栈）
			stackSize = k;  // 初始存储容量
		}

		~SqStack()
		{
			delete[] base;
		}

		void ClearStack()
		{
			top = base;  // 栈顶指针指向栈底
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
			if (top > base)  // 栈不空
			{
				e = *(top - 1);  // 将栈顶元素赋给e
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
			if ((top-base) == stackSize)  // 栈满
			{
				newBase = new T[stackSize * 2];  // 新空间为原来的2倍
				if (newBase == nullptr)
				{
					return false;
				}
				for (int j = 0; j < top-base; ++j)  // 将原栈空间的数据复制到新空间
				{
					*(newBase + j) = *(base + j);
				}
				delete[] base;  // 释放原栈空间
				base = newBase;  // 新基址赋给base
				top = base + stackSize;  // 修改栈顶指针
				stackSize *= 2;
			}
			*top++ = e;  // 将e入栈
			return true;
		}

		bool Pop(T& e)
		{
			if (top == base)  // 栈空
			{
				return false;
			}
			e = *--top;  // 栈顶指针下移一个单元后将栈顶元素赋给e
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

	// 测试
	void test_func()
	{
		int j;
		SqStack<int> s(3);
		int e;
		for (j = 1; j <= 5; ++j)
		{
			s.Push(j);
		}
		cout << "栈中元素由栈底到栈顶依次为：";
		s.StackTraverse(mprint<int>);
		s.Pop(e);
		cout << "弹出的栈顶元素为：" << e;
		cout << "。栈空否？" << boolalpha << s.StackEmpty() << endl;
		s.GetTop(e);
		cout << "新的栈顶元素e=" << e << "，栈的长度为：" << s.StackLength() << endl;
		s.ClearStack();
		cout << "清空栈后，栈是否为空？" << boolalpha << s.StackEmpty() << endl;
	}
}

#endif