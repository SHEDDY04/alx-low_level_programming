#include <stdio.h>

/**
 * main - print single digitd in base 10
 *
 * return: 0
 */
int main(void)
{
	int s = 0;

	for (; s < 10; s++)
	{
		printf("%d", s);
	}
	putchar('\n');
	return (0);
}
