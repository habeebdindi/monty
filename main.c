#include "monty.h"

/**
 * main - Interpreter for monty bytecodes.
 * @ac: argument count to program.
 * @av: arguments to program.
 * Return: 0 always.
 */
globs global = {0, NULL, NULL, NULL};
int main(int ac, char **av)
{
	size_t len = 0;
	int line_num = 1;

	if (ac != 2)
	{
		dprintf(1, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global.fp = fopen(av[1], "r");
	if (!global.fp)
	{
		dprintf(1, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&(global.line), &len, global.fp) != -1)
	{
		execute_op(global.line, line_num);
		line_num++;
	}
	fclose(global.fp);
	free_stack(global.stack);
	free(global.line);
	return (0);
}
