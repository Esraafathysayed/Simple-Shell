#include "shell.h"
/**
 * main - main arguments functions
 * @argc:count of argumnents
 * @argv: arguments
 * @env: environment
 * Return: _exit = 0.
 */
int main(int argc, char **argv, char **env)
{
	char *command = NULL, **user_command = NULL;
	int pathValue = 0, _exit = 0, n = 0;
	(void)argc;

	while (1)
	{
		command = _getline_handler();
		if (command)
		{
			pathValue++;
			user_command = _token_handler(command);
			if (!user_command)
			{
				free(command);
				continue;
			}
			if ((!_strcmp(user_command[0], "exit")) && user_command[1] == NULL)
				_exit_handler(user_command, command, _exit);
			if (!_strcmp(user_command[0], "env"))
				_env_handler(env);
			else
			{
				n = _values_path_handler(&user_command[0], env);
				_exit = _fork_handler(user_command, argv, env, command, pathValue, n);
				if (n == 0)
					free(user_command[0]);
			}
			free(user_command);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(_exit);
		}
		free(command);
	}
	return (_exit);
}
