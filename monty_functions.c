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
	if (opcode == NULL || strcmp(opcode, "#") == 0)
		return;

	arg = strtok(NULL, " \t\n\r");

	if (strcmp(opcode, "push") == 0)
		push(stack, line_number, arg);
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
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
