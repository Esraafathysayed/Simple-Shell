#include "shell.h"
/**
 * _values_path_handler - separate the path in new strings.
 * @arg: command input of user.
 * @env: environment.
 * Return:  a pointer to strings.
 */
int _values_path_handler(char **arg, char **env)
{
	char *token = NULL, *path_rela = NULL, *path_absolute = NULL;
	size_t value_path, command;
	struct stat stat_line_pointer;

	if (stat(*arg, &stat_line_pointer) == 0)
		return (-1);
	path_rela = _path_handler(env);
	if (!path_rela)
		return (-1);
	token = _strtok(path_rela, ":");
	command = _strlen(*arg);
	while (token)
	{
		value_path = _strlen(token);
		path_absolute = malloc(sizeof(char) * (value_path + command + 2));
		if (!path_absolute)
		{
			free(path_rela);
			return (-1);
		}
		path_absolute = _strcpy(path_absolute, token);
		_strcat(path_absolute, "/");
		_strcat(path_absolute, *arg);

		if (stat(path_absolute, &stat_line_pointer) == 0)
		{
			*arg = path_absolute;
			free(path_rela);
			return (0);
		}
		free(path_absolute);
		token = _strtok(NULL, ":");
	}
	free(path_rela);
	return (-1);
}
