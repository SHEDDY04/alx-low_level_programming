#include "main.h"

/**
 * _strlen - finds the length of a string
 * @str: pointer to the string
 *
 * Return: length of the string
 */
size_t _strlen(char *str)
{
	size_t l;

	for (l = 0; str[i]; i++)
		;
	return (l);
}

/**
 * append_text_to_file - appends a text at the end of a file.
 * @filename: name of the file
 * @text_content: NULL terminated string
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fed;
	ssize_t lent;

	if (filename == NULL)
		return (-1);
	fed = open(filename, O_WRONLY | O_APPEND);
	if (fed == -1)
		return (-1);
	if (text_content != NULL)
		lent = write(fed, text_content, _strlen(text_content));
	close(fed);
	if (lent == -1)
		return (-1);
	return (1);
}
