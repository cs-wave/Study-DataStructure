#include "Stack.h"

/// <summary>
/// 스택 생성자
/// </summary>
/// <param name="stack"> 대상이 될 스택 </param>
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
/// 스택 소멸자
/// </summary>
/// <param name="stack"> 대상이 될 스택 </param>
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
/// 스택이 비었는 지 확인
/// </summary>
/// <param name="stack"> 대상이 될 스택 </param>
/// <returns> 비었다면 참을 반환 </returns>
bool s_empty(STACK* stack)
{
	return stack->size == 0;
}

/// <summary>
/// 스택의 사이즈를 반환
/// </summary>
/// <param name="stack"> 대상이 될 스택 </param>
/// <returns> 스택의 사이즈 </returns>
size_t s_size(STACK* stack)
{
	return stack->size;
}

/// <summary>
/// 스택에 데이터를 삽입
/// </summary>
/// <param name="stack"> 대상이 될 스택 </param>
/// <param name="data"> 넣을 데이터 </param>
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
/// 스택의 맨 위에서 데이터를 반환
/// </summary>
/// <param name="stack"> 대상이 될 스택 </param>
/// <returns> 반환된 데이터 </returns>
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
/// 스택의 맨 위를 스캔
/// </summary>
/// <param name="stack"> 대상이 될 스택 </param>
/// <returns> 스캔한 값 </returns>
element s_top(STACK* stack)
{
	return stack->begin->next->data;
}

/// <summary>
/// 스택을 초기화
/// </summary>
/// <param name="stack"> 대상이 될 스택</param>
void s_clear(STACK* stack)
{
	for (; !s_empty(stack); s_pop(stack));
}