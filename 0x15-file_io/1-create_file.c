#include "main.h"
/**
 * create_file -creates an array of chars, and initializes
 *
 * @text_content: is a NULL terminated string
 * @filename: is the name of the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int p, r, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	p = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	r = write(p, text_content, len);

	if (p == -1 || r == -1)
		return (-1);

	close(p);

	return (1);
}
