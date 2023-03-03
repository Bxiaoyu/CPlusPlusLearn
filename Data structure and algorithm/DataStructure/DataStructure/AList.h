#pragma once
#ifndef _ALIST_H_
#define _ALIST_H_

// ���Ա������Ķ���
template<typename T>
class AList
{
public:
	// �������Ա�Ϊ��
	void ClearList();
	// �ж����Ա��Ƿ�Ϊ��
	bool ListEmpty() const;
	// ���ص�һ����e����eq��ϵ����������Ԫ��λ����������������Ԫ���򷵻�0
	int LocateElem(T e, bool(*eq)(T, T)) const;
	// ����Ԫ��e��ǰ��
	bool PriorElem(T e, bool(*eq)(T, T), T& pre_e) const;
	// ����Ԫ��e�ĺ��
	bool NextElem(T e, bool(*eq)(T, T), T& next_e) const;
	// ɾ�����Ա�ĵ�i��Ԫ��
	bool ListDelete(int i, T& e);
	// ���ζ�ÿ��Ԫ�ص���visit��������
	void ListTraverse(void(*visit) (T*)) const;
	// ��ȡ��i��Ԫ�ص�ֵ
	virtual bool GetElem(int i, T& e) const = 0;
	// �����Ա�ĵ�i��λ��֮ǰ�����µ�Ԫ��e
	virtual bool ListInsert(int i, T e) = 0;
	// �������Ա�ĳ���
	virtual int ListLength() const = 0;
};

#endif