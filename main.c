#include "monty.h"

/**
 * main - entry point.
 * @argc: number of arguments.
 * @argv: arguments.
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */


int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	stack_t *stack = NULL;
	unsigned int line_number = 1;
	char line[256];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		get_opcode(&stack, line, line_number);
		line_number++;
	}

	fclose(file);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
