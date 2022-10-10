nclude "monty.h"

/**
 * * op_stack - change the linked list to act as stack
 * * @head: pointer to first element of the stack
 * * @line_number: line read
 * *
 * * Return: void
 * */
void op_stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	global_struct.flag = 0;
}

/**
 * * op_queue - change linked list to act as queue
 * * @head: pointer to first element of the stack
 * * @line_number: line read
 * *
 * * Return: void
 * */
void op_queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	global_struct.flag = 1;
}

/**
 * * op_rotl - rotate the stack to the left
 * * @head: pointer to first element of the stack
 * * @line_number: line read
 * *
 * * Return: void
 * */
void op_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	int num = 0;

	(void)line_number;
	if (!*head)
		return;
	temp = get_dnodeint_at_index(*head, 0);
	num = temp->n;
	delete_dnodeint_at_index(head, 0);
	add_dnodeint_end(head, num);
}

/**
 * * op_rotr - rotate the stack to the right
 * * @head: pointer to first element of the stack
 * * @line_number: line read
 * *
 * * Return: void
 * */
void op_rotr(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;
	int num = 0, len = dlistint_len(*head);

	(void)line_number;
	if (!*head)
		return;
	temp = get_dnodeint_at_index(*head, len - 1);
	num = temp->n;
	delete_dnodeint_at_index(head, len - 1);
	add_dnodeint_end(head, num);
}

/**
 * * op_swap - swap first two elements of the stack
 * * @head: pointer to first element of the stack
 * * @line_number: line read
 * *
 * * Return: void
 * */

void op_swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head, *new = NULL;
	int num = 0;

	if (dlistint_len(*head) < 2)
	{
		dprintf(STDERR_FILENO, SWAP_FAIL, line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = get_dnodeint_at_index(*head, 0);
	num = temp->n;
	delete_dnodeint_at_index(head, 0);
	new = insert_dnodeint_at_index(head, 1, num);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all();
		exit(EXIT_FAILURE);
	}
}
