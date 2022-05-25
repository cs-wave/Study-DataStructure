#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include "List.h"
#include "Queue.h"
#include "Stack.h"

void list_test()
{
	_List* list = NULL;
	list_construct(&list);

	for (int i = 0; i < 10; i++)
	{
		list_insert(list, 0, i);
	}

	for (int i = 0; i < 3; i++)
	{
		list_erase(list, 5);
	}

	*list_at(list, 2) = 10;

	for (int i = 0; i < list_size(list); i++)
	{
		printf("%d ", *list_at(list, i));
	}

	list_destruct(list);
}

void queue_test()
{
	_Queue* queue = NULL;
	queue_construct(&queue);

	for (int i = 0; i < 5; i++)
	{
		queue_push(queue, i);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d ", queue_pop(queue));
	}
	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		queue_push(queue, i);
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", queue_pop(queue));
	}
	printf("\n");

	queue_destruct(queue);
}

void stack_test()
{
	_Stack* stack = NULL;
	stack_construct(&stack);

	for (int i = 0; i < 5; i++)
	{
		stack_push(stack, i);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d ", stack_pop(stack));
	}
	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		stack_push(stack, i);
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", stack_pop(stack));
	}
	printf("\n");

	stack_destruct(stack);
}

int main()
{
	stack_test();
}