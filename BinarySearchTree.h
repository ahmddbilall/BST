#pragma once
#include <iostream>
#include <queue>
using  namespace std;


struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class bst {
	Node* root;

public:
	bst()
	{
		root = nullptr;
	}

	void insert(int data)
	{
		root = insertHelper(root, data);
	}

	void preorder()
	{
		preorderHelper(root);
	}

	void inorder()
	{
		inorderHelper(root);
	}

	void postorder()
	{
		postorderHelper(root);
	}

	void levelOrder()
	{
		if (!root)
			return;
		queue<Node*> q;
		q.push(root);

		while (!q.empty())
		{
			Node* n = q.front();
			q.pop();
			cout << n->data << "  ";
			if (n->left)
				q.push(n->left);
			if (n->right)
				q.push(n->right);
		}
	}

	int depthOfTree()
	{
		return depthHelper(root, 0);
	}

	int heightOfTree()
	{
		return heightHelper(root);
	}

	bool search(int data)
	{
		return searchHelper(root, data);
	}

	void remove(int data)
	{
		if (!search(data))
			return;
		root = removeHelper(root, data);
	}

	int getMin()
	{
		return getMinHelper(root);
	}

	int getMax()
	{
		return getMaxHelper(root);
	}

	int Kthmin(int k)
	{
		return KthminHelper(root, k);
	}

	int Kthmax(int k)
	{
		return KthmaxHelper(root, k);
	}

private:

	int KthmaxHelper(Node* r, int& k)
	{
		if (!r) {
			k--;
			return INT_MAX;
		}
		int x = KthmaxHelper(r->right, k);
		if (x != INT_MAX)
			return x;

		if (k == 0)
			return r->data;
		k--;
		return INT_MAX;
	}

	int KthminHelper(Node* r, int &k)
	{
		if (!r)
		{
			k--;
			return INT_MIN;
		}
		int x = KthminHelper(r->left, k);
		if (x != INT_MIN)
			return x;

		if (k == 0)
			return r->data;
		k--;
		return INT_MIN;
	}

	Node* removeHelper(Node* r, int data)
	{
		if (!r)
			return r;

		if (r->data > data)
			r->left = removeHelper(r->left, data);
		else if (r->data < data)
			r->right = removeHelper(r->right, data);
		else if (r->data == data)
		{
			if (!r->left && !r->right)
			{
				return nullptr;
			}
			else if (r->left && !r->right)
			{
				r->data = getMaxHelper(r->left);
				r->left = removeHelper(r->left, r->data);
			}
			else if (!r->left && r->right)
			{
				r->data = getMinHelper(r->right);
				r->right = removeHelper(r->right, r->data);
			}
			else if (r->left && r->right)
			{
				r->data = getMinHelper(r->right);
				r->right = removeHelper(r->right, r->data);
			}
		}
		return r;
	}

	int getMaxHelper(Node* r)
	{
		if (!r)
			return INT_MAX;

		if (r->right == nullptr)
			return r->data;
		getMinHelper(r->right);
	}

	int getMinHelper(Node* r)
	{
		if (!r)
			return INT_MIN;

		if (r->left == nullptr)
			return r->data;
		getMinHelper(r->left);
	}

	bool searchHelper(Node* r, int data)
	{
		if (!r)
			return false;
		if (r->data == data)
			return true;
		if (r->data > data)
			return searchHelper(r->left, data);
		else if (r->data < data)
			return searchHelper(r->right, data);
	}

	int depthHelper(Node* r, int d)
	{
		if (!r)
			return d - 1;//depth of root is zero

		int left = depthHelper(r->left, d + 1);
		int right = depthHelper(r->right, d + 1);
		return left > right ? left : right;
	}

	int heightHelper(Node* r)
	{
		if (!r)
			return -1;
		int left = 1 + heightHelper(r->left);
		int right = 1 + heightHelper(r->right);
		return left > right ? left : right;

	}

	Node* insertHelper(Node* r, int data)
	{
		if (r == nullptr)
		{
			return new Node(data);
		}
		else
		{
			if (r->data > data)
				r->left = insertHelper(r->left, data);
			else if (r->data <= data)
				r->right = insertHelper(r->right, data);
		}
		return r;
	}

	void preorderHelper(Node* r)
	{
		if (!r)
			return;
		cout << r->data << "  ";
		preorderHelper(r->left);
		preorderHelper(r->right);
	}

	void postorderHelper(Node* r)
	{
		if (!r)
			return;
		postorderHelper(r->left);
		postorderHelper(r->right);
		cout << r->data << "  ";
	}

	void inorderHelper(Node* r)
	{
		if (!r)
			return;
		inorderHelper(r->left);
		cout << r->data << "  ";
		inorderHelper(r->right);
	}


};