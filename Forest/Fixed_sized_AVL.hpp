#pragma once

#include "AVL_Tree.hpp"

template <class T>
class Fixed_sized_AVL : AVL_Tree<T> {
private:
	size_t max_size;

public:
	Fixed_sized_AVL(const size_t& n) : max_size(n) {}

	void push(const T& item);
};

template <class T>
void Fixed_sized_AVL<T>::push(const T& item)
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
	if (size > max_size)  pop_front();//or pop_back()
}
