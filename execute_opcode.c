#include "monty.h"

/**
 * execute_op - checks and executes the opcode.
 * @input: the buffer containing the opcode.
 * @line_num: the line number of the opcode.
 * @stack: pointer to the stack.
 * Return: void.
 */
void execute_op(char *input, unsigned int line_num, stack_t **stack)
{
	instruction_t ops[] = {
		{"pall", _pall},
		{"push", _push},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop}
	};
	char *tok;
	int i;

	input = trim_space(input);
	if (!*input)
		return;
	tok = strtok(input, TOK_DELIM);
	for (i = 0; i < 6 && strlen(tok) == strlen(ops[i].opcode); i++)
		if (strcmp(tok, ops[i].opcode) == 0)
		{
			if (strcmp(tok, "push") == 0)
			{
				tok = strtok(NULL, TOK_DELIM);
				number = atoi(tok);
				if (number == 0 && *tok != '0')
				{
					dprintf(1, "L%u: usage: push integer\n", line_num);
					free_stack(stack);
					free(input);
					exit(EXIT_FAILURE);
				}
			}
			(ops[i]).f(stack, line_num);
			return;
		}
	dprintf(1, "L:%u unknown instruction %s\n", line_num, tok);
	free(input);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
