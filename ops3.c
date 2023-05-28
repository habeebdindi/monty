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

	if (!*head || !(*head)->next || !head)
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
	(*head)->next->n %= (*head)->n;
	*head = top->next;
	(*head)->prev = NULL;
	free(top);
}

/**
 * _pchar - prints the char at the top of the stack.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _pchar(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	(void)line_num;
	if (!*head || !head)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_num);
		cleanup_exit();
	}
	top = *head;
	printf("%c\n", top->n);
}

/**
 * _pstr - prints the string starting at the stack top, followed by a \n.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _pstr(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	(void)line_num;
	if (!*head || !head)
		return;
	top = *head;
	while (top)
	{
		printf("%c\n", top->n);
		top = top->next;
	}
}
