#pragma once
#include "Node.hpp"

template <class T>
class List
{
private:
	Node<T>* begin;
	Node<T>* end;

public:
	List();
	~List();
	void insert(size_t index, T value);
	void erase(size_t index);
	T& at(size_t index);
	size_t size();
};