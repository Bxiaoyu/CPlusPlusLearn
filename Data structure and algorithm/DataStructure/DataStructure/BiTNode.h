#pragma once
#ifndef _BITNODE_H_
#define _BITNODE_H_

template<typename T>
struct BiTNode
{
	T data;  // 结点数据类型
	BiTNode<T>* lchild, * rchild;  // 左右孩子指针
};

#endif