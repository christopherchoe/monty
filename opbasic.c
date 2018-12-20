#include "monty.h"

/**
  * push - pushes an element to the stack
  *
  * @stack: first element of stack
  * @line_number: the line number of the opcode
  * Return: void
  */
void push(stack_t **stack, unsigned int line_number)
{
	/*stack_t *new_element, *tmp;*/

	(void) stack;
	(void) line_number;

	/* TODO check if the next token is integer */

	/* TODO atoi the integer */

	/* TODO add element to stack */

	/* new_element = malloc_stack();
	new_element->n = */
}

/**
  * pall - prints elements of the stack, last to first
  *
  * @stack: first element of stack
  * @line_number: the line number of the opcode
  * Return: void
  */
void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	while (stack != NULL && *stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}

/**
  * pint - prints the first element of the stack
  *
  * @stack: first element of stack
  * @line_number: the line number of the opcode
  * Return: void
  */
/*void pint(stack_t **stack, unsigned int line_number)
{
	printf("%d\n", (*stack)->n);
}*/

/**
  * pop -
  *
  * @stack: first element of stack
  * @line_number: the line number of the opcode
  * Return: void
  */
/*void pop(stack_t **stack, unsigned int line_number)
{

}*/

/**
  * nop - does nothing
  *
  * @stack: first element of stack
  * @line_number: the line number of the opcode
  * Return: void
  */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

