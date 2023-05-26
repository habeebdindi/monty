#include "monty.h"

/**
 * _mod - adds 2 topmost stack elements.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _mod(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (!*head || !(*head)->next)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_num);
		cleanup_exit();
	}
	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_num);
		cleanup_exit();
	}
	top = *head;
	(*head)->next->n += (*head)->n;
	*head = top->next;
	if (*head)
		(*head)->prev = NULL;
	free(top);
}
