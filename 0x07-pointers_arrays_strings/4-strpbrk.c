#include "main.h"

/**
 * _strpbrk - a function that searches a string for any of a set of bytes.
 *
 * @s: the string
 *
 * @accept: the bytes
 *
 * Return: a pointer to the byte in @s
 */

char *_strpbrk(char *s, char *accept)
{
	int i;
	while (*s)

	{
			for (i = 0; accept[i]; i++)
			{
				for (*s == accept[i])
					return (s);
			}
			s++;
	}
	return (NULL);
}
