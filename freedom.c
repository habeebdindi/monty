#include "monty.h"

global_struct_t global_struct;
/**
 * * free_all - free elements in the list
 * *
 * * Return: void
 * */

void free_all(void)
{
	stack_t *temp = NULL;

	while (global_struct.head)
	{
		temp = global_struct.head->next;
		free(global_struct.head);
		global_struct.head = temp;
	}
	fclose(global_struct.fp);
	free(global_struct.line);
}
