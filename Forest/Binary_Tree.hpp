#pragma once
#include "TreeNode.hpp"

template <class T>
class Binary_Tree
{
private:
	void recur_del(TreeNode<T>* node);

protected:
	TreeNode<T>* root = nullptr;
	static long height(TreeNode<T>* node);  //height of the root is 0
	inline static int is_balanced(TreeNode<T>* node);
	inline static bool is_leaf(TreeNode<T>* node);

public:
	virtual ~Binary_Tree();

};

template <class T>
int Binary_Tree<T>::is_balanced(TreeNode<T>* node)
{
	return height(node->left) - height(node->right);
}

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

template <class T>
long Binary_Tree<T>::height(TreeNode<T>* node)
{
	if (!node)  return -1;
	long h1 = height(node->left), h2 = height(node->right);
	return h1 > h2 ? h1 : h2 + 1;
}

template <class T>
bool Binary_Tree<T>::is_leaf(TreeNode<T>* node)
{
	return !(node->left || node->right);
}
