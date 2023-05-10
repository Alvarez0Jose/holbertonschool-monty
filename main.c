#include "monty.h"

/**
 * main - entry point
 *@argv: argument vector
 *@argc: argument counter
 *Return: 0
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	FILE *file;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		execute(line, &stack, line_number);
	}

	free(line);
	FreeStack(&stack);
	fclose(file);

	return (EXIT_SUCCESS);
}
