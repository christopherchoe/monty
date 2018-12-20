#include "monty.h"

/**
  * swap - swaps the top two elements of the stack
  *
  * @stack: first element of the stack
  * @line_number: current line number
  * Return: void
  */
void swap(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
  * add - adds the top two elements of the stack
  *
  * @stack: first element of the stack
  * @line_number: current line number
  * Return: void
  */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL)
		return;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		memory_clear(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
