#include "monty.h"

void cleanm(stack_t *stack)
{
    fclose(globals.file);
    if (globals.line != NULL)
        free(globals.line);
    free_stack(&stack);
        
}

void free_stack(stack_t **stack)
{
    stack_t *tmp = NULL;

    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}
