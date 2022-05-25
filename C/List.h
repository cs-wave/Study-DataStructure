#pragma once
#include "stdhs.h"
#include "Node.h"

typedef struct list
{
	_Node* head;
	_Node* tail;
} _List;

void list_construct(_List** list);
void list_destruct(_List* list);
void list_insert(_List* list, size_t index, _E value);
void list_erase(_List* list, size_t index);
_E* list_at(_List* list, size_t index);
size_t list_size(_List* list);