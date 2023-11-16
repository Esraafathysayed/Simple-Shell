#include "shell.h"
/**
 * _getline_handler - print "#cisfun$ " and wait for the user type something.
 * Return: line of string input for user
 */

char *_getline_handler(void)
{
	char *line_pointer = NULL;
	size_t char_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&line_pointer, &char_user, stdin) == -1)
	{
		free(line_pointer);
		return (NULL);
	}

	return (line_pointer);
}
