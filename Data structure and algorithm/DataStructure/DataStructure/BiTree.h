#pragma once
#ifndef _BITREE_H_
#define _BITREE_H_
#include "C.h"
#include "BiTNode.h"
#include "helper.h"

enum class Tags : int {Left, Right};  // ö�����ͱ�־λ��StackElemʹ��
enum class style : int {Pre, In, Post};  // ö�����ͱ�����ʽ��OrderTraverse()ʹ��

template<typename T>
struct StackElem
{
	BiTNode<T>* p;  // ָ�����������ָ��
	Tags flag;  // ��־λ
};

template<typename T>
class BiTree
{
protected:
	BiTNode<T>* root;
private:
	void DestroyTree(BiTNode<T>*& t)
	{
		if (t != nullptr)
		{
			DestroyTree(t->lchild);  // �ݹ�����������
			DestroyTree(t->rchild);  // �ݹ�����������
			delete t;
			t = nullptr;
		}
	}
public:
	BiTree()
	{
		root = nullptr;
	}

	~BiTree()
	{
		DestroyTree(root);
	}

	void CreateBiTreeFromFile(ifstream& f)
	{
		T e;
		InputFromFile(f, e);
		if (e == nullptr)
		{
			return;
		}
		root = new BiTNode<T>;  // ���ɸ��ڵ�
		assert(root != nullptr);
		root->data = e;
		BiTree<T> left, right;  // ���������������
		left.CreateBiTreeFromFile(f);  // �ݹ鴴��������
		right.CreateBiTreeFromFile(f);  // �ݹ鴴��������
		root->lchild = left.root;  // ���������ӽ��������ĸ��ڵ�
		left.root = nullptr;  // ������Ϊ����
		root->rchild = right.root;
		right.root = nullptr;
	}

	bool BiTreeEmpty() const
	{
		return root == nullptr;
	}

	int BiTreeDepth(BiTNode<T>* t) const
	{
		if (t == nullptr)
		{
			return 0;
		}

		int i, j;
		i = BiTreeDepth(t->lchild);  // ���������
		j = BiTreeDepth(t->rchild);  // ���������
		return i > j ? i + 1 : j + 1;  // t�����Ϊ����������������������+1
	}

	// ǰ��ݹ����
	void PreOrderRecursiveTraverse(void(*visit)(const T& e), BiTNode<T>* p) const
	{
		if (p == nullptr)
		{
			return;
		}
		visit(p->data);
		PreOrderRecursiveTraverse(visit, p->lchild);
		PreOrderRecursiveTraverse(visit, p->rchild);
	}

	// ǰ��ǵݹ飨����ջ������������
	void PreOrderTraverse(void(*visit)(const T& e)) const
	{
		stack<BiTNode<T>*> s;
		BiTNode<T>* t = root;
		s.push(nullptr);  // ѹ��һ����ָ����Ϊ��־
		while (t != nullptr)
		{
			visit(root->data);
			if (t->rchild != nullptr)
			{
				s.push(t->rchild);
			}
			if (t->lchild != nullptr)
			{
				s.push(t->lchild);
			}
			else  // ����ָ��Ϊ��
			{
				t = s.top();  // ���ջ��Ԫ��
				s.pop();  // ���ջ��Ԫ��
			}
		}
	}

	// ����ݹ����
	void InOrderRecursiveTraverse(void(*visit)(const T& e), BiTNode<T>* p) const
	{
		if (p == nullptr)
		{
			return;
		}
		InOrderRecursiveTraverse(visit, p->lchild);
		visit(p->data);
		InOrderRecursiveTraverse(visit, p->rchild);
	}

	// ����ǵݹ飨����ջ������
	void InOrderTraverse(void(*visit)(const T& e)) const
	{
		stack<BiTNode<T>*> s;
		BiTNode<T>* t = root;
		while (t != nullptr && !s.empty())
		{
			if (t != nullptr)  // ��ָ���ջ������������
			{
				s.push(t);
				t = t->lchild;
			}
			else
			{
				t = s.top();
				s.pop();
				visit(t->data);
				t = t->rchild;
			}
		}
		cout << endl;
	}

	// �����ݹ����
	void PostOrderRecursiveTraverse(void(*visit)(const T& e), BiTNode<T>* p) const
	{
		if (p == nullptr)
		{
			return;
		}
		PostOrderRecursiveTraverse(visit, p->lchild);
		PostOrderRecursiveTraverse(visit, p->rchild);
		visit(p->data);
	}

	// �����ǵݹ����
	void PostOrderTraverse(void(*visit)(const T& e)) const
	{
		StackElem<T> se;
		stack<StackElem<T>> s;
		BiTNode<T>* t = root;
		if (t == nullptr)
		{
			return;
		}

		while (!s.empty() || t != nullptr)
		{
			while (t != nullptr)
			{
				se.p = t;
				se.flag = Tags::Left;
				s.push(se);
				t = t->lchild;
			}
			se = s.top();
			s.pop();
			t = se.p;
			if (se.flag == Tags::Left)
			{
				se.flag = Tags::Right;
				s.push(se);
				t = t->rchild;
			}
			else
			{
				visit(t->data);
				t = nullptr;
			}
		}
	}

	// �������
	void LevelOrderTraverse(void(*visit)(const T& e)) const
	{
		queue<BiTNode<T>*> q;
		BiTNode<T>* t = root, *a;
		if (t != nullptr)  // ������
		{
			q.push(t);  // ��ָ�����
			while (!q.empty())
			{
				a = q.front();
				q.pop();  // ���Ӷ�ͷԪ��
				visit(a->data);
				if (a->lchild != nullptr)
				{
					q.push(a->lchild);
				}
				if (a->rchild != nullptr)
				{
					q.push(a->rchild);
				}
			}
		}
		cout << endl;
	}

	// ����mode��ֵ������������ߺ�������
	void OrderTraverse(BiTNode<T>* t, style mode, void(*visit)(const T& e)) const
	{
		if (t != nullptr)
		{
			if (mode == style::Pre)
			{
				visit(t->data);
			}
			OrderTraverse(t->lchild, mode, visit);
			if (mode == style::In)
			{
				visit(t->data);
			}
			OrderTraverse(t->rchild, mode, visit);
			if (mode == style::Post)
			{
				visit(t->data);
			}
		}
	}

	BiTNode<T>* Root()
	{
		return root;
	}

	bool InsertChild(BiTNode<T>*& p, bool LR, BiTree<T>& c)
	{
		BiTNode<T>* q = c.Root();
		c.root = nullptr;
		if (p != nullptr)
		{
			if (!LR)
			{
				q->rchild = p->lchild;
				p->lchild = q;
			}
			else
			{
				q->rchild = p->rchild;
				p->rchild = q;
			}
			return true;
		}
		return false;
	}

	bool Delete(BiTNode<T>*& p, bool LR)
	{
		if (p != nullptr)
		{
			if (!LR)
			{
				DestroyTree(p->lchild);
			}
			else
			{
				DestroyTree(p->rchild);
			}
			return true;
		}
		return false;
	}

	T Value(BiTNode<T>* p) const
	{
		return p->data;
	}

	void Assign(BiTNode<T>* p, T value) const
	{
		p->data = value;
	}

	BiTNode<T>* Parent(BiTNode<T>* p) const
	{
		queue<BiTNode<T>*> q;
		BiTNode<T>* a;
	}
};

#endif