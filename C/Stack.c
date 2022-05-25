#pragma once
#include "stdhs.h"
#include "Stack.h"

void stack_construct(_Stack** stack)
{
	_Stack* result = (_Stack*)malloc(sizeof(_Stack));

	result->head = (_Node*)malloc(sizeof(_Node));
	result->tail = (_Node*)malloc(sizeof(_Node));

	result->head->next = result->tail;
	result->tail->next = NULL;

	result->head->value = -1;
	result->tail->value = -1;

	*stack = result;
}

void stack_destruct(_Stack* stack)
{
	while (stack->head != NULL)
	{
		_Node* temp = stack->head->next;

		free(stack->head);

		stack->head = temp;
	}

	free(stack);

	_CrtDumpMemoryLeaks();
}

void stack_push(_Stack* stack, _E value)
{
	_Node* location = stack->head;

	_Node* temp = (_Node*)malloc(sizeof(_Node));

	temp->next = location->next;
	location->next = temp;

	temp->value = value;
}

_E stack_pop(_Stack* stack)
{
	if (stack_size(stack) == 0)
	{
		printf("stack empty\n");
		return;
	}

	_Node* location = stack->head->next->next;
	_E result = stack->head->next->value;

	free(stack->head->next);

	stack->head->next = location;

	return result;
}

size_t stack_size(_Stack* stack)
{
	int result = 0;

	for (_Node* temp = stack->head->next; temp->next != NULL; temp = temp->next)
	{
		result++;
	}

	return result;
}