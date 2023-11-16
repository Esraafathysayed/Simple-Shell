#include "shell.h"
/**
 * _token_handler - get token of string
 * @line_pointer: comman user
 * Return: To a pointer
 */

char **_token_handler(char *line_pointer)
{
	char **user_command = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;

	if (line_pointer == NULL)
		return (NULL);

	for (i = 0; line_pointer[i]; i++)
	{
		if (line_pointer[i] == ' ')
			size++;
	}
	if ((size + 1) == _strlen(line_pointer))
		return (NULL);
	user_command = malloc(sizeof(char *) * (size + 2));
	if (user_command == NULL)
		return (NULL);

	token = _strtok(line_pointer, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		user_command[i] = token;
		token = _strtok(NULL, " \n\t\r");
	}
	user_command[i] = NULL;
	return (user_command);
}
