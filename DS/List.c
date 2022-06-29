#include "List.h"

void construct(LIST** list)
{
	(*list) = (LIST**)malloc(sizeof(LIST*));

	if (*list != NULL)
	{
		(*list)->begin = (NODE*)malloc(sizeof(NODE));
		(*list)->end = (NODE*)malloc(sizeof(NODE));
		(*list)->size = 0;

		if ((*list)->begin != NULL)
		{
			(*list)->begin->next = (*list)->end;
			(*list)->begin->data = 0;
		}

		if ((*list)->end != NULL)
		{
			(*list)->end->next = NULL;
			(*list)->end->data = 0;
		}
	}
}

void destruct(LIST** list) 
{

}

bool empty(LIST* list)
{
	return list->size == 0;
	// if (list->size == 0) return true; else return false;
}

size_t size(LIST* list) 
{
	return list->size;
}

element* at(LIST* list, size_t index)
{
	NODE* result = list->begin->next;

	for (int i = 0; i < index; i++)
	{
		result = result->next;
	}

	return &(result->data);
}

void insert(LIST* list, size_t index, element data)
{
	NODE* now = list->begin;

	for (int i = 0; i < index; i++)
	{
		now = now->next;
	}

	NODE* node = (NODE*)malloc(sizeof(NODE));

	if (node != NULL)
	{
		node->data = data;

		node->next = now->next;
		now->next = node;
	}

	list->size++;
}

void erase(LIST* list, size_t index)
{
	NODE* now = list->begin;

	for (int i = 0; i < index; i++)
	{
		now = now->next;
	}

	NODE* temp = now->next->next;

	free(now->next);

	now->next = temp;

	list->size--;
}

void clear(LIST* list)
{

}

void merge(LIST* list, LIST* target)
{

}

void split(LIST* list, LIST** target, size_t index)
{

}

size_t find(LIST* list, void* condition)
{

}

void reverse(LIST* list)
{

}

void sort(LIST* list)
{

}