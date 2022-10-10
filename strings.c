#include "monty.h"

/**
 * * wordcount - finds words within string
 * * @str: string being passed to check for words
 * *
 * * Return: number of words
 * */

int wordcount(char *str)
{
	int num = 0, i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			i++;
		else
		{
			while (str[i] != ' ' && str[i])
				i++;
			num++;
		}
	}
	return (num);
}

/**
 * * rm_nl - remove the last character newline from string
 * * @lineptr: double pointer to string
 * */
void rm_nl(char **lineptr)
{
	char *ptr = NULL;
	int i;

	ptr = *lineptr;

	i = 0;
	while (ptr[i] != '\n')
		i++;
	ptr[i] = '\0';
}

/**
 * * _strlen - find the length of a string
 * * @s: pointer to string
 * *
 * * Return: length of string as int
 * */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}

/**
 * * strtok_list - tokenize line into argument
 * * @line: input string
 * *
 * */

void strtok_list(char *line)
{
	global_struct.arg = strtok(line, " \t\n");
}
