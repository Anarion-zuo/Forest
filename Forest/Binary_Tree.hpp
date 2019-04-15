#pragma once
#include "TreeNode.hpp"

template <class T>
class Binary_Tree
{
private:
	void recur_del(TreeNode<T>* node);

protected:
	TreeNode<T>* root = nullptr;
	size_t size = 0;

public:
	virtual ~Binary_Tree();

};

template <class T>
Binary_Tree<T>::~Binary_Tree()
{
	recur_del(root);
}

template <class T>
void Binary_Tree<T>::recur_del(TreeNode<T>* node)
{
	if (!node)  return;
	recur_del(node->left);
	recur_del(node->right);
	delete node;
}
