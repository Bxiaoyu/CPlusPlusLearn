#pragma once
#ifndef _SQLIST_H_
#define _SQLIST_H_
#include "AList.h"
#include "C.h"

namespace NPSqList
{
	// ˳�����
	template<typename T>
	class SqList : public AList<T>
	{
		// ������ͨ����MergeList()ΪSqList����Ԫ
		template<typename T>
		friend void MergeList(const SqList<T>&, const SqList<T>&, SqList<T>&);
	private:
		T* elem;      // ���Ա�洢�ռ��ַ
		int length;   // ���Ա�ǰ����
		int listsize; // ���Ա�ǰ�洢����

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
		 * @brief �������Ա�Ϊ��
		*/
		void ClearList()
		{
			length = 0;
		}

		/*!
		 * @brief ���Ա��Ƿ�Ϊ��
		 * @return �շ���true���ǿշ���false
		*/
		bool ListEmpty() const
		{
			return length == 0;
		}

		/*!
		 * @brief ��ȡ���Ա�ǰԪ������
		 * @return ���ص�ǰԪ�ظ���
		*/
		int ListLength() const
		{
			return length;
		}

		/*!
		 * @brief ��ȡ���Ա�ǰ����
		 * @return �������Ա�ǰ����
		*/
		int ListSize() const
		{
			return listsize;
		}

		/*!
		 * @brief ��ȡ��i��Ԫ��
		 * @param i λ��
		 * @param e ������ֵ
		 * @return �ɹ�����true��ʧ�ܷ���false
		*/
		bool GetElem(int i, T& e) const
		{
			// 1 <= i <= length
			if (i < 1 || i > length)
			{
				return false;
			}

			e = *(elem + i - 1);  // ����i��Ԫ�ص�ֵ����e
			return true;
		}

		/*!
		 * @brief ��ȡԪ��e��λ���±꣩
		 * @param e Ŀ��Ԫ��
		 * @param eq ����ָ��
		 * @return �ɹ�����λ��ʧ�ܷ���0
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
		 * @brief Ѱ��Ԫ��e��ǰ�����
		 * @param e Ŀ��Ԫ��
		 * @param eq ����ָ��
		 * @param pre_e ������ֵ
		 * @return �ɹ�����true��ʧ�ܷ���false
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
				pre_e = *(elem + i - 2);  // ��iָʾ��ǰһ��Ԫ�ص�ֵ����pre_e
				return true;
			}
		}

		/*!
		 * @brief Ѱ��Ԫ��e�ĺ�̽��
		 * @param e Ŀ��Ԫ��
		 * @param eq ����ָ��
		 * @param next_e �����ص�ֵ
		 * @return �ɹ�����true��ʧ�ܷ���false
		*/
		bool NextElem(T e, bool(*eq)(T, T), T& next_e) const
		{
			int i = LocateElem(e, eq);
			if (i == 0 || i == length)  // δ�ҵ��������һ��Ԫ��
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
		 * @brief �ڵ�i��λ��Ǯ����Ԫ��e
		 * @param i λ��
		 * @param e ������ֵ
		 * @return �ɹ�����true��ʧ�ܷ���false
		*/
		bool ListInsert(int i, T e)
		{
			T* newBase, * q, * p;
			if (i < 1 || i > length + 1)
			{
				return false;
			}

			if (length == listsize)  // ��ǰ�洢�ռ�����
			{
				newBase = new T[2 * listsize];  // �¿ռ�Ϊԭ�ռ��2��
				assert(newBase != nullptr);

				for (int j = 0; j < length; ++j)
				{
					*(newBase + j) = *(elem + j);  // ��ԭ��ռ�����ݸ��Ƶ��µĿռ�
				}

				delete[] elem;   // �ͷ�ԭ��ռ�
				elem = newBase;  // �»�ַ����elem
				listsize *= 2;   // ���´洢����
			}

			q = elem + i - 1;  // qΪ����λ��
			for (p = elem + length - 1; p >= q; --p)
			{
				*(p + 1) = *p;
			}
			*q = e;
			++length;
			return true;
		}

		/*!
		 * @brief ɾ����i��Ԫ�أ�����e����
		 * @param i Ԫ��λ��
		 * @param e ������ֵ
		 * @return �ɹ�����true�����򷵻�false
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
			q = elem + length - 1;  // qΪ��βԪ�ص�λ��
			for (++p; p <= q; ++p)
			{
				*(p - 1) = *p;
			}
			length--;
			return true;
		}

		void ListTraverse(void(*visit) (T*)) const;  // ������ӡ���
	};

	/*!
	 * @brief ��ӡ���
	 * @tparam T ��������
	 * @param visit ����ָ��
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
	 * @brief �ϲ��������Ա�
	 * @tparam T ��������
	 * @param la ���Ա�1
	 * @param lb ���Ա�2
	 * @param lc �ϲ��ɵ������Ա�
	*/
	template<typename T>
	void MergeList(const SqList<T>& la, const SqList<T>& lb, SqList<T>& lc)
	{
		// ��֪���Ա�la��lb��Ԫ�ذ�ֵ�ǵݼ�����
		// �鲢la��lb�õ��µ����Ա�lc, lc��Ԫ��Ҳ��ֵ�ǵݼ����У����ı��la��lb��
		T* pa, * pa_last, * pb, * pb_last, * pc;
		assert(lc.ListSize() >= (la.ListLength() + lb.ListLength()));  // �ж�lc�Ĵ洢�ռ��Ƿ񹻹��鲢�±�
		pa = la.elem;
		pb = lb.elem;
		pc = lc.elem;
		pa_last = la.elem + la.length - 1;
		pb_last = lb.elem + lb.length - 1;

		while (pa <= pa_last && pb <= pb_last)  // ��la��lb����Ԫ��δ�鲢
		{
			if (*pa <= *pb)  // ��la�ĵ�ǰԪ�ز����ڱ�lb�ĵ�ǰԪ��
			{
				*pc++ = *pa++;  // ��pa��ָ��Ԫ��ֵ����pc��ָ��Ԫ��,pa��pc�ֱ�+1��ָ����һ����Ԫ��
			}
			else
			{
				*pc++ = *pb++;
			}
		}

		while (pa <= pa_last)
		{
			*pc++ = *pa++;  // ����laʣ��Ԫ��
		}

		while (pb <= pb_last)
		{
			*pc++ = *pb++;  // ����lbʣ��Ԫ��
		}

		lc.length = la.length + lb.length;  // lc�ı�
	}

	// ����
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