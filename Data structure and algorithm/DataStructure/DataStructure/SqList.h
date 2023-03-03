#pragma once
#ifndef _SQLIST_H_
#define _SQLIST_H_
#include "AList.h"
#include "C.h"

namespace NPSqList
{
	// 顺序表类
	template<typename T>
	class SqList : public AList<T>
	{
		// 声明普通函数MergeList()为SqList的友元
		template<typename T>
		friend void MergeList(const SqList<T>&, const SqList<T>&, SqList<T>&);
	private:
		T* elem;      // 线性表存储空间基址
		int length;   // 线性表当前长度
		int listsize; // 线性表当前存储容量

	public:
		SqList(int k = 1)
		{
			elem = new T[k];
			assert(elem != nullptr);
			length = 0;
			listsize = k;
		}

		~SqList()
		{
			delete[] elem;
		}

		/*!
		 * @brief 重置线性表为空
		*/
		void ClearList()
		{
			length = 0;
		}

		/*!
		 * @brief 线性表是否为空
		 * @return 空返回true，非空返回false
		*/
		bool ListEmpty() const
		{
			return length == 0;
		}

		/*!
		 * @brief 获取线性表当前元素数量
		 * @return 返回当前元素个数
		*/
		int ListLength() const
		{
			return length;
		}

		/*!
		 * @brief 获取线性表当前容量
		 * @return 返回线性表当前容量
		*/
		int ListSize() const
		{
			return listsize;
		}

		/*!
		 * @brief 获取第i个元素
		 * @param i 位序
		 * @param e 待返回值
		 * @return 成功返回true，失败返回false
		*/
		bool GetElem(int i, T& e) const
		{
			// 1 <= i <= length
			if (i < 1 || i > length)
			{
				return false;
			}

			e = *(elem + i - 1);  // 将第i个元素的值赋给e
			return true;
		}

		/*!
		 * @brief 获取元素e的位序（下标）
		 * @param e 目标元素
		 * @param eq 函数指针
		 * @return 成功返回位序，失败返回0
		*/
		int LocateElem(T e, bool(*eq)(T, T)) const
		{
			int i = 1;
			while (i <= length && !eq(e, *(elem + i - 1)))
			{
				i++;
			}

			if (i <= length)
			{
				return i;
			}
			else
			{
				return 0;
			}
		}

		/*!
		 * @brief 寻找元素e的前驱结点
		 * @param e 目标元素
		 * @param eq 函数指针
		 * @param pre_e 待返回值
		 * @return 成功返回true，失败返回false
		*/
		bool PriorElem(T e, bool(*eq)(T, T), T& pre_e) const
		{
			int i = LocateElem(e, eq);
			if (i <= 1)
			{
				return false;
			}
			else
			{
				pre_e = *(elem + i - 2);  // 将i指示的前一个元素的值赋给pre_e
				return true;
			}
		}

		/*!
		 * @brief 寻找元素e的后继结点
		 * @param e 目标元素
		 * @param eq 函数指针
		 * @param next_e 待返回的值
		 * @return 成功返回true，失败返回false
		*/
		bool NextElem(T e, bool(*eq)(T, T), T& next_e) const
		{
			int i = LocateElem(e, eq);
			if (i == 0 || i == length)  // 未找到或是最后一个元素
			{
				return false;
			}
			else
			{
				next_e = *(elem + i);
				return true;
			}
		}

		/*!
		 * @brief 在第i个位置钱插入元素e
		 * @param i 位序
		 * @param e 待插入值
		 * @return 成功返回true，失败返回false
		*/
		bool ListInsert(int i, T e)
		{
			T* newBase, * q, * p;
			if (i < 1 || i > length + 1)
			{
				return false;
			}

			if (length == listsize)  // 当前存储空间已满
			{
				newBase = new T[2 * listsize];  // 新空间为原空间的2倍
				assert(newBase != nullptr);

				for (int j = 0; j < length; ++j)
				{
					*(newBase + j) = *(elem + j);  // 将原表空间的数据复制到新的空间
				}

				delete[] elem;   // 释放原表空间
				elem = newBase;  // 新基址赋给elem
				listsize *= 2;   // 更新存储容量
			}

			q = elem + i - 1;  // q为插入位置
			for (p = elem + length - 1; p >= q; --p)
			{
				*(p + 1) = *p;
			}
			*q = e;
			++length;
			return true;
		}

		/*!
		 * @brief 删除第i个元素，并用e返回
		 * @param i 元素位序
		 * @param e 待返回值
		 * @return 成功返回true，否则返回false
		*/
		bool ListDelete(int i, T& e)
		{
			T* p, * q;
			if (i < 1 || i > length)
			{
				return false;
			}

			p = elem + i - 1;
			e = *p;
			q = elem + length - 1;  // q为表尾元素的位置
			for (++p; p <= q; ++p)
			{
				*(p - 1) = *p;
			}
			length--;
			return true;
		}

		void ListTraverse(void(*visit) (T*)) const;  // 遍历打印输出
	};

	/*!
	 * @brief 打印输出
	 * @tparam T 数据类型
	 * @param visit 函数指针
	*/
	template<typename T>
	void SqList<T>::ListTraverse(void(*visit) (T*)) const
	{
		for (int i = 0; i < length; ++i)
		{
			visit(elem + i);
		}
		std::cout << "\n";
	}

	/*!
	 * @brief 合并两个线性表
	 * @tparam T 参数类型
	 * @param la 线性表1
	 * @param lb 线性表2
	 * @param lc 合并成的新线性表
	*/
	template<typename T>
	void MergeList(const SqList<T>& la, const SqList<T>& lb, SqList<T>& lc)
	{
		// 已知线性表la和lb的元素按值非递减排列
		// 归并la和lb得到新的线性表lc, lc的元素也按值非递减排列（不改变表la和lb）
		T* pa, * pa_last, * pb, * pb_last, * pc;
		assert(lc.ListSize() >= (la.ListLength() + lb.ListLength()));  // 判断lc的存储空间是否够够归并新表
		pa = la.elem;
		pb = lb.elem;
		pc = lc.elem;
		pa_last = la.elem + la.length - 1;
		pb_last = lb.elem + lb.length - 1;

		while (pa <= pa_last && pb <= pb_last)  // 表la和lb均有元素未归并
		{
			if (*pa <= *pb)  // 表la的当前元素不大于表lb的当前元素
			{
				*pc++ = *pa++;  // 将pa所指单元的值赋给pc所指单元后,pa和pc分别+1（指向下一个单元）
			}
			else
			{
				*pc++ = *pb++;
			}
		}

		while (pa <= pa_last)
		{
			*pc++ = *pa++;  // 插入la剩余元素
		}

		while (pb <= pb_last)
		{
			*pc++ = *pb++;  // 插入lb剩余元素
		}

		lc.length = la.length + lb.length;  // lc的表长
	}

	// 测试
	template<typename T>
	void print(T* val)
	{
		std::cout << *val << " ";
	}

	void test_func()
	{
		SqList<int> la(5), lb(3), lc(8);
		for (int i = 1; i <= 5; ++i)
		{
			la.ListInsert(i, i);
		}
		std::cout << "la: ";
		la.ListTraverse(print);
		std::cout << "\n";

		for (int i = 1; i <= 3; ++i)
		{
			lb.ListInsert(i, 2 * i);
		}
		std::cout << "lb: ";
		lb.ListTraverse(print);
		std::cout << "\n";

		MergeList<int>(la, lb, lc);
		std::cout << "lc: ";
		lc.ListTraverse(print);
		std::cout << endl;
	}
}

#endif