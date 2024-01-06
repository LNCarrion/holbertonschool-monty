#include "monty.h"

/**
 *pall - print all opcode
 *@stack: array of data to print
 *@line_number: lines in input;
 */
void pall(m_stack_t **stack, unsigned int line_number)
{
	m_stack_t *current = *stack;

	/* Suppress unused parameter warning for line_number */
	(void)line_number;

	/* Traverse the stack and print each element */
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}