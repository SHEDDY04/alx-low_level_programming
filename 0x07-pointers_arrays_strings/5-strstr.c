#include "main.h"

/**
 * _strstr - a function that locates a string
 *
 * @needle: the substring
 * @haystack: the string
 *
 * Return: a pointer to the beginning of the located string.
 */

char *_strstr(char *haystack, char *needle)
{
	unsigned int i = 0, j = 0;

	while (haystack[i])
	{
		while (needle[j] && (haystack[i] == needle[0]))
		{
			if (haystack[i + j] == needle[j])
				j++;
		}
		if (needle[j])
		{
		i++;
		j = 0;
		}
		else
		return (haystack + i);

	}
	return (0);
}
