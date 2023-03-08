#include "main.h"

/**
 * check - checks for the square root
 * @a: int
 * @b: int
 *
 * Return: int
 */

int check(int a, int b)
{
	if (a * a == b)
		return (b);
	if (a * a > b)
		return (-1);
	return (check(a + 1, b));
}

/**
 * _sqrt_recursion - returns the natural square root of a num
 * @n: int to find sqrt of
 *
 * Return: natural sqrt or -1
 */

int _sqrt_recursion(int n)
{
	if (n == 0)
		return (0);
	return (check(1, n));
}
