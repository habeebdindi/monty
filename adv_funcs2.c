#include "monty.h"

/**
 * op_pchar - print element of stack as char
 * @head: pointer to first element of the stack
 * @line_number: line read
 *
 * Return: void
 */
void op_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *node = *head;

	if (!node)
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL_2, line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (node->n >= 0 && node->n <= 127)
	{
		putchar(node->n);
		putchar ('\n');
	}
	else
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL, line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

}

/**
 * op_pstr - print elements of stack as chars
 * @head: pointer to first element of stack
 * @line_number: line read
 *
 * Return: void
 */

void op_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *node = *head;

	(void)line_number;
	while (node)
	{
		if (node->n > 0 && node->n <= 127)
		{
			putchar(node->n);
			node = node->next;
		}
		else
			break;
	}
	putchar('\n');
}
