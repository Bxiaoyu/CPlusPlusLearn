#pragma once
#ifndef _MUARRAY_H_
#define _MUARRAY_H_
#include "C.h"


template<typename T>
class MuArray
{
private:
	T* base;         // ����Ԫ�ػ�ַ���ɹ��캯������
	int dim;         // ����ά��
	int* bounds;     // ����ά���ַ���ɹ��캯������
	int* constants;  // ����ӳ����������ַ���ɹ��캯������

private:
	// ��apָʾ�ĸ��±�ֵ�Ϸ����������Ԫ����base�е���Ե�ַoff
	bool Locate(va_list ap, int& off) const
	{
		int i, ind;
		off = 0;
		for (i = 0; i < dim; ++i)
		{
			ind = va_arg(ap, int);  // ��һ��ȡ��ά�ȵ��±�ֵ
			if (ind < 0 || ind >= bounds[i])
			{
				return false;
			}
			off += constants[i] * ind;  // ��Ե�ַ=��ά���±�ֵ*��ά��ƫ����֮��
		}
		return true;
	}

public:
	MuArray(int Dim, ...)
	{
		int elemtotal = 1;
		va_list ap;
		assert(Dim > 0);
		dim = Dim;
		bounds = new int[dim];
		assert(bounds != nullptr);
		va_start(ap, Dim);
		for (int i = 0; i < Dim; ++i)
		{
			bounds[i] = va_arg(ap, int);
			assert(bounds[i] > 0);
			elemtotal *= bounds[i];
		}
		va_end(ap);
		base = new T[elemtotal];
		assert(base != nullptr);
		constants = new int[dim];
		assert(constants != nullptr);
		constants[dim - 1] = 1;
		for (int i = Dim - 2; i >= 0; --i)
		{
			constants[i] = bounds[i + 1] * constants[i + 1];
		}
	}

	~MuArray()
	{
		delete[] base;
		delete[] bounds;
		delete[] constants;
	}

	bool Value(T& e, int n, ...) const
	{
		va_list ap;
		int off;
		va_start(ap, n);
		if (Locate(ap, off) == false)
		{
			return false;
		}
		e = *(base + off);
		return true;
	}

	bool Assign(T e, ...) const
	{
		va_list ap;
		int off;
		va_start(ap, e);
		if (Locate(ap, off) == false)
		{
			return false;
		}
		*(base + off) = e;
		return true;
	}
};

namespace NPMuArray
{
	void test_func()
	{
		int i, j, k, dim = 3, bound1 = 3, bound2 = 4, bound3 = 2;
		int e;
		MuArray<int> A(dim, bound1, bound2, bound3);
		cout << bound1 << "ҳ" << bound2 << "��" << bound3 << "�о���Ԫ�����£�\n";
		for (i = 0; i < bound1; ++i)
		{
			for (j = 0; j < bound2; ++j)
			{
				for (k = 0; k < bound3; ++k)
				{
					A.Assign(i * 100 + j * 10 + k, i, j, k);
					A.Value(e, dim, i, j, k);
					cout << "A[" << i << "][" << j << "][" << k << "]=" << setw(3) << e << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
	}
}

#endif