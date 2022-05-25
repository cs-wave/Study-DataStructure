#pragma once
#include "Node.h"

typedef struct stack
{
	_Node* head;
	_Node* tail;
} _Stack;

void stack_construct(_Stack** stack);
void stack_destruct(_Stack* stack);
void stack_push(_Stack* stack, _E value);
_E stack_pop(_Stack* stack);
size_t stack_size(_Stack* stack);