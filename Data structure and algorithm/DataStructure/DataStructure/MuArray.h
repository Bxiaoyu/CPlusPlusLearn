#pragma once
#ifndef _MUARRAY_H_
#define _MUARRAY_H_
#include "C.h"


template<typename T>
class MuArray
{
private:
	T* base;         // 数组元素基址，由构造函数分配
	int dim;         // 数组维数
	int* bounds;     // 数组维界基址，由构造函数分配
	int* constants;  // 数组映像函数常量基址，由构造函数分配

private:
	// 若ap指示的各下标值合法，则求出该元素在base中的相对地址off
	bool Locate(va_list ap, int& off) const
	{
		int i, ind;
		off = 0;
		for (i = 0; i < dim; ++i)
		{
			ind = va_arg(ap, int);  // 逐一读取各维度的下标值
			if (ind < 0 || ind >= bounds[i])
			{
				return false;
			}
			off += constants[i] * ind;  // 相对地址=各维的下标值*本维的偏移量之和
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
		cout << bound1 << "页" << bound2 << "行" << bound3 << "列矩阵元素如下：\n";
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