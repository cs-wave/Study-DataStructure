#include "header.h"
#include "List.h"
#include "Stack.h"

// main source code

int main()
{
	LIST* list1 = NULL;

	l_construct(&list1);

	l_insert(list1, 0, 1);
	l_insert(list1, 0, 2);
	l_insert(list1, 0, 3);
	l_insert(list1, 0, 4);
	l_insert(list1, 0, 5);

	LIST* list2 = NULL;

	l_construct(&list2);

	l_insert(list2, 0, 6);
	l_insert(list2, 0, 7);
	l_insert(list2, 0, 8);
	l_insert(list2, 0, 9);
	l_insert(list2, 0, 10);

	l_append(list1, &list2);

	for (int i = 0; i < l_size(list1); i++)
	{
		printf("%d -> ", *l_at(list1, i));
	}
	printf("\n");

	l_split(list1, &list2, 5);

	for (int i = 0; i < l_size(list1); i++)
	{
		printf("%d -> ", *l_at(list1, i));
	}
	printf("\n");

	for (int i = 0; i < l_size(list2); i++)
	{
		printf("%d -> ", *l_at(list2, i));
	}
	printf("\n");

	//printf("%lld", find_element(list1, 11));

	l_sort(list1, false);

	for (int i = 0; i < l_size(list1); i++)
	{
		printf("%d -> ", *l_at(list1, i));
	}
	printf("\n");

	l_destruct(&list1);
	l_destruct(&list2);

	printf("\n\nCHECK\n\n");


	STACK* stack = NULL;

	s_construct(&stack);

	s_push(stack, 1);
	s_push(stack, 2);
	s_push(stack, 3);
	s_push(stack, 4);

	printf("%d\n", s_pop(stack));
	printf("%d\n", s_pop(stack));
	printf("%d\n", s_pop(stack));
	printf("%d\n", s_top(stack));
	
	s_push(stack, 1);
	s_push(stack, 2);
	s_push(stack, 3);
	s_push(stack, 4);

	printf("%d\n", s_pop(stack));
	printf("%d\n", s_pop(stack));
	printf("%d\n", s_pop(stack));
	printf("%d\n", s_pop(stack));
	printf("%d\n", s_pop(stack));
	printf("%d\n", s_pop(stack));

	s_destruct(&stack);

	printf("\n\nCHECK\n\n");


	_CrtDumpMemoryLeaks();
}