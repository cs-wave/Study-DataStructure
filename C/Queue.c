#pragma once
#include "stdhs.h"
#include "Queue.h"

void queue_construct(_Queue** queue) 
{
	_Queue* result = NULL;

	if ((result = (_Queue*)malloc(sizeof(_Queue))) != NULL)
	{
		if ((result->head = (_Node*)malloc(sizeof(_Node))) != NULL
			&& (result->tail = (_Node*)malloc(sizeof(_Node))) != NULL)
		{
			result->head->next = result->tail;
			result->tail->next = result->head;

			result->head->value = -1;
			result->tail->value = -1;

			*queue = result;

			return;
		}
	}

	printf("memory leaks");
}

void queue_destruct(_Queue* queue)
{
	if (queue->head != NULL)
	{
		_Node* temp = queue->head;
		_Node* temp_next = temp->next;

		while (temp_next != queue->tail->next)
		{
			free(temp);

			temp = temp_next;
			temp_next = temp->next;
		}

		free(queue->tail);
	}

	free(queue);

	_CrtDumpMemoryLeaks();
}

void queue_push(_Queue* queue, _E value)
{
	_Node* temp = NULL;

	if ((temp = (_Node*)malloc(sizeof(_Node))) != NULL) 
	{
		queue->tail->next->next = temp;
		queue->tail->next = temp;
		temp->next = queue->tail;

		temp->value = value;

		return;
	}

	printf("memory leaks");
}

_E queue_pop(_Queue* queue)
{
	if (queue_size(queue) == 0) 
	{
		printf("queue empty\n");

		return 0;
	}

	_E result = queue->head->next->value;
	_Node* location = queue->head->next->next;

	free(queue->head->next);

	queue->head->next = location;

	return result;
}

size_t queue_size(_Queue* queue)
{
	size_t result = 0;

	for (_Node* location = queue->head->next; location != queue->tail; location = location->next)
	{
		result++;
	}

	return result;
}