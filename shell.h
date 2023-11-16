#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

char *_path_handler(char **env);
int _values_path_handler(char **arg, char **env);
char *_getline_handler(void);
void _env_handler(char **env);
char **_token_handler(char *line_pointer);
void _exit_handler(char **arg, char *line_pointer, int _exit);
int _fork_handler(char **arg, char **argv, char **env, char *line_pointer, int np, int c);
char *_strtok(char *str, const char *delim);

#endif /* SHELL_H */
