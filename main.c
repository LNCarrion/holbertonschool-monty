#include "monty.h"

/**
 * main - entry point.
 * @argc: number of arguments.
 * @argv: arguments.
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */

int main(int argc, char **argv)
{
    char opcode[6] = {0}, wrong[1024] = {0};
    int global = 0;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    ssize_t read;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    globals.file=NULL;
    globals.file = fopen(argv[1], "r");
    if (globals.file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        fclose(globals.file);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&globals.line, &len, globals.file)) != -1)
    {
        line_number++;
        if (!_whitespace())
        {
            global = sscanf(globals.line, "%s%d%1s", opcode, &globals.data, wrong);
            if (global != 2 && strcmp(opcode, "push") == 0)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                cleanm(stack);
                exit(EXIT_FAILURE);
            }
        }
        free (globals.line);
        globals.line = NULL;
    }
    cleanm(stack);
    return (0);
}

int _whitespace(void)
{
    int i, j;
    char *ws = "/r/n/t ";

    for (i = 0; globals.line[i] != '\0'; i++)
        for (j = 0; ws[j] != '\0' && globals.line[i] != ws[j]; j++)
            if (ws[j] == '\0')
                return (0);
    return (1);
}
