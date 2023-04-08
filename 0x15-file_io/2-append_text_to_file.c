#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success and -1 on failure.
 *         If filename is NULL return -1.
 *         If text_content is NULL, do not add anything to the file.
 *         Return 1 if the file exists and -1 if the file does not exist.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, len, bytes_written;

	if (filename == NULL)
		return (-1);

	if (access(filename, F_OK) == -1)
		return (-1);

	if (text_content == NULL)
		return (1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	len = 0;
	while (text_content[len] != '\0')
		len++;

	bytes_written = write(fd, text_content, len);
	close(fd);

	if (bytes_written == len)
		return (1);

	return (-1);
}

