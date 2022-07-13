#pragma once
/*
*	����������
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

	// �������ݣ��ݹ����
	void insert(Key key, Value value)
	{
		root = insert(root, key, value);
	}

	// �ǵݹ鷽ʽ��������
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
	// �ݹ鷽ʽ����������(key, value)
	// ���ز����½ڵ��Ķ����������ĸ�
	Node* insert(Node* node, Key key, Value value)
	{
		if (node == nullptr)  // �ݹ��������
		{
			count++;
			return new Node(key, value);
		}

		if (key == node->key)  // ���key��ͬ������ݹ���ֱ�Ӹ���value����
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

	// �鿴��nodeΪ���Ķ������������Ƿ������ֵΪkey�Ľڵ�
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

	// ����nodeΪ���Ķ����������в���key����Ӧ��value
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