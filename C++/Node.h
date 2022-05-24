#pragma once

template <class T>
struct _Node
{
	T value;
	_Node<T>* prev;
	_Node<T>* next;
};