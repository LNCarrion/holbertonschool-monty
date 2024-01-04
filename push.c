#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: doble pointer to the head of the stack.
 * @line_number: line number in the file where the opcode is located.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(globals.file);
		free(globals.line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = globals.data;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
