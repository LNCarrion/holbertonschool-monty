#include "monty.h"

/**
 *pint - prints the value @ the top of the stack
 *@stack: pointer to the stack
 *@line_number: unused param in this function
 */
void pint(m_stack_t **stack, unsigned int line_number)
{ /* Check if the stack is empty */
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Print the value at the top of the stack */
	printf("%d\n", (*stack)->n);
}