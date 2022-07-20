#include "List.h"

/// <summary>
/// ����Ʈ ������
/// </summary>
/// <param name="list"> ����� �� ����Ʈ </param>
void construct(LIST** list)
{
	*list = (LIST*)malloc(sizeof(LIST));

	if (*list != NULL)
	{
		(*list)->begin = (NODE*)malloc(sizeof(NODE));
		(*list)->end = (NODE*)malloc(sizeof(NODE));
		(*list)->size = 0;

		if ((*list)->begin != NULL)
		{
			(*list)->begin->next = (*list)->end;
			(*list)->begin->data = 0;
		}

		if ((*list)->end != NULL)
		{
			(*list)->end->next = NULL;
			(*list)->end->data = 0;
		}
	}
}

/// <summary>
/// ����Ʈ �Ҹ���
/// </summary>
/// <param name="list"> ����� �� ����Ʈ </param>
void destruct(LIST** list) 
{
	if (*list != NULL) 
	{
		for (NODE* now = (*list)->begin; now != NULL; free((*list)->begin))
		{
			(*list)->begin = now;
			now = now->next;
		}

		free(*list);
		*list = NULL;
	}
	//_CrtDumpMemoryLeaks();
}

/// <summary>
/// ����Ʈ�� ����� �� Ȯ��
/// </summary>
/// <param name="list"> ����� �� ����Ʈ </param>
/// <returns> ����ٸ� ���� ��ȯ </returns>
bool empty(LIST* list)
{
	return list->size == 0;
	// if (list->size == 0) return true; else return false;
}

/// <summary>
/// ����Ʈ�� ũ�⸦ ��ȯ
/// </summary>
/// <param name="list"> ����� �� ����Ʈ </param>
/// <returns> ũ�� �� </returns>
size_t size(LIST* list) 
{
	return list->size;
}

/// <summary>
/// ����Ʈ�� Ư�� �ε����� �����Ͽ� �ּҰ��� ��ȯ
/// </summary>
/// <param name="list"> ����� �� ����Ʈ </param>
/// <param name="index"> ������ �ε��� </param>
/// <returns> ��� �������� �ּҰ� </returns>
element* at(LIST* list, size_t index)
{
	NODE* result = list->begin->next;

	for (int i = 0; i < index; i++)
	{
		result = result->next;
	}

	return &(result->data);
}

/// <summary>
/// ����Ʈ�� Ư�� �ε��� ��ġ�� �����͸� �߰� ����
/// </summary>
/// <param name="list"> ����� �� ����Ʈ </param>
/// <param name="index"> ������ ��ġ�� �ε��� </param>
/// <param name="data"> ���� �� </param>
void insert(LIST* list, size_t index, element data)
{
	NODE* now = list->begin;

	for (int i = 0; i < index; i++)
	{
		now = now->next;
	}

	NODE* node = (NODE*)malloc(sizeof(NODE));

	if (node != NULL)
	{
		node->data = data;

		node->next = now->next;
		now->next = node;
	}

	list->size++;
}

/// <summary>
/// ����Ʈ�� Ư�� �ε��� ��ġ�� ���Ҹ� ����
/// </summary>
/// <param name="list"> ����� �� ����Ʈ </param>
/// <param name="index"> ������ ��ġ�� �ε��� </param>
void erase(LIST* list, size_t index)
{
	NODE* now = list->begin;

	for (int i = 0; i < index; i++)
	{
		now = now->next;
	}

	NODE* temp = now->next->next;

	free(now->next);

	now->next = temp;

	list->size--;
}

/// <summary>
/// ����Ʈ�� ��� ���Ҹ� ����
/// </summary>
/// <param name="list"> ����� �� ����Ʈ </param>
void clear(LIST* list)
{
	while (list->size != 0) 
	{
		erase(list, 0);
	}
}

/// <summary>
/// �� ����Ʈ�� ����
/// </summary>
/// <param name="list"> ����� �� ����Ʈ </param>
/// <param name="target"> �ڿ� �̾���� ����Ʈ </param>
void append(LIST* list, LIST** target)
{
	if ((*target)->size == 0 && list->size != 0)
	{
		destruct(target);
	}
	else if (list->size == 0) 
	{
		free(list->begin);
		free(list->end);

		list->begin = (*target)->begin;
		list->end = (*target)->end;
		
		list->size = (*target)->size;

		free(*target);

		*target = NULL;
	}
	else
	{
		NODE* temp = NULL;
		
		for (temp = list->begin; temp->next != list->end; temp = temp->next);

		temp->next = (*target)->begin->next;

		free(list->end);
		list->end = (*target)->end;
		list->size = list->size + (*target)->size;

		free((*target)->begin);
		free((*target));
		(*target) = NULL;
	}
}

/// <summary>
/// �� ����Ʈ�� ����
/// </summary>
/// <param name="list"> ����� �� ����Ʈ </param>
/// <param name="target"> �ɰ��� ����Ʈ�� ���� ������ </param>
/// <param name="index"> �ɰ� �ε��� </param>
void split(LIST* list, LIST** target, size_t index)
{
	NODE* now = list->begin;

	for (int i = 0; i < index; i++)
	{
		now = now->next;
	}

	if (target != NULL) 
	{
		destruct(target);
		construct(target);

		if (*target != NULL)
		{
			(*target)->begin->next = now->next;

			free((*target)->end);
			(*target)->end = list->end;

			NODE* end = (NODE*)malloc(sizeof(NODE));

			if (end != NULL)
			{
				end->next = NULL;
			}

			now->next = end;
			list->end = end;

			(*target)->size = list->size - index;
			list->size = index;
		}
	}
}

/// <summary>
/// ����Ʈ ������ ���ǿ� �´� ���Ҹ� ã�� �ε����� ��ȯ
/// </summary>
/// <param name="list"> ����� �� ����Ʈ </param>
/// <param name="condition"> ã�� ������ �Լ� ������ </param>
/// <returns> ã�� ������ �ε��� </returns>
size_t find(LIST* list, void* condition)
{

}

/// <summary>
/// ����Ʈ�� ����
/// </summary>
/// <param name="list"> ����� �� ����Ʈ </param>
void reverse(LIST* list)
{

}

/// <summary>
/// ����Ʈ�� ����
/// </summary>
/// <param name="list"> ����� �� ����Ʈ </param>
void sort(LIST* list)
{

}