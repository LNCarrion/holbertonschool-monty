#include "monty.h"

/**
 * swap - swap top 2 elements of stack
 * @stack: array of data
 * @line_number: line
 */

void swap(m_stack_t **stack, unsigned int line_number)
{
	m_stack_t *temp;

	/* Check if there are at least two elements on the stack */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Save pointers to the top two elements */
	temp = (*stack)->next;

	/* Update the next pointers to perform the swap */
	(*stack)->next = temp->next;
	temp->next = *stack;

	/* Update the previous pointers to maintain the doubly linked list */
	temp->prev = NULL;
	(*stack)->prev = temp;

	/* Update the stack pointer to point to the new top element */
	*stack = temp;
}