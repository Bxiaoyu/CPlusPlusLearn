#pragma once
#ifndef _BITNODE_H_
#define _BITNODE_H_

template<typename T>
struct BiTNode
{
	T data;  // �����������
	BiTNode<T>* lchild, * rchild;  // ���Һ���ָ��
};

#endif