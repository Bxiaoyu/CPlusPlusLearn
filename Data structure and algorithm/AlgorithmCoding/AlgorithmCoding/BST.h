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
	Key maximum()
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

	// 寻找key的floor值，递归算法
	// 如果不存在key的floor值（key比BST中的最小值还小），返回nullptr
	Key* floor(Key key)
	{
		if (count == 0 || key < minimun())
		{
			return nullptr;
		}

		Node* floorNode = floor(root, key);
		return &(floorNode->key);
	}

	// 寻找key的ceil值，递归算法
	// 如果不存在key的ceil值（key比BST中的最大值还大），返回nullptr
	Key* ceil(Key key)
	{
		if (count == 0 || key > maximum())
		{
			return nullptr;
		}

		Node* ceilNode = ceil(root, key);
		return &(ceilNode->key);
	}

	// 查找key的前驱
	// 如果不存在key的前驱(key不存在, 或者key是整棵二叉树中的最小值), 则返回NULL
	Key* predecessor(Key key)
	{
		Node* node = search(root, key);
		// 如果key所在的节点不存在，则key没有前驱，返回null
		if (node == nullptr)
		{
			return nullptr;
		}

		// 如果key所在的节点左子树不为空,则其左子树的最大值为key的前驱
		if (node->left != nullptr)
		{
			return &(maximum(node->left)->key);
		}

		// 否则, key的前驱在从根节点到key的路径上, 在这个路径上寻找到比key小的最大值, 即为key的前驱
		Node* preNode = predecessorFromAncestor(root, key);
		return preNode == nullptr ? nullptr : &(preNode->key);
	}

	// 查找key的后继, 递归算法
	// 如果不存在key的后继(key不存在, 或者key是整棵二叉树中的最大值), 则返回NULL
	Key* successor(Key key)
	{
		Node* node = search(root, key);
		// 如果key所在的节点不存在, 则key没有前驱, 返回NULL
		if (node == nullptr)
		{
			return nullptr;
		}

		// 如果key所在的节点右子树不为空,则其右子树的最小值为key的后继
		if (node->right != nullptr)
		{
			return &(minimun(node->right)->key);
		}

		// 否则, key的后继在从根节点到key的路径上, 在这个路径上寻找到比key大的最小值, 即为key的后继
		Node* sucNode = successorFromAncestor(root, key);
		return sucNode == nullptr ? nullptr : &(sucNode->key);
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
			count--;
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

	// 在以node为根的二叉搜索树中, 寻找key的floor值所处的节点, 递归算法
	Node* floor(Node* node, Key key)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		// 如果node的key值和要寻找的key值相等
		// 则node本身就是key的floor节点
		if (node->key == key)
		{
			return node;
		}

		// 如果node的key值比要寻找的key值大
		// 则要寻找的key的floor节点一定在node的左子树中
		if (node->key > key)
		{
			return floor(node->left, key);
		}

		// 如果node->key < key
		// 则node有可能是key的floor节点, 也有可能不是(存在比node->key大但是小于key的其余节点)
		// 需要尝试向node的右子树寻找一下
		Node* tempNode = floor(node->right, key);
		if (tempNode != nullptr)
		{
			return tempNode;
		}

		return node;
	}

	// 在以node为根的二叉搜索树中, 寻找key的ceil值所处的节点, 递归算法
	Node* ceil(Node* node, Key key)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		// 如果node的key值和要寻找的key值相等
		// 则node本身就是key的ceil节点
		if (node->key == key)
		{
			return node;
		}

		// 如果node的key值比要寻找的key值小
		// 则要寻找的key的ceil节点一定在node的右子树中
		if (node->key < key)
		{
			return ceil(node->right, key);
		}

		// 如果node->key > key
		// 则node有可能是key的ceil节点, 也有可能不是(存在比node->key小但是大于key的其余节点)
		// 需要尝试向node的左子树寻找一下
		Node* tempNode = ceil(node->left, key);
		if (tempNode == nullptr)
		{
			return tempNode;
		}

		return node;
	}

	// 在以node为根的二叉搜索树中, 寻找key的祖先中,比key小的最大值所在节点, 递归算法
	// 算法调用前已保证key存在在以node为根的二叉树中
	Node* predecessorFromAncestor(Node* node, Key key)
	{
		if (node->key == key)
		{
			return nullptr;
		}

		if (key < node->key)
		{
			// 如果当前节点大于key, 则当前节点不可能是比key小的最大值
			// 向下搜索到的结果直接返回
			return predecessorFromAncestor(node->left, key);
		}
		else
		{
			assert(key > node->key);
			// 如果当前节点小于key, 则当前节点有可能是比key小的最大值
			// 向右继续搜索, 将结果存储到tempNode中
			Node* tempNode = predecessorFromAncestor(node->right, key);
			if (tempNode)
			{
				return tempNode;
			}
			else
			{
				// 如果tempNode为空, 则当前节点即为结果
				return node;
			}
		}
	}

	// 在以node为根的二叉搜索树中, 寻找key的祖先中,比key大的最小值所在节点, 递归算法
	// 算法调用前已保证key存在在以node为根的二叉树中
	Node* successorFromAncestor(Node* node, Key key)
	{
		if (node->key == key)
		{
			return nullptr;
		}

		if (key > node->key)
		{
			// 如果当前节点小于key, 则当前节点不可能是比key大的最小值
			// 向下搜索到的结果直接返回
			return successorFromAncestor(node->right, key);
		}
		else
		{
			assert(key < node->key);
			// 如果当前节点大于key, 则当前节点有可能是比key大的最小值
			// 向左继续搜索, 将结果存储到tempNode中
			Node* tempNode = predecessorFromAncestor(node->left, key);
			if (tempNode)
			{
				return tempNode;
			}
			else
			{
				// 如果tempNode为空, 则当前节点即为结果
				return node;
			}
		}
	}
};