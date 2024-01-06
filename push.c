#include "monty.h"

/**
 *push - adds to the stack
 *@stack:a pointer to the head of the stack
 *@line_number:data to be stored
 */

void push(m_stack_t **stack, unsigned int line_number)
{
	m_stack_t *new_node;

	/* Allocate memory for a new stack node */
	new_node = malloc(sizeof(m_stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Set the integer value in the new node */
	new_node->n = line_number;

	/* Initialize pointers for the new node */
	new_node->prev = NULL;
	new_node->next = *stack;

	/* Update the previous pointer of the current top element */
	if (*stack != NULL)
		(*stack)->prev = new_node;

	/* Update the stack pointer to point to the new top element */
	*stack = new_node;
}