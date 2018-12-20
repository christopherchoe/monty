#include "monty.h"

struct global_var glo = {NULL, 0, 0};

/**
  * main - Takes in arguments and attempts to interpret monty code
  *
  * @argc: number of arguments
  * @argv: array of string arguments
  * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
  */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	open_file(argv[1]);

	return (EXIT_SUCCESS);
}

/**
  * open_file - opens the file and feeds it into the command function
  *
  * @file_name: file name that was given
  * Return: int TODO add cases
  */
int open_file(char *file_name)
{
	unsigned int line_no = 0;

	glo.fp = fopen(file_name, "r");
	if (glo.fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	line_no = line_iterate(glo.fp, line_no);

	return (0);
}

/**
  * line_iterate - iterates through lines for commands
  *
  * @fp: file descriptor to get opcodes from
  * Return: TODO
  */
unsigned int line_iterate(FILE *fp, unsigned int line_no)
{
	stack_t *stack = NULL;
	size_t bufsize;

	while (getline(&glo.buffer, &bufsize, fp) != -1)
	{
		line_no++;
		opcode(&stack, line_no);
	}

	memory_clear(stack);

	return (line_no);
}

/**
  * opcode - searches and runs possible opcode commands
  *
  * @command: input command
  * Return: 0 on success, 1 on failure
  */
void opcode(stack_t **stack, unsigned int line_no)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
/*		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},*/
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;
	char *token;

	token = strtok(glo.buffer, " \n\r");

	while (token && opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, token) == 0)
			break;
		i++;
	}
	if (opcodes[i].opcode == NULL)
	{
		dprintf(STDERR_FILENO ,"L%d: unknown instruction %s\n", line_no, token);
		memory_clear(*stack);
		exit(EXIT_FAILURE);
	}
	opcodes[i].f(stack, line_no);
}
