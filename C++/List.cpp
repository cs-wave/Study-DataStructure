#pragma once
#include <crtdbg.h>
#include "List.h"

template <class T>
_List<T>::_List() 
{
	this->begin = new _Node<T>();
	this->end = new _Node<T>();

	this->begin->next = this->end;
	this->begin->prev = 0;

	this->end->prev = this->begin;
	this->end->next = 0;

	this->begin->value = 0;
	this->end->value = 0;
}

template <class T>
_List<T>::~_List() 
{
	while (this->begin)
	{
		_Node<T>* temp = this->begin;

		this->begin = this->begin->next;
		delete temp;
	}

	_CrtDumpMemoryLeaks();
}

template <class T>
void _List<T>::_insert(size_t index, T value)
{
	if (index > _size() || index < 0)
	{
		throw;
	}

	_Node<T>* temp = new _Node<T>();
	_Node<T>* location = this->begin;

	for (int i = 0; i < index; i++)
	{
		location = location->next;
	}

	location->next->prev = temp;
	location->next->prev->prev = location;
	location->next->prev->next = location->next;
	location->next = temp;
	temp->value = value;
}

template <class T>
void _List<T>::_erase(size_t index) 
{
	if (index >= _size() || index < 0)
	{
		throw;
	}

	_Node<T>* location = this->begin;

	for (int i = 0; i < index; i++)
	{
		location = location->next;
	}

	location->next = location->next->next;
	delete location->next->prev;
	location->next->prev = location;
}


template <class T>
T& _List<T>::_at(size_t index)
{
	if (index >= _size() || index < 0)
	{
		throw;
	}

	_Node<T>* temp = this->begin;

	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}

	return temp->next->value;
}

template <class T>
size_t _List<T>::_size()
{
	size_t result = 0;

	for (_Node<T>* temp = this->begin->next; temp->next; temp = temp->next)
	{
		result++;
	}

	return result;
}