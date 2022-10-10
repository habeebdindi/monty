#include "monty.h"

/**
 * get_op_func - selects correct function for format
 * @s: input opcode
 *
 * Return: pointer to matching function
 */
void (*get_op_func(char *s))(stack_t **head, unsigned int linenumber)
{
	/** initialize struct of opcode functions **/
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"add", op_add},
		{"sub", op_sub},
		{"mul", op_mul},
		{"div", op_div},
		{"mod", op_mod},
		{"nop", op_nop},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"queue", op_queue},
		{"stack", op_stack},
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{"swap", op_swap},
		{NULL, NULL}
	};

	int i = 0;

	/** loop through instructions opcode member **/

	while (instructions[i].opcode)
	{
		if (strcmp(s, instructions[i].opcode) == 0)
			break;
		i++;
	}

	return (instructions[i].f);
}
