#pragma once
#include "header.h"

typedef struct node
{
	element data;
	struct node* next;
} NODE;

typedef struct list
{
	NODE* begin;
	NODE* end;
	size_t size;
} LIST;

void construct(LIST**);
void destruct(LIST**);

bool empty(LIST*);
size_t size(LIST*);
element* at(LIST*, size_t);

void insert(LIST*, size_t, element);
void erase(LIST*, size_t);
void clear(LIST*);

void append(LIST*, LIST**);
void split(LIST*, LIST**, size_t);

size_t find(LIST*, void*);
void reverse(LIST*);
void sort(LIST*);