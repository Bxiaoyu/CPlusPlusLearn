#pragma once
#ifndef _BITREE_H_
#define _BITREE_H_
#include "C.h"
#include "BiTNode.h"
#include "helper.h"

enum class Tags : int {Left, Right};  // 枚举类型标志位，StackElem使用
enum class style : int {Pre, In, Post};  // 枚举类型遍历方式，OrderTraverse()使用

template<typename T>
struct StackElem
{
	BiTNode<T>* p;  // 指向二叉树结点得指针
	Tags flag;  // 标志位
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
			DestroyTree(t->lchild);  // 递归销毁左子树
			DestroyTree(t->rchild);  // 递归销毁右子树
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
		root = new BiTNode<T>;  // 生成根节点
		assert(root != nullptr);
		root->data = e;
		BiTree<T> left, right;  // 左右两棵树类对象
		left.CreateBiTreeFromFile(f);  // 递归创建左子树
		right.CreateBiTreeFromFile(f);  // 递归创建右子树
		root->lchild = left.root;  // 根结点的左孩子接左子树的根节点
		left.root = nullptr;  // 左子树为空树
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
		i = BiTreeDepth(t->lchild);  // 左子树深度
		j = BiTreeDepth(t->rchild);  // 右子树深度
		return i > j ? i + 1 : j + 1;  // t的深度为其左右子树的深度中最大者+1
	}

	// 前序递归遍历
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

	// 前序非递归（利用栈）遍历二叉树
	void PreOrderTraverse(void(*visit)(const T& e)) const
	{
		stack<BiTNode<T>*> s;
		BiTNode<T>* t = root;
		s.push(nullptr);  // 压入一个空指针作为标志
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
			else  // 左孩子指针为空
			{
				t = s.top();  // 获得栈顶元素
				s.pop();  // 清除栈顶元素
			}
		}
	}

	// 中序递归遍历
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

	// 中序非递归（利用栈）遍历
	void InOrderTraverse(void(*visit)(const T& e)) const
	{
		stack<BiTNode<T>*> s;
		BiTNode<T>* t = root;
		while (t != nullptr && !s.empty())
		{
			if (t != nullptr)  // 根指针进栈，遍历左子树
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

	// 后续递归遍历
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

	// 后续非递归遍历
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

	// 层序遍历
	void LevelOrderTraverse(void(*visit)(const T& e)) const
	{
		queue<BiTNode<T>*> q;
		BiTNode<T>* t = root, *a;
		if (t != nullptr)  // 树不空
		{
			q.push(t);  // 根指针入队
			while (!q.empty())
			{
				a = q.front();
				q.pop();  // 出队队头元素
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

	// 根据mode的值，先序，中序或者后续遍历
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