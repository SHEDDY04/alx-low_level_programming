#include "main.h"
#include <stddef>

/**
 * print_binary - Prints the binary representation of a number
 * @n: The number to print in binary representation
 */
void print_binary(unsigned long int n)
{
    unsigned long int mask = 1;
    int i;

    /* Find the leftmost non-zero bit */
    for (i = (sizeof(unsigned long int) * 8) - 1; i >= 0; i--)
    {
        if ((n >> i) & 1)
            break;
    }

    /* Print each bit in the binary representation */
    for (; i >= 0; i--)
    {
        if (n & (mask << i))
            _putchar('1');
        else
            _putchar('0');
    }
}

