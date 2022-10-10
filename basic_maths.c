#include "monty.h"

/**
 * op_add - find addition of first and second element in the stack
 * @head: pointer to first element in the stack
 * @line_number: line read
 *
 * Return: void
 */
void op_add(stack_t **head, unsigned int line_number)
{
	stack_t *new = NULL, *node_0 = NULL, *node_1 = NULL;
	int sum = 0;

	if (dlistint_len(*head) < 2)
	{
		dprintf(STDERR_FILENO, ADD_FAIL, line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	node_0 = get_dnodeint_at_index(*head, 0);
	node_1 = get_dnodeint_at_index(*head, 1);

	sum = node_0->n + node_1->n;
	delete_dnodeint_at_index(head, 0);
	delete_dnodeint_at_index(head, 0);

	new =  add_dnodeint(head, sum);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all();
		exit(EXIT_FAILURE);
	}
}

/**
 * op_sub - find subtraction of first and second element in the stack
 * @head: pointer to first element in the stack
 * @line_number: line read
 *
 * Return: void
 */
void op_sub(stack_t **head, unsigned int line_number)
{
	stack_t *new = NULL, *node_0 = NULL, *node_1 = NULL;
	int sub = 0;

	if (dlistint_len(*head) < 2)
	{
		dprintf(STDERR_FILENO, SUB_FAIL, line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	node_0 = get_dnodeint_at_index(*head, 0);
	node_1 = get_dnodeint_at_index(*head, 1);

	sub = node_1->n - node_0->n;
	delete_dnodeint_at_index(head, 0);
	delete_dnodeint_at_index(head, 0);

	new =  add_dnodeint(head, sub);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all();
		exit(EXIT_FAILURE);
	}
}

/**
 * op_mul - find product of first and second element in the stack
 * @head: pointer to first element in the stack
 * @line_number: line read
 *
 * Return: void
 */
void op_mul(stack_t **head, unsigned int line_number)
{
	stack_t *new = NULL, *node_0 = NULL, *node_1 = NULL;
	int prod = 0;

	if (dlistint_len(*head) < 2)
	{
		dprintf(STDERR_FILENO, MUL_FAIL, line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	node_0 = get_dnodeint_at_index(*head, 0);
	node_1 = get_dnodeint_at_index(*head, 1);

	prod = node_0->n * node_1->n;
	delete_dnodeint_at_index(head, 0);
	delete_dnodeint_at_index(head, 0);

	new =  add_dnodeint(head, prod);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all();
		exit(EXIT_FAILURE);
	}
}

/**
 * op_div - find dividend of first and second element in the stack
 * @head: pointer to first element in the stack
 * @line_number: line read
 *
 * Return: void
 */
void op_div(stack_t **head, unsigned int line_number)
{
	stack_t *new = NULL, *node_0 = NULL, *node_1 = NULL;
	int div = 0;

	if (dlistint_len(*head) < 2)
	{
		dprintf(STDERR_FILENO, DIV_FAIL, line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	node_0 = get_dnodeint_at_index(*head, 0);
	node_1 = get_dnodeint_at_index(*head, 1);
	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_FAIL_2, line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	div = node_1->n / node_0->n;
	delete_dnodeint_at_index(head, 0);
	delete_dnodeint_at_index(head, 0);

	new =  add_dnodeint(head, div);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all();
		exit(EXIT_FAILURE);
	}
}

/*
 * op_mod - find modulus of first and second element in the stack
 * @head: pointer to first element in the stack
 * @line_number: line read
 *
 * Return: void
 */

void op_mod(stack_t **head, unsigned int line_number)
{
	stack_t *new = NULL, *node_0 = NULL, *node_1 = NULL;
	int mod = 0;

	if (dlistint_len(*head) < 2)
	{
		dprintf(STDERR_FILENO, MOD_FAIL, line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	node_0 = get_dnodeint_at_index(*head, 0);
	node_1 = get_dnodeint_at_index(*head, 1);
	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, MOD_FAIL_2, line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	mod = node_1->n % node_0->n;
	delete_dnodeint_at_index(head, 0);
	delete_dnodeint_at_index(head, 0);

	new =  add_dnodeint(head, mod);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all();
		exit(EXIT_FAILURE);
	}
}
