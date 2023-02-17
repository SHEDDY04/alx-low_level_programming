#include <stdio.h>

/**
 * main - prints alphabets in lower case and then in upper case
 * @void: rep null argument
 *
 * return: 0
 */
int main(void)
{
	int s = 'a';
	int y = 'A';

	for (; s <= 'z'; s++)
	{
		putchar(s);
	}
	for (; y <= 'Z'; y++)
	{
		putchar(y);
	}
	putchar('\n');

	return (0);
}
