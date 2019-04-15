#pragma once

template <class T>
struct TreeNode {
	T* val = nullptr;
	TreeNode<T>* left = nullptr, * right = nullptr;

	TreeNode(TreeNode<T>* l, TreeNode<T>* r, T* v = nullptr) : val(v), left(l), right(r) {}
	virtual ~TreeNode() {}
};