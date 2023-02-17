#include <stdio.h>

/**
 * main - print the alphabet in lower case
 * @void: rep null argument
 *
 * Return: 0
 */
int main(void)
{
	int s = 'a';
	int q = 'q';
	int e = 'e';

	for (; s <= 'z'; s++)
	{
		if (s == q || s == e)
			continue;
		putchar(s);
	}
	putchar('\n');
	return (o);
}
