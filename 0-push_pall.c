#include "monty.h"

void _push(stack_t **head, unsigned int line_num)
{
        stack_t *top;

	(void)line_num;
        top = malloc(sizeof(stack_t));
        if (!top)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
        top->prev = NULL;
        top->n = number;
        top->next = *head;
        *head = top;
}

void _pall(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	(void)line_num;
	if (!*head)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	top = *head;
	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
