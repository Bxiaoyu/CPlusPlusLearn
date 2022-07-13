#pragma once
/*
*	二叉搜索树
*/
#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

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

		Node(Node* node)
		{
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
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
		destroy(root);
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

	// 前序遍历
	void preOrder()
	{
		preOrder(root);
	}

	// 中序遍历
	void inOrder()
	{
		inOrder(root);
	}

	// 后续遍历
	void postOrder()
	{
		postOrder(root);
	}

	// 层序遍历
	void levelOrder()
	{
		queue<Node*> q;
		q.push(root);

		while (!q.empty())
		{
			Node* node = q.front();
			q.pop();
			cout << node->key << endl;

			if (node->left != nullptr)
			{
				q.push(node->left);
			}
			if (node->right != nullptr)
			{
				q.push(node->right);
			}
		}
	}

	// 寻找最小的键值
	Key minimun()
	{
		assert(count != 0);
		Node* minNode = minimun(root);
		return minNode->key;
	}

	// 寻找最大的键值
	Key maximum(Node* node)
	{
		assert(count != 0);
		Node* maxNode = maximum(root);
		return maxNode->key;
	}

	// 从二叉树中删除最小值所在节点
	// 最小值只可能在左子树，且没有左孩子；最小节点的右孩子有两种情况，存在右孩子和不存在右孩子
	// 不存在右孩子的话直接删除即可；存在右孩子的话用右孩子替代最小节点即可
	void removeMin()
	{
		if (root != nullptr)
		{
			root = removeMin(root);
		}
	}

	// 从二叉搜索树中删除最大值所在节点
	// 最大值只可能在右子树，且没有右孩子；最大节点的左孩子有两种情况，存在左孩子和不存在左孩子
	// 不存在左孩子的话直接删除即可；存在左孩子的话用左孩子代替最大节点即可
	void removeMax()
	{
		if (root != nullptr)
		{
			root = removeMax(root);
		}
	}

	// 从二叉搜索树中删除键值为key的节点
	// 难点在于要删除的节点左右孩子都存在，操作如下:
	// 例如要删除节点为d，找到节点d的右子树的最小值节点s（s=min(d->right)），s是d的后继，用s代替d；
	// 或者找到节点d的左子树的最大值节点s（s=max(d->left)），s是d的后继，用s代替d，两种方法都行
	void remove(Key key)
	{
		root = remove(root, key);
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

	// 对以node为根的二叉搜索树进行前序遍历
	void preOrder(Node* node)
	{
		if (node != nullptr)
		{
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}

	// 对以node为根的二叉搜索树进行中序遍历
	void inOrder(Node* node)
	{
		if (node != nullptr)
		{
			inOrder(node->left);
			cout << node->key << endl;
			inOrder(node->right);
		}
	}

	// 对以node为根的二叉搜索树进行后续遍历
	void postOrder(Node* node)
	{
		if (node != nullptr)
		{
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << endl;
		}
	}

	// 释放二叉搜索树
	void destroy(Node* node)
	{
		if (node != nullptr)
		{
			destroy(node->left);
			destroy(node->right);
			
			delete node;
			cout--;
		}
	}

	// 在以node为根的二叉搜索树中，返回最小键值的节点
	Node* minimun(Node* node)
	{
		if (node->left == nullptr)
		{
			return node;
		}

		return minimun(node->left);
	}

	// 在以node为根的二叉搜索树中，返回最大键值的节点
	Node* maximum(Node* node)
	{
		if (node->right == nullptr)
		{
			return node;
		}

		return maximum(node->right);
	}

	// 删除掉以node为根的二叉搜索树中的最小节点
	// 返回删除节点后新的二分搜索树的根
	Node* removeMin(Node* node)
	{
		if (node->left == nullptr)
		{
			Node* rightNode = node->right;
			delete node;
			count--;
			return rightNode;
		}

		node->left = removeMin(node->left);
		return node;
	}

	// 删除掉以node为根的二叉搜索树中的最大节点
	// 返回删除节点后新的二分搜索树的根
	Node* removeMax(Node* node)
	{
		if (node->right == nullptr)
		{
			Node* leftNode = node->left;
			delete node;
			count--;
			return leftNode;
		}

		node->right = removeMax(node->right);
		return node;
	}

	// 删除以node为根的二叉搜索树中键值为key的节点
	// 返回删除节点后新的二分搜索树的根
	Node* remove(Node* node, Key key)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		if (key < node->key)
		{
			node->left = remove(node->left, key);
			return node;
		}
		else if (key > node->key)
		{
			node->right = remove(node->right, key);
			return node;
		}
		else  // key == node->key
		{
			if (node->left == nullptr)
			{
				Node* rightNode = node->right;
				delete node;
				count--;
				return rightNode;
			}

			if (node->right == nullptr)
			{
				Node* leftNode = node->left;
				delete node;
				count--;
				return leftNode;
			}

			// node->left != nullptr && node->right != nullptr
			Node* successor = new Node(minimun(node->right));  // 找到节点node的右子树的最小值
			count++;

			successor->right = removeMin(node->right);  // 删除节点node的右子树的最小值节点，并将其返回值代替node
			successor->left = node->left;

			delete node;
			count--;

			return successor;
		}
	}
};