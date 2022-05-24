#pragma once
#include "Node.h"

template <class T>
class _List
{
private:
	_Node<T>* begin;
	_Node<T>* end;

public:
	_List();
	~_List();
	void _insert(size_t index, T value);
	void _erase(size_t index);
	T& _at(size_t index);
	size_t _size();
};