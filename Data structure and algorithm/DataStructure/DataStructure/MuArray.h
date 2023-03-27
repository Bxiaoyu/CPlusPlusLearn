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

	}
};

#endif