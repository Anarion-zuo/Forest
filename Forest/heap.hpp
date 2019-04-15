#pragma once

#include <vector>

template <class T> class heap // max heap
{
protected:
	std::vector<T> arr;

	void heapify();
	inline size_t parent(const size_t& index);
	inline size_t left(const size_t& index);
	inline size_t right(const size_t& index);

public:
	heap() {}
	virtual ~heap() {}

	virtual void push(const T& item);
	//void pop();
	T& top();
};

template <class T>
void heap<T>::heapify()
{
	size_t index = arr.size() - 1, par = parent(index);
	while (arr[index] > arr[par]) {
		swap(arr[index], arr[par]);
		index = par;
		par = parent(index);
	}
}

template <class T>
size_t heap<T>::right(const size_t& index)
{
	return 2 * index + 1;
}

template <class T>
size_t heap<T>::left(const size_t& index)
{
	return 2 * index;
}

template <class T>
size_t heap<T>::parent(const size_t& index)
{
	return index / 2;
}

template <class T>
void heap<T>::push(const T& item)
{
	arr.push_back(item);
	heapify();
}

template <class T>
T& heap<T>::top()
{
	return arr[0];
}

//template <class T>
//void heap<T>::pop()
//{
//	swap(arr[0], arr[arr.size() - 1]);
//	arr.pop_back();
//	
//}
