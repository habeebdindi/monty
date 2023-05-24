#include "monty.h"
#include <stdio.h>

int main(int ac, char **av)
{
	FILE  *fp;
	char *line = NULL;
	size_t len = 0;
	int line_num = 1;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen("av[1]", "r");
	if (!fp)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, fp) != -1)
	{
		printf("line: %s\n", line);
		execute_op(line, line_num);
		line_num++;
	}
	return (0);
}

void execute_op(char *input, unsigned int line_num)
{
	instruction_t ops[] = {
	        {"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	stack_t *stack;
	char *tok;
	int i;

	stack = malloc(sizeof(stack_t));
	if (!stack)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tok = strtok(input, TOK_DELIM);
	for (i = 0; i < 2; i++)
	{
		if (strcmp(tok, ops[i].opcode) == 0)
		{
			tok = strtok(NULL, TOK_DELIM);
			number = atoi(tok);
			if (number == 0 && *tok != '0')
			{
				printf("L%u: usage: push integer\n", line_num);
				exit(EXIT_FAILURE);
			}
			ops[i].f(&stack, line_num);
		}
		else
		{
			printf("L:%u unknown instruction %s\n", line_num, tok);
			exit(EXIT_FAILURE);
		}
	}
}
