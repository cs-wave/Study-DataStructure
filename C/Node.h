#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

typedef int _E;

typedef struct node
{
	_E value;
	struct node* next;
} _Node;
