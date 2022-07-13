#pragma once
/*
*	二叉搜索树
*/
#include <iostream>

template<class Key, class Value>
class BST
{
private:
	struct Node
	{
		Key key;
		Value value;
		Node* left;
		Node* right;

		Node(Key key, Value value)
		{
			this->key = key;
			this->value = value;
			this->left = this->right = nullptr;
		}
	};

	Node* root;
	int count;

public:
	BST()
	{
		root = nullptr;
		count = 0;
	}

	~BST()
	{
		// To do
	}

	int size() const
	{
		return count;
	}

	bool isEmpty()
	{
		return count == 0;
	}

	// 插入数据，递归插入
	void insert(Key key, Value value)
	{
		root = insert(root, key, value);
	}

	// 非递归方式插入数据
	void insert_nonrecursive(Key key, Value value)
	{
		if (root == nullptr)
		{
			root = new Node(key, value);
			count++;
			return;
		}

		Node* cur = root;
		while (true)
		{
			if (key < cur->key)
			{
				if (cur->left == nullptr)
				{
					cur->left = new Node(key, value);
					count++;
					return;
				}
				else
				{
					cur = cur->left;
				}
			}
			else if (key > cur->key)
			{
				if (cur->right == nullptr)
				{
					cur->right = new Node(key, value);
					count++;
					return;
				}
				else
				{
					cur = cur->right;
				}
			}
			else  // key == cur->key
			{
				cur->value = value;
				return;
			}
		}
	}

	bool contain(Key key)
	{
		return contain(root, key);
	}

	Value* search(Key key)
	{
		return search(root, key);
	}

private:
	// 递归方式插入新数据(key, value)
	// 返回插入新节点后的二叉搜索树的根
	Node* insert(Node* node, Key key, Value value)
	{
		if (node == nullptr)  // 递归结束条件
		{
			count++;
			return new Node(key, value);
		}

		if (key == node->key)  // 如果key相同，则根据规则直接更新value即可
		{
			node->value = value;
		}
		else if (key < node->key)
		{
			node->left = insert(node->left, key, value);
		}
		else  // key > node->key
		{
			node->right = insert(node->right, key, value);
		}
		
		return node;
	}

	// 查看以node为根的二叉搜索树中是否包含键值为key的节点
	bool contain(Node* node, Key key)
	{
		if (node == nullptr)
		{
			return false;
		}

		if (key == node->key)
		{
			return true;
		}
		else if (key < node->key)
		{
			return contain(node->left, key);
		}
		else // key > node->key
		{
			return contain(node->right, key);
		}
	}

	// 在以node为根的二叉搜索树中查找key所对应的value
	Value* search(Node* node, Key key)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		if (key == node->key)
		{
			return &(node->value);
		}
		else if(key < node->key)
		{
			return search(node->left, key);
		}
		else // key > node->key
		{
			return search(node->right, key);
		}
	}
};