#include "main.h"

/**
 * flip_bits - Returns the number of bits needed to flip to get from one number
 *             to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to flip to get from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int x = n ^ m;
	unsigned int count = 0;

	while (x)
	{
		count += x & 1;
		x >>= 1;
	}

	return (count);
}

