#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
	char *buffer = (char *) malloc(letters + 1);

	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}
	ssize_t bytes_read = fread(buffer, 1, letters, file);

	if (bytes_read <= 0 || fwrite(buffer, 1, bytes_read, stdout) != bytes_read)
	{
		free(buffer);
		fclose(file);
		return (0);
	}
	free(buffer);
	fclose(file);
	return (bytes_read);
}

