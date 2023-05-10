#include "monty.h"

/**
 * push - push an element onto the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number in the file where the opcode exists
 * @arg: argument to push onto the stack
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	int n;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node || !arg || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(new_node);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;

	/* Add the new node to the beginning of the stack */
	if (*stack == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * pall - print all elements in the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number in the file where the opcode exists
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = *stack;
	(void)line_number;

	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}


}

/**
 * print_stack - prints all the values on the stack
 * @stack: pointer to the head of the stack
 */
void print_stack(stack_t *stack)
{
	stack_t *current_node = stack;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

/**
 * pint - print the value at the top of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number in the file where the opcode exists
 *
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * is_integer - checks if a string is a number
 * @str: the string to check
 * Return: 1 if str is an integer, 0 otherwise
 */
int is_integer(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
