#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

#define BUFFER_SIZE 1024
/**
 * main - Copies the content of a file to another file.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of arguments passed to the program.
 *
 * Return: 0 on success, or an error code on failure.
 */

int main(int argc, char *argv[])
{
    int file_from, file_to, r, w, c;
    char buffer[BUFFER_SIZE];

    /* Check the number of arguments */
    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    /* Open the source file */
    file_from = open(argv[1], O_RDONLY);
    if (file_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    /* Open or create the destination file */
    file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (file_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
        exit(99);
    }

    /* Copy the content from source file to destination file */
    while ((r = read(file_from, buffer, BUFFER_SIZE)) > 0)
    {
        w = write(file_to, buffer, r);
        if (w == -1 || w != r)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
            exit(99);
        }
    }

    /* Check for read error */
    if (r == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    /* Close the files */
    c = close(file_from);
    if (c == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
        exit(100);
    }

    c = close(file_to);
    if (c == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
        exit(100);
    }

    return 0;
}

