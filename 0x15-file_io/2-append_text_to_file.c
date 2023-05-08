/**
 * append_text_to_file - Appends the given text content.
 * @filename: Name of the file.
 * @text_content: Null-terminated string.
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	if (filename == NULL)
		return (-1);

	int fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		size_t len = strlen(text_content);
		ssize_t bytes_written = write(fd, text_content, len);
		if (bytes_written == -1 || bytes_written != (ssize_t) len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

