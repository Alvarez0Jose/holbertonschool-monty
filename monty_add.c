#include "monty.h"

/**
 * add - adds two elements of the stack
 * @stack: stacks provided for in the struct
 * @line_number: line being analyzed
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *t;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	t = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(t);
}
