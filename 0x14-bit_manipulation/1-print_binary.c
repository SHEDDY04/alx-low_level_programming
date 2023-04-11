#include "main.h"
#include <stddef.h>

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	size_t bit_count = 0;

	mask = mask << (sizeof(unsigned long int) * 8 - 1);

	while (mask > 0)
	{
		if ((n & mask) == mask)
		{
			_putchar('1');
			bit_count++;
		}
		else if (bit_count > 0 || mask == 1)
			_putchar('0');

		mask = mask >> 1;
	}

	if (bit_count == 0)
		_putchar('0');
}
