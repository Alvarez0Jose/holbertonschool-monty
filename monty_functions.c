#include "monty.h"

/**
 *execute_instruction - passes and executes an instruction
 *@line: A string containing the instructions
 *@stack: A pointer to the stack
 *@line_number: The line number of the instruction
 *Return: void
 */

void execute_instruction(char *line, stack_t **stack, unsigned int line_number)
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
}
 /**
 * free_stack - frees a stack
 * @stack: a pointer to the stack
 * Return: void
 */

void free_stack(stack_t **stack)
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
