#include "monty.h"

int number = 0;

/**
 * main - Interpreter for monty bytecodes.
 * @ac: argument count to program.
 * @av: arguments to program.
 * Return: 0 always.
 */
int main(int ac, char **av)
{
	FILE  *fp;
	char *line = NULL;
	size_t len = 0;
	int line_num = 1;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		dprintf(1, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (!fp)
	{
		dprintf(1, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, fp) != EOF)
	{
		execute_op(line, line_num, &stack);
		line_num++;
	}
	free(line);
	fclose(fp);
	free_stack(&stack);
	return (0);
}
