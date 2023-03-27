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

	}
};

#endif