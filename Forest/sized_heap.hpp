#pragma once
#include "heap.hpp"

template <class T>
class sized_queue : public heap<T> {
protected:
	size_t size;
public:
	sized_heap(const size_t& s): heap<T>(), size(s) {}
	virtual ~sized_heap() {}

	virtual void push(const T& item);

};