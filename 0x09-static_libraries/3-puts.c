#include "main.h"

/**
 * _puts - to print a string to stout
 * @str: the string
 * Return: the lenght of the string
 */

void _puts(char *str)
{
	int a = 0;

	while (str[a] != '\0')
	{
		_putchar(str[a]);
		a++;
	}
	_putchar('\n');
}
