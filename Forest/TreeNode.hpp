#pragma once

template <class T>
struct TreeNode {
	T val;
	TreeNode<T>* left = nullptr, * right = nullptr;

	TreeNode(TreeNode<T>* l, TreeNode<T>* r, const T& v) : val(v), left(l), right(r) {}
	virtual ~TreeNode() {}
};