#pragma once
#include "Node.h"

typedef struct list
{
	_Node* head;
	_Node* tail;
} _List;

void _construct(_List** list);
void _destruct(_List* list);
void _insert(_List* list, size_t index, _E value);
void _erase(_List* list, size_t index);
_E* _at(_List* list, size_t index);
size_t _size(_List* list);