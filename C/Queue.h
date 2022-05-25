#pragma once
#include "Node.h"

typedef struct queue
{
	_Node* head;
	_Node* tail;
} _Queue;

void queue_construct(_Queue** queue);
void queue_destruct(_Queue* queue);
void queue_push(_Queue* queue, _E value);
_E queue_pop(_Queue* queue);
size_t queue_size(_Queue* queue);