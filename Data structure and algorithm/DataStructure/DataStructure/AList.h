#pragma once
#ifndef _ALIST_H_
#define _ALIST_H_

// 线性表抽象类的定义
template<typename T>
class AList
{
public:
	// 重置线性表为空
	void ClearList();
	// 判断线性表是否为空
	bool ListEmpty() const;
	// 返回第一个与e满足eq关系（）的数据元素位序，若不存在这样的元素则返回0
	int LocateElem(T e, bool(*eq)(T, T)) const;
	// 返回元素e的前驱
	bool PriorElem(T e, bool(*eq)(T, T), T& pre_e) const;
	// 返回元素e的后继
	bool NextElem(T e, bool(*eq)(T, T), T& next_e) const;
	// 删除线性表的第i个元素
	bool ListDelete(int i, T& e);
	// 依次对每个元素调用visit（）函数
	void ListTraverse(void(*visit) (T*)) const;
	// 获取第i个元素的值
	virtual bool GetElem(int i, T& e) const = 0;
	// 在线性表的第i个位置之前插入新的元素e
	virtual bool ListInsert(int i, T e) = 0;
	// 返回线性表的长度
	virtual int ListLength() const = 0;
};

#endif