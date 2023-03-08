#include <unistd.h>

/**
 * _putchar - writes the char c
 * @c: the char to print
 *
 * Return: 0 for success
 * on error, -1 is returned
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
