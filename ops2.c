#include "monty.h"

/**
 * _add - adds 2 topmost stack elements.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _add(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (!*head || !(*head)->next)
	{
		printf("L%u: can't swap, stack too short\n", line_num);
		fclose(global.fp);
		free_stack(global.stack);
		free(global.line);
		exit(EXIT_FAILURE);
	}
	top = *head;
	(*head)->next->n += (*head)->n;
	*head = top->next;
	if (*head)
		(*head)->prev = NULL;
	free(top);
}

/**
 * _nop - here goes nothing.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _nop(stack_t **head, __attribute__((unused))unsigned int line_num)
{
	(void)head;
}
