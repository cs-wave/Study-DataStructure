#pragma once
#include <crtdbg.h>
#include "List.hpp"

template <class T>
List<T>::List() 
{
	this->begin = new Node<T>();
	this->end = new Node<T>();

	this->begin->next = this->end;
	this->begin->prev = 0;

	this->end->prev = this->begin;
	this->end->next = 0;

	this->begin->value = 0;
	this->end->value = 0;
}

template <class T>
List<T>::~List() 
{
	while (this->begin)
	{
		Node<T>* temp = this->begin;

		this->begin = this->begin->next;
		delete temp;
	}

	_CrtDumpMemoryLeaks();
}

template <class T>
void List<T>::insert(size_t index, T value)
{
	if (index > size() || index < 0)
	{
		throw;
	}

	Node<T>* temp = new Node<T>();
	Node<T>* location = this->begin;

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
void List<T>::erase(size_t index) 
{
	if (index >= size() || index < 0)
	{
		throw;
	}

	Node<T>* location = this->begin;

	for (int i = 0; i < index; i++)
	{
		location = location->next;
	}

	Node<T>* temp = location->next->next;
	
	delete location->next;

	location->next = temp;
	temp->prev = location;
}


template <class T>
T& List<T>::at(size_t index)
{
	if (index >= size() || index < 0)
	{
		throw;
	}

	Node<T>* temp = this->begin;

	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}

	return temp->next->value;
}

template <class T>
size_t List<T>::size()
{
	size_t result = 0;

	for (Node<T>* temp = this->begin->next; temp->next; temp = temp->next)
	{
		result++;
	}

	return result;
}