#include "monty.h"

/**
 * op_push - add a node to the head of the stack
 * @head: double pointer to the nodes in the list
 * @line_number: line read
 *
 * Return: void
 */

void op_push(stack_t **head, unsigned int line_number)
{
	int data = 0, digit = 0;
	stack_t *new = NULL;
	char *num = strtok(NULL, " \t\n");

	if (num && num[0] == '-')
		data++;
	while (num && num[data])
		if (!isdigit(num[data++]))
		{
			data = -1;
			break;
		}
	if (!num || data == -1)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	digit = atoi(num);
	if (global_struct.flag == 0)
		new = add_dnodeint(head, digit);
	else if (global_struct.flag == 1)
		new = add_dnodeint_end(head, digit);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all();
		exit(EXIT_FAILURE);
	}
}
/**
 * op_pall - print the linked list
 * @h: pointer to the first element in the stack
 * @line_number: pointer to the nodes of the list
 *
 * Return: void
 */

void op_pall(stack_t **h, unsigned int line_number)
{
	int i;
	stack_t *temp = *h;

	line_number = line_number;
	for (i = 0; temp; i++)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * op_pop - remove most recenet element on the stack
 * @head: pointer to first element of the stack
 * @line_number: line read
 *
 * Return: void
 */

void op_pop(stack_t **head, unsigned int line_number)
{
	stack_t **temp = head;

	if (!*temp)
	{
		dprintf(STDERR_FILENO, POP_FAIL, line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(temp, 0);
}

/**
 * op_pint - print first element of the stack
 * @head: pointer to first element on the stack
 * @line_number: line read
 *
 * Return: void
 */
void op_pint(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	if (!*head)
	{
		dprintf(STDERR_FILENO, PINT_FAIL, line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}

/**
 * op_nop - function that doesnt do anything
 * @head: pointer to first element in the stack
 * @line_number: line read
 *
 * Return: void
 */

void op_nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
