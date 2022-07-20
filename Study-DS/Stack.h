#pragma once
#include "header.h"

typedef struct stack
{
	NODE* begin;
	size_t size;
} STACK;

void s_construct(STACK**);
void s_destruct(STACK**);

bool s_empty(STACK*);
size_t s_size(STACK*);

void s_push(STACK*, element);
element s_pop(STACK*);
element s_top(STACK*);
void s_clear(STACK*);