#pragma once
#ifndef _AQUEUE_H_
#define _AQUEUE_H_

template<typename T>
class AQueue
{
public:
	// ��ն���
	void ClearQueue();
	// �����Ƿ�Ϊ��
	bool QueueEmpty() const;
	// ���еĳ���
	int QueueLength() const;
	// ���ض�ͷԪ��
	bool GetHead(T& e) const;
	// �����βԪ��
	bool EnQueue(T e);
	// ɾ����ͷԪ��
	bool DeQueue(T& e);
	// ������ӡ
	void QueueTraverse(void(*visit)(T*)) const;
};

#endif