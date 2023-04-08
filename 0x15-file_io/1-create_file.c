#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a new file and writes a string to it.
 * @filename: The name of the file to create.
 * @text_content: The string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, result, text_len;

	if (filename == NULL)
		return (-1);

	/* Open the file for writing, creating it if necessary */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	/* Write the string to the file, if provided */
	if (text_content != NULL)
	{
		text_len = 0;
		while (text_content[text_len])
			text_len++;
		result = write(fd, text_content, text_len);
		if (result == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

