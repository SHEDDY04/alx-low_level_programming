#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         O/w - the actual number of bytes the function can read and print.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
	{
		return (0);
	}

	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		return (0);
	}

	char *buffer = (char *) malloc(sizeof(char) * (letters + 1));

	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}
	ssize_t bytes_read = fread(buffer, sizeof(char), letters, file);

	if (bytes_read <= 0, || fwrite(buffer, sizeof(char), bytes_read, stdout)
			!= bytes_read)
		{
			fclose(file);
			free(buffer);
			return (0);
		}
		fclose(file);
		free(buffer);
		return (bytes_read);
}
