#include "main.h"

/**
 * _memcpy -  function that copies memory area @n from @src to @dest
 * @n: the memory to be copied
 * @src: the memory area to be copied from
 * @dest: the memory area to be copied to
 *
 * Return: a pointer to @dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
