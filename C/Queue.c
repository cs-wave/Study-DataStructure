#pragma once
#include "stdhs.h"
#include "Queue.h"

void queue_construct(_Queue** queue) 
{
	_Queue* result = (_Queue*)malloc(sizeof(_Queue));

	result->head = (_Node*)malloc(sizeof(_Node));
	result->tail = (_Node*)malloc(sizeof(_Node));

	result->head->next = result->tail;
	result->tail->next = NULL;

	result->head->value = -1;
	result->tail->value = -1;

	*queue = result;
}

void queue_destruct(_Queue* queue)
{
	while (queue->head != NULL)
	{
		_Node* temp = queue->head->next;

		free(queue->head);

		queue->head = temp;
	}

	free(queue);

	_CrtDumpMemoryLeaks();
}

void queue_push(_Queue* queue, _E value)
{
	_Node* location = NULL;

	for (location = queue->head; location->next->next != NULL; location = location->next);

	_Node* temp = (_Node*)malloc(sizeof(_Node));

	temp->next = location->next;
	location->next = temp;

	temp->value = value;
}

_E queue_pop(_Queue* queue)
{
	if (queue_size(queue) == 0) 
	{
		printf("queue empty\n");
		return;
	}

	_Node* location = queue->head->next->next;
	_E result = queue->head->next->value;

	free(queue->head->next);

	queue->head->next = location;

	return result;
}

size_t queue_size(_Queue* queue)
{
	int result = 0;

	for (_Node* temp = queue->head->next; temp->next != NULL; temp = temp->next)
	{
		result++;
	}

	return result;
}