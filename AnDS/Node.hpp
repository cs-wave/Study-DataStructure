#pragma once

template <class T>
struct Node
{
	T value;
	Node<T>* prev;
	Node<T>* next;
};