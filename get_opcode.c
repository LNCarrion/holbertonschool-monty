#include "monty.h"

/**
 * get_opcode - get opcode.
 * @stack: pointer to stack.
 * @line_number: line number.
 * @opcode: opcode.
 * Return: void.
 */

void get_opcode(stack_t **stack, unsigned int line_number, char *opcode)
{
    int i = 0;
    instruction_t opcodes[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };

    while (opcodes[i].opcode)
    {
        if (strcmp(opcode, opcodes[i].opcode) == 0)
        {
            opcodes[i].f(stack, line_number);
            return;
        }
        i++;
    }
    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
    free_stack(stack);
    exit(EXIT_FAILURE);
}

int is_number(char *str)
{
    int i = 0;

    if (str[0] == '-')
        i = 1;
    for (; str[i]; i++)
    {
        if (isdigit(str[i]) == 0)
            return (0);
    }
    return (1);
}