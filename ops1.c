#include "monty.h"

/**
 * _push - pushes an element onto the stack.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _push(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	(void)line_num;
	top = malloc(sizeof(stack_t));
	if (!top)
	{
		dprintf(2, "Error: malloc failed\n");
		fclose(global.fp);
		free_stack(global.stack);
		free(global.line);
		exit(EXIT_FAILURE);
	}
	top->prev = NULL;
	top->n = global.number;
	top->next = *head;
	*head = top;
}

/**
 * _pall - prints all stack elements.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _pall(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	(void)line_num;
	if (!*head)
		return;
	top = *head;
	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}

/**
 * _pint - prints top stack element.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _pint(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	(void)line_num;
	if (!*head)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_num);
		fclose(global.fp);
		free_stack(global.stack);
		free(global.line);
		exit(EXIT_FAILURE);
	}
	top = *head;
	printf("%d\n", top->n);
}

/**
 * _pop - removes topmost element from stack.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _pop(stack_t **head, unsigned int line_num)
{
	stack_t *top;

	if (!*head)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_num);
		fclose(global.fp);
		free_stack(global.stack);
		free(global.line);
		exit(EXIT_FAILURE);
	}
	top = *head;
	*head = top->next;
	if (*head)
		(*head)->prev = NULL;
	free(top);
}

/**
 * _swap - swaps 2 topmost stack elements.
 * @head: the head of the stack.
 * @line_num: the line of the opcode being executed.
 * Return: void.
 */
void _swap(stack_t **head, unsigned int line_num)
{
	stack_t *top;
	int temp;

	if (!*head || !(*head)->next)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_num);
		fclose(global.fp);
		free_stack(global.stack);
		free(global.line);
		exit(EXIT_FAILURE);
	}
	top = *head;
	temp = top->n;
	top->n = top->next->n;
	top->next->n = temp;
}
