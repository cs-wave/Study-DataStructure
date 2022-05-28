#pragma once
#include "stdhs.h"
#include "List.h"

void list_construct(_List** list)
{
	_List* result = NULL;

	if ((result = (_List*)malloc(sizeof(_List))) != NULL)
	{
		if ((result->head = (_Node*)malloc(sizeof(_Node))) != NULL
			&& (result->tail = (_Node*)malloc(sizeof(_Node))) != NULL)
		{
			result->head->next = result->tail;
			result->tail->next = result->head;

			result->head->value = -1;
			result->tail->value = -1;

			*list = result;

			return;
		}
	}

	printf("memory leaks");
}

void list_destruct(_List* list)
{
	if (list->head != NULL)
	{
		_Node* temp = list->head;
		_Node* temp_next = temp->next;

		while (temp_next != list->tail->next)
		{
			free(temp);

			temp = temp_next;
			temp_next = temp->next;
		}

		free(list->tail);
	}

	free(list);

	_CrtDumpMemoryLeaks();
}

void list_insert(_List* list, size_t index, _E value)
{
	if (index > list_size(list) || index < 0)
	{
		printf("index over\n");

		return;
	}

	_Node* new_node = NULL;
	_Node* location = list->head;

	for (int i = 0; i < index; i++)
	{
		location = location->next;
	}

	if ((new_node = (_Node*)malloc(sizeof(_Node))) != NULL)
	{
		new_node->next = location->next;
		location->next = new_node;
		new_node->value = value;

		return;
	}

	printf("memory leaks");
}

void list_erase(_List* list, size_t index)
{
	if (index >= list_size(list) || index < 0) 
	{
		printf("index over\n"); 
		return; 
	}

	_Node* location = list->head;

	for (int i = 0; i < index; i++) 
	{
		location = location->next;
	}

	_Node* temp = location->next->next;
	
	free(location->next);

	location->next = temp;
}

_E* list_at(_List* list, size_t index)
{
	if (index >= list_size(list) || index < 0)
	{
		printf("index over\n");
		return;
	}

	_Node* location = list->head;

	for (int i = 0; i < index; i++)
	{
		location = location->next;
	}

	return &(location->next->value);
}

size_t list_size(_List* list)
{
	size_t result = 0;

	for (_Node* location = list->head->next; location != list->tail; location = location->next)
	{
		result++;
	}

	return result;
}


//void show(_List* list) 
//{
//	printf("Start -> ");
//	for (_Node* temp = list->head->next; temp->next != NULL; temp = temp->next)
//	{
//		printf("%d -> ", temp->value);
//	}
//	printf("End\n\n");
//}