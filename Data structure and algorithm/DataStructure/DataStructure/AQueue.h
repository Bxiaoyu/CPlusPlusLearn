#pragma once
#ifndef _AQUEUE_H_
#define _AQUEUE_H_

template<typename T>
class AQueue
{
public:
	// 清空队列
	void ClearQueue();
	// 队列是否为空
	bool QueueEmpty() const;
	// 队列的长度
	int QueueLength() const;
	// 返回队头元素
	bool GetHead(T& e) const;
	// 插入队尾元素
	bool EnQueue(T e);
	// 删除队头元素
	bool DeQueue(T& e);
	// 遍历打印
	void QueueTraverse(void(*visit)(T*)) const;
};

#endif