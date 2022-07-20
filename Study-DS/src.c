#include "header.h"
#include "List.h"

// main source code

int main()
{
	LIST* list1 = NULL;
	
	construct(&list1);

	insert(list1, 0, 1);
	insert(list1, 0, 2);
	insert(list1, 0, 3);
	insert(list1, 0, 4);
	insert(list1, 0, 5);

	LIST* list2 = NULL;

	construct(&list2);

	insert(list2, 0, 6);
	insert(list2, 0, 7);
	insert(list2, 0, 8);
	insert(list2, 0, 9);
	insert(list2, 0, 10);

	append(list1, &list2);

	for (int i = 0; i < size(list1); i++) 
	{
		printf("%d -> ", *at(list1, i));
	}
	printf("\n");

	split(list1, &list2, 5);

	for (int i = 0; i < size(list1); i++)
	{
		printf("%d -> ", *at(list1, i));
	}
	printf("\n");

	for (int i = 0; i < size(list2); i++)
	{
		printf("%d -> ", *at(list2, i));
	}
	printf("\n");

	destruct(&list1);
	destruct(&list2);

	printf("CHECK");

	_CrtDumpMemoryLeaks();

}