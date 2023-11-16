#include "shell.h"
/**
 * _exit_handler - this function closes the simple_shell when
 * @arg: pointer with the direction argument.
 * @line_pointer: stander input string
 * @_exit: value of exit
 * Return: None
 */
void _exit_handler(char **arg, char *line_pointer, int _exit)
{
	int exit_status = 0;

	if (!arg[1])
	{
		free(line_pointer);
		free(arg);
		exit(_exit);
	}
	exit_status = atoi(arg[1]);

	free(line_pointer);
	free(arg);
	exit(exit_status);
}

/**
 *_env_handler - function to get all env
 *@env: environment
 *Return: 0
 */

void _env_handler(char **env)
{
	size_t run = 0;

	while (env[run])
	{
		write(STDOUT_FILENO, env[run], _strlen(env[run]));
		write(STDOUT_FILENO, "\n", 1);
		run++;
	}
}
