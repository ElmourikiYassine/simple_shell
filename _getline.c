#include "main.h"
/**
 * _getline - Reads a character from standard input.
 *
 * Return: The character read, or EOF on end of input or error.
 */
int _getline(void)
{
	char c;
	ssize_t bytes_read = read(0, &c, 1);

	if (bytes_read == -1)
	{
		/* Handle error */
		perror("Error reading from stdin");
		exit(EXIT_FAILURE);
	}
	else if (bytes_read == 0)
		return (EOF);
		/* End of file (e.g., Ctrl+D on Unix/Linux) */
	else
	{
		return ((int)c);
	}
}

