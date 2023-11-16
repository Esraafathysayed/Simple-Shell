#include "shell.h"
/**
 * _fork_handler - function that create a fork
 *@arg: command and values path
 *@argv: Has the name of our program
 *@env: environment
 *@line_pointer: command line for the user
 *@np: id of process
 *@c: Checker add new test
 *Return: 0 success
 */

int _fork_handler(
	char **arg, char **argv, char **env, char *line_pointer, int np, int c)
{
	pid_t pid_ch;
	int st;
	char *format = "%s: %d: %s: not found\n";

	pid_ch = fork();

	if (pid_ch == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, argv[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(line_pointer);
			exit(errno);
		}
	}
	else
	{
		wait(&st);

		if (WIFEXITED(st) && WEXITSTATUS(st) != 0)
			return (WEXITSTATUS(st));
	}
	return (0);
}
