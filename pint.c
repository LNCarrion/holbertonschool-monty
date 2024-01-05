/**
* _pint - prints top of stack
* @head: double head pointer to the stack
* @counter: line count
*
* Return: nothing
*/
void _pint(stack_t **head, unsigned int counter)
{
	if (*head != NULL)
    {
        printf("%d\n", (*head)->n);
    }
    else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(globals.file);
		free(globals.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}