#pragma once
/*
*	����������
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

	// ǰ�����
	void preOrder()
	{
		preOrder(root);
	}

	// �������
	void inOrder()
	{
		inOrder(root);
	}

	// ��������
	void postOrder()
	{
		postOrder(root);
	}

	// �������
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

	// Ѱ����С�ļ�ֵ
	Key minimun()
	{
		assert(count != 0);
		Node* minNode = minimun(root);
		return minNode->key;
	}

	// Ѱ�����ļ�ֵ
	Key maximum()
	{
		assert(count != 0);
		Node* maxNode = maximum(root);
		return maxNode->key;
	}

	// �Ӷ�������ɾ����Сֵ���ڽڵ�
	// ��Сֵֻ����������������û�����ӣ���С�ڵ���Һ�������������������Һ��ӺͲ������Һ���
	// �������Һ��ӵĻ�ֱ��ɾ�����ɣ������Һ��ӵĻ����Һ��������С�ڵ㼴��
	void removeMin()
	{
		if (root != nullptr)
		{
			root = removeMin(root);
		}
	}

	// �Ӷ�����������ɾ�����ֵ���ڽڵ�
	// ���ֵֻ����������������û���Һ��ӣ����ڵ������������������������ӺͲ���������
	// ���������ӵĻ�ֱ��ɾ�����ɣ��������ӵĻ������Ӵ������ڵ㼴��
	void removeMax()
	{
		if (root != nullptr)
		{
			root = removeMax(root);
		}
	}

	// �Ӷ�����������ɾ����ֵΪkey�Ľڵ�
	// �ѵ�����Ҫɾ���Ľڵ����Һ��Ӷ����ڣ���������:
	// ����Ҫɾ���ڵ�Ϊd���ҵ��ڵ�d������������Сֵ�ڵ�s��s=min(d->right)����s��d�ĺ�̣���s����d��
	// �����ҵ��ڵ�d�������������ֵ�ڵ�s��s=max(d->left)����s��d�ĺ�̣���s����d�����ַ�������
	void remove(Key key)
	{
		root = remove(root, key);
	}

	// Ѱ��key��floorֵ���ݹ��㷨
	// ���������key��floorֵ��key��BST�е���Сֵ��С��������nullptr
	Key* floor(Key key)
	{
		if (count == 0 || key < minimun())
		{
			return nullptr;
		}

		Node* floorNode = floor(root, key);
		return &(floorNode->key);
	}

	// Ѱ��key��ceilֵ���ݹ��㷨
	// ���������key��ceilֵ��key��BST�е����ֵ���󣩣�����nullptr
	Key* ceil(Key key)
	{
		if (count == 0 || key > maximum())
		{
			return nullptr;
		}

		Node* ceilNode = ceil(root, key);
		return &(ceilNode->key);
	}

	// ����key��ǰ��
	// ���������key��ǰ��(key������, ����key�����ö������е���Сֵ), �򷵻�NULL
	Key* predecessor(Key key)
	{
		Node* node = search(root, key);
		// ���key���ڵĽڵ㲻���ڣ���keyû��ǰ��������null
		if (node == nullptr)
		{
			return nullptr;
		}

		// ���key���ڵĽڵ���������Ϊ��,���������������ֵΪkey��ǰ��
		if (node->left != nullptr)
		{
			return &(maximum(node->left)->key);
		}

		// ����, key��ǰ���ڴӸ��ڵ㵽key��·����, �����·����Ѱ�ҵ���keyС�����ֵ, ��Ϊkey��ǰ��
		Node* preNode = predecessorFromAncestor(root, key);
		return preNode == nullptr ? nullptr : &(preNode->key);
	}

	// ����key�ĺ��, �ݹ��㷨
	// ���������key�ĺ��(key������, ����key�����ö������е����ֵ), �򷵻�NULL
	Key* successor(Key key)
	{
		Node* node = search(root, key);
		// ���key���ڵĽڵ㲻����, ��keyû��ǰ��, ����NULL
		if (node == nullptr)
		{
			return nullptr;
		}

		// ���key���ڵĽڵ���������Ϊ��,��������������СֵΪkey�ĺ��
		if (node->right != nullptr)
		{
			return &(minimun(node->right)->key);
		}

		// ����, key�ĺ���ڴӸ��ڵ㵽key��·����, �����·����Ѱ�ҵ���key�����Сֵ, ��Ϊkey�ĺ��
		Node* sucNode = successorFromAncestor(root, key);
		return sucNode == nullptr ? nullptr : &(sucNode->key);
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

	// ����nodeΪ���Ķ�������������ǰ�����
	void preOrder(Node* node)
	{
		if (node != nullptr)
		{
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}

	// ����nodeΪ���Ķ��������������������
	void inOrder(Node* node)
	{
		if (node != nullptr)
		{
			inOrder(node->left);
			cout << node->key << endl;
			inOrder(node->right);
		}
	}

	// ����nodeΪ���Ķ������������к�������
	void postOrder(Node* node)
	{
		if (node != nullptr)
		{
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << endl;
		}
	}

	// �ͷŶ���������
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

	// ����nodeΪ���Ķ����������У�������С��ֵ�Ľڵ�
	Node* minimun(Node* node)
	{
		if (node->left == nullptr)
		{
			return node;
		}

		return minimun(node->left);
	}

	// ����nodeΪ���Ķ����������У���������ֵ�Ľڵ�
	Node* maximum(Node* node)
	{
		if (node->right == nullptr)
		{
			return node;
		}

		return maximum(node->right);
	}

	// ɾ������nodeΪ���Ķ����������е���С�ڵ�
	// ����ɾ���ڵ���µĶ����������ĸ�
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

	// ɾ������nodeΪ���Ķ����������е����ڵ�
	// ����ɾ���ڵ���µĶ����������ĸ�
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

	// ɾ����nodeΪ���Ķ����������м�ֵΪkey�Ľڵ�
	// ����ɾ���ڵ���µĶ����������ĸ�
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
			Node* successor = new Node(minimun(node->right));  // �ҵ��ڵ�node������������Сֵ
			count++;

			successor->right = removeMin(node->right);  // ɾ���ڵ�node������������Сֵ�ڵ㣬�����䷵��ֵ����node
			successor->left = node->left;

			delete node;
			count--;

			return successor;
		}
	}

	// ����nodeΪ���Ķ�����������, Ѱ��key��floorֵ�����Ľڵ�, �ݹ��㷨
	Node* floor(Node* node, Key key)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		// ���node��keyֵ��ҪѰ�ҵ�keyֵ���
		// ��node�������key��floor�ڵ�
		if (node->key == key)
		{
			return node;
		}

		// ���node��keyֵ��ҪѰ�ҵ�keyֵ��
		// ��ҪѰ�ҵ�key��floor�ڵ�һ����node����������
		if (node->key > key)
		{
			return floor(node->left, key);
		}

		// ���node->key < key
		// ��node�п�����key��floor�ڵ�, Ҳ�п��ܲ���(���ڱ�node->key����С��key������ڵ�)
		// ��Ҫ������node��������Ѱ��һ��
		Node* tempNode = floor(node->right, key);
		if (tempNode != nullptr)
		{
			return tempNode;
		}

		return node;
	}

	// ����nodeΪ���Ķ�����������, Ѱ��key��ceilֵ�����Ľڵ�, �ݹ��㷨
	Node* ceil(Node* node, Key key)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		// ���node��keyֵ��ҪѰ�ҵ�keyֵ���
		// ��node�������key��ceil�ڵ�
		if (node->key == key)
		{
			return node;
		}

		// ���node��keyֵ��ҪѰ�ҵ�keyֵС
		// ��ҪѰ�ҵ�key��ceil�ڵ�һ����node����������
		if (node->key < key)
		{
			return ceil(node->right, key);
		}

		// ���node->key > key
		// ��node�п�����key��ceil�ڵ�, Ҳ�п��ܲ���(���ڱ�node->keyС���Ǵ���key������ڵ�)
		// ��Ҫ������node��������Ѱ��һ��
		Node* tempNode = ceil(node->left, key);
		if (tempNode == nullptr)
		{
			return tempNode;
		}

		return node;
	}

	// ����nodeΪ���Ķ�����������, Ѱ��key��������,��keyС�����ֵ���ڽڵ�, �ݹ��㷨
	// �㷨����ǰ�ѱ�֤key��������nodeΪ���Ķ�������
	Node* predecessorFromAncestor(Node* node, Key key)
	{
		if (node->key == key)
		{
			return nullptr;
		}

		if (key < node->key)
		{
			// �����ǰ�ڵ����key, ��ǰ�ڵ㲻�����Ǳ�keyС�����ֵ
			// �����������Ľ��ֱ�ӷ���
			return predecessorFromAncestor(node->left, key);
		}
		else
		{
			assert(key > node->key);
			// �����ǰ�ڵ�С��key, ��ǰ�ڵ��п����Ǳ�keyС�����ֵ
			// ���Ҽ�������, ������洢��tempNode��
			Node* tempNode = predecessorFromAncestor(node->right, key);
			if (tempNode)
			{
				return tempNode;
			}
			else
			{
				// ���tempNodeΪ��, ��ǰ�ڵ㼴Ϊ���
				return node;
			}
		}
	}

	// ����nodeΪ���Ķ�����������, Ѱ��key��������,��key�����Сֵ���ڽڵ�, �ݹ��㷨
	// �㷨����ǰ�ѱ�֤key��������nodeΪ���Ķ�������
	Node* successorFromAncestor(Node* node, Key key)
	{
		if (node->key == key)
		{
			return nullptr;
		}

		if (key > node->key)
		{
			// �����ǰ�ڵ�С��key, ��ǰ�ڵ㲻�����Ǳ�key�����Сֵ
			// �����������Ľ��ֱ�ӷ���
			return successorFromAncestor(node->right, key);
		}
		else
		{
			assert(key < node->key);
			// �����ǰ�ڵ����key, ��ǰ�ڵ��п����Ǳ�key�����Сֵ
			// �����������, ������洢��tempNode��
			Node* tempNode = predecessorFromAncestor(node->left, key);
			if (tempNode)
			{
				return tempNode;
			}
			else
			{
				// ���tempNodeΪ��, ��ǰ�ڵ㼴Ϊ���
				return node;
			}
		}
	}
};