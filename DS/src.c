#include "header.h"
#include "List.h"

int main()
{
	LIST* list = NULL;
	
	construct(&list);

	insert(list, 0, 1);
	insert(list, 0, 2);
	insert(list, 0, 3);
	insert(list, 0, 4);
	insert(list, 0, 5);

	int a = *at(list, 3);
	*at(list, 2) = 4;

	erase(list, 4);

	for (int i = 0; i < size(list); i++) 
	{
		printf("%d -> ", *at(list, i));
	}

	printf("CHECK");
}