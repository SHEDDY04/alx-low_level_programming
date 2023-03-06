#include "main.h"

/**
 * *_strchr - locates a char in a string
 * @c: ocurrence of the char
 * @s: the string
 * Return: a pointer to the first occurrence of the character
 */
char *_strchr(char *s, char c)
{
	while (*s)

	{
		if (*s != c, c == '\0', s++)

		else
			return (s);
	}

	return (NULL);
}
