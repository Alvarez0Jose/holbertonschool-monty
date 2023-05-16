#include "monty.h"

/**
 *execute - passes and executes an instruction
 *@line: A string containing the instructions
 *@stack: A pointer to the stack
 *@line_number: The line number of the instruction
 *Return: void
 */

void execute(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode, *arg;

	opcode = strtok(line, " \t\n\r");
	if (opcode == NULL || strcmp(opcode, "#", 1) == 0)
		return;

	arg = strtok(NULL, " \t\n\r");

	if (strcmp(opcode, "push") == 0)
	{
		if (arg == NULL)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		push(stack, line_number, arg);
	}
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);
	else
	{
		fprintf(stderr, "L%u unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * FreeStack - frees the stack
 * @stack: stack provided
 */
void FreeStack(stack_t **stack)
{
	stack_t *current_node = *stack, *next_node;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}

	*stack = NULL;
}
