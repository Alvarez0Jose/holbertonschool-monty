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

	if (!arg || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
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
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

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

	while (current_node != NULL)
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
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
