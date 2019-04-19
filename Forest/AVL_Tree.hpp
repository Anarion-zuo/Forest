#pragma once
#include "Binary_Tree.hpp"

template <class T>
class AVL_Tree : public Binary_Tree<T> {
private:
	TreeNode<T>* pfront = nullptr;
	TreeNode<T>* pback = nullptr;

	static void rotate_left(TreeNode<T>*& node);
	static void rotate_right(TreeNode<T>*& node);
	inline static void balance_with_one_rotation(TreeNode<T>*& node);

protected:
	size_t size = 0;

public:
	virtual void push(const T& item);
	void pop_front();
	void pop_back();
	T& front();
	T& back();
};

template <class T>
void AVL_Tree<T>::rotate_left(TreeNode<T>*& x)
{
	if (!x)  throw "Trying to rotate nullptr";
	if (!x->right)  throw "Trying to rotate and put nullptr to the root";
	TreeNode<T>* l = new TreeNode<T>(x->left, x->right->left, x->val), * res = new TreeNode<T>(l, x->right->right, x->right->val), * temp = x;
	x = res;
	delete temp;
}

template <class T>
void AVL_Tree<T>::rotate_right(TreeNode<T>*& x)
{
	if (!x)  throw "Trying to rotate nullptr";
	if (!x->left)  throw "Trying to rotate and put nullptr to the root";
	TreeNode<T>* l = new TreeNode<T>(x->left->right, x->right, x->val), * res = new TreeNode<T>(x->left->left, l, x->left->val), * temp = x;
	x = res;
	delete temp;
}

template <class T>
void AVL_Tree<T>::balance_with_one_rotation(TreeNode<T>*& node)
{
	int bal = Binary_Tree<T>::is_balanced(node);
	if (bal > 0) {
		rotate_right(node);
	}
	else if (bal < 0) {
		rotate_left(node);
	}
}

template <class T>
void AVL_Tree<T>::push(const T& item)
{
	if (!this->root) {
		this->root = new TreeNode<T>(nullptr, nullptr, item);
		++size;
		return;
	}
	TreeNode<T>* node = this->root, * last = node;
	while (node) {
		last = node;
		if (item < node->val) {
			node = node->left;
		}
		else if (item > node->val) {
			node = node->right;
		}
	}
	if (item < last->val) {
		last->left = new TreeNode<T>(nullptr, nullptr, item);
	}
	else if (item > last->val) {
		last->right = new TreeNode<T>(nullptr, nullptr, item);
	}
	balance_with_one_rotation(this->root);
	size++;
}

template <class T>
void AVL_Tree<T>::pop_front()
{
	if (!this->root) {
		throw "Nothing to pop";
	}
	if (!this->root->left) {
		delete this->root;
		this->root = nullptr;
		size--;
		return;
	}
	TreeNode<T>* node = this->root, * last = node;
	while (node->left) {
		last = node;
		node = node->left;
	}
	delete node;
	last->left = nullptr;
	balance_with_one_rotation(this->root);
	size--;
}

template <class T>
void AVL_Tree<T>::pop_back()
{
	if (!this->root) {
		throw "Nothing to pop";
	}
	if (!this->root->right) {
		delete this->root;
		this->root = nullptr;
		size--;
		return;
	}
	TreeNode<T>* node = this->root, * last = node;
	while (node->right) {
		last = node;
		node = node->right;
	}
	delete last->right;
	last->right = nullptr;
	balance_with_one_rotation(this->root);
}

template <class T>
T& AVL_Tree<T>::front()
{
	if (!this->root) {
		throw "Empty Content";
	}
	TreeNode<T>* node = this->root;
	while (node->left) {
		node = node->left;
	}
	return node->val;
}

template <class T>
T& AVL_Tree<T>::back()
{
	if (!this->root) {
		throw "Empty Content";
	}
	TreeNode<T>* node = this->root;
	while (node->right) {
		node = node->right;
	}
	return node->val;
}
