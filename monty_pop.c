#include "monty.h"

/**
 * pop - remove the top element of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number in the file where the opcode exists
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_node = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top_node);
}
