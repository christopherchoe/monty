#include "monty.h"

/**
  * rotr - rotates the last element to be the top element
  *
  * @stack: first element of the stack
  * @line_number: current line number
  * Return: void
  */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *copy;
	(void) line_number;

	copy = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (copy != NULL && (copy)->next != NULL)
	{
		copy = copy->next;
	}

	tmp = copy->prev;
	tmp->next = copy->next;
	copy->prev = NULL;
	copy->next = (*stack)->next;
	*stack = copy;
}
