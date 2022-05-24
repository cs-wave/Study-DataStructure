#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include "List.h"


void list_test()
{
	_List* list = NULL;
	_construct(&list);

	for (int i = 0; i < 10; i++)
	{
		_insert(list, 0, i);
	}

	for (int i = 0; i < 3; i++)
	{
		_erase(list, 5);
	}

	*_at(list, 2) = 10;

	for (int i = 0; i < _size(list); i++)
	{
		printf("%d ", *_at(list, i));
	}

	_destruct(list);
}


int main() 
{
	list_test();
}