#include "monty.h"

/**
 * pop - remove item from stack
 * @stack: array of data
 * @line_number: line
 */
void pop(m_stack_t **stack, unsigned int line_number)
{
	m_stack_t *temp;

	/* Check if the stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Save a pointer to the current top element */
	temp = *stack;

	/* Update the stack pointer to point to the next element */
	*stack = (*stack)->next;

	/* Update the previous pointer of the new top element to NULL */
	if (*stack != NULL)
		(*stack)->prev = NULL;

	/* Free the memory of the removed element */
	free(temp);
}