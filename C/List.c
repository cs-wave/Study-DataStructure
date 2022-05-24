#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "List.h"

void _construct(_List** list)
{
	_List* result = (_List*)malloc(sizeof(_List));

	result->head = (_Node*)malloc(sizeof(_Node));
	result->tail = (_Node*)malloc(sizeof(_Node));

	result->head->next = result->tail;
	result->tail->next = NULL;
	
	result->head->value = -1;
	result->tail->value = -1;

	*list = result;
}

void _destruct(_List* list)
{
	while (list->head != NULL) 
	{
		_Node* temp = list->head->next;

		free(list->head);

		list->head = temp;
	}

	free(list);
}

void _insert(_List* list, size_t index, _E value)
{
	if (index > _size(list) || index < 0)
	{
		printf("index over\n"); 
		return; 
	}

	_Node* temp = (_Node*)malloc(sizeof(_Node));
	_Node* location = list->head;

	for (int i = 0; i < index; i++)
	{
		location = location->next;
	}

	temp->next = location->next;
	location->next = temp;
	temp->value = value;
}

void _erase(_List* list, size_t index)
{
	if (index >= _size(list) || index < 0) 
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

_E* _at(_List* list, size_t index)
{
	if (index >= _size(list) || index < 0)
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

size_t _size(_List* list)
{
	int result = 0;

	for (_Node* temp = list->head -> next; temp->next != NULL; temp = temp->next)
	{
		result++;
	}

	return result;
}

void show(_List* list) 
{
	printf("Start -> ");
	for (_Node* temp = list->head->next; temp->next != NULL; temp = temp->next)
	{
		printf("%d -> ", temp->value);
	}
	printf("End\n\n");
}