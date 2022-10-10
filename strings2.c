#include "monty.h"
/**
 * _isnum - check if a character is a number
 * @c: input character
 *
 * Return: 1 if true and 0 if false
 */
int _isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/**
 * _atoi - convert a string of numbers to an integer
 * @num: pointer to num variable
 * @s: input string
 *
 * Return: integer equivalent to input string
 */
int _atoi(int *num, char *s)
{

	int _isnum(char c);
	int i = 0;
	int result = 0;
	int sign = 1;
	int flag = 0;

	while (s[i] != '\0')
	{
		if ((s[i] == '-') && (_isnum(s[i + 1])))
		{
			sign = -1;
			i++;
		}
		if (_isnum(s[i]))
		{
			flag = 1;
			result = (result * 10) + (s[i] - '0');
			i++;
		}
	}
	*num = result * sign;
	if (flag == 1)
		return (0);
	else
		return (-1);
}
