#pragma once
#include "Binary_Tree.hpp"

template <class T>
class AVL_Tree : Binary_Tree<T> {
private:
	TreeNode<T>* pfront = nullptr;
	TreeNode<T>* pback = nullptr;

	void rotate_left(TreeNode<T>*& node);

public:
	void push(const T* item);
	void pop_front();
	void pop_back();
	T& front();
	T& back();
};

template <class T>
void AVL_Tree<T>::rotate_left(TreeNode<T>*& x)
{
	if (!x)  return;
	TreeNode<T>* l = new TreeNode<T>(x->left, x->right->left, x->val), * res = new TreeNode<T>(l, x->right->right, x->right), * temp = x;
	x = res;
	delete temp;
}

template <class T>
void AVL_Tree<T>::push(const T* item)
{
	if (!root) {
		root = new TreeNode<T>(nullptr, nullptr, item);
		return;
	}
	TreeNode<T>* node = root, * last;;
	while (node) {
		last = node;
		if (*item < *node->val) {
			node = node->left;
		}
		else if (*item > *node->val) {
			node = node->right;
		}
	}
	if (*item < *last->val) {
		last->left = new TreeNode<T>(nullptr, nullptr, item);
	}
	else if (*item > *last->val) {
		last->right = new TreeNode<T>(nullptr, nullptr, item);
	}
}
