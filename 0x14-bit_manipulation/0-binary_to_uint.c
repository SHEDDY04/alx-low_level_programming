#include "main.h"
#include <stddef.h>
#include <string.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned integer.
 * @b: A pointer to a string of 0 and 1 characters.
 *
 * Return: The converted number, or 0 if there is one or more characters in the
 * string b that is not 0 or 1 or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	size_t len = 0;

	if (b == NULL)
		return (0);

	len = strlen(b);

	for (size_t i = 0; i < len; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		result = result << 1;
		if (b[i] == '1')
			result = result | 1;
	}

	return (result);
}

