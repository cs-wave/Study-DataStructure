#pragma once
#include "stdhs.h"
#include "Stack.h"

void stack_construct(_Stack** stack)
{
	_Stack* result = NULL;

	if ((result = (_Stack*)malloc(sizeof(_Stack))) != NULL) 
	{
		if ((result->head = (_Node*)malloc(sizeof(_Node))) != NULL 
			&& (result->tail = (_Node*)malloc(sizeof(_Node))) != NULL) 
		{
			result->head->next = result->tail;
			result->tail->next = NULL;

			result->head->value = -1;
			result->tail->value = -1;

			*stack = result;

			return;
		}
	}

	printf("memory leaks");
}

void stack_destruct(_Stack* stack)
{
	if (stack->head != NULL)
	{
		_Node* temp = stack->head;
		_Node* temp_next = temp->next;

		while (temp_next != stack->tail->next)
		{
			free(temp);

			temp = temp_next;
			temp_next = temp->next;
		}

		free(stack->tail);
	}

	free(stack);

	_CrtDumpMemoryLeaks();
}

void stack_push(_Stack* stack, _E value)
{
	_Node* location = stack->head;

	_Node* new_node = NULL;

	if ((new_node = (_Node*)malloc(sizeof(_Node))) != NULL)
	{
		new_node->next = location->next;
		location->next = new_node;

		new_node->value = value;

		return;
	}

	printf("memory leaks");
}

_E stack_pop(_Stack* stack)
{
	if (stack_size(stack) == 0)
	{
		printf("stack empty\n");

		return 0;
	}

	_Node* location = stack->head->next->next;
	_E result = stack->head->next->value;

	free(stack->head->next);

	stack->head->next = location;

	return result;
}

size_t stack_size(_Stack* stack)
{
	size_t result = 0;

	for (_Node* location = stack->head->next; location != stack->tail; location = location->next)
	{
		result++;
	}

	return result;
}