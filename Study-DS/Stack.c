#include "Stack.h"

/// <summary>
/// ���� ������
/// </summary>
/// <param name="stack"> ����� �� ���� </param>
void s_construct(STACK** stack)
{
	*stack = (STACK*)malloc(sizeof(STACK));

	if (*stack != NULL)
	{
		(*stack)->begin = (NODE*)malloc(sizeof(NODE));
		(*stack)->size = 0;

		if ((*stack)->begin != NULL)
		{
			(*stack)->begin->next = (NODE*)malloc(sizeof(NODE));
			(*stack)->begin->data = 0;
			
			if ((*stack)->begin->next != NULL)
			{
				(*stack)->begin->next->next = NULL;
			}
		}
	}
}

/// <summary>
/// ���� �Ҹ���
/// </summary>
/// <param name="stack"> ����� �� ���� </param>
void s_destruct(STACK** stack)
{
	if (*stack != NULL)
	{
		for (NODE* now = (*stack)->begin; now != NULL; free((*stack)->begin))
		{
			(*stack)->begin = now;
			now = now->next;
		}

		free(*stack);
		*stack = NULL;
	}
}

/// <summary>
/// ������ ����� �� Ȯ��
/// </summary>
/// <param name="stack"> ����� �� ���� </param>
/// <returns> ����ٸ� ���� ��ȯ </returns>
bool s_empty(STACK* stack)
{
	return stack->size == 0;
}

/// <summary>
/// ������ ����� ��ȯ
/// </summary>
/// <param name="stack"> ����� �� ���� </param>
/// <returns> ������ ������ </returns>
size_t s_size(STACK* stack)
{
	return stack->size;
}

/// <summary>
/// ���ÿ� �����͸� ����
/// </summary>
/// <param name="stack"> ����� �� ���� </param>
/// <param name="data"> ���� ������ </param>
void s_push(STACK* stack, element data)
{
	NODE* node = (NODE*)malloc(sizeof(NODE));

	if (node != NULL)
	{
		node->data = data;

		node->next = stack->begin->next;
		stack->begin->next = node;
	}

	stack->size++;
}

/// <summary>
/// ������ �� ������ �����͸� ��ȯ
/// </summary>
/// <param name="stack"> ����� �� ���� </param>
/// <returns> ��ȯ�� ������ </returns>
element s_pop(STACK* stack)
{
	if (!s_empty(stack))
	{
		NODE* temp = stack->begin->next->next;

		element result = stack->begin->next->data;

		free(stack->begin->next);

		stack->begin->next = temp;

		stack->size--;

		return result;
	}

	return 0;
}

/// <summary>
/// ������ �� ���� ��ĵ
/// </summary>
/// <param name="stack"> ����� �� ���� </param>
/// <returns> ��ĵ�� �� </returns>
element s_top(STACK* stack)
{
	return stack->begin->next->data;
}

/// <summary>
/// ������ �ʱ�ȭ
/// </summary>
/// <param name="stack"> ����� �� ����</param>
void s_clear(STACK* stack)
{
	for (; !s_empty(stack); s_pop(stack));
}