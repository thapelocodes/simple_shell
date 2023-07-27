#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdbool.h>

#define MAX_COM_LEN 128
#define MAX_TOK_LEN 64

int _putchar(char c);
char *_strcpy(char *dest, char *src);
int split(char *str, const char *delimiters, char **tokens, int max_tokens);
void _puts(char *str);
char *_strdup(const char *s);
size_t _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);
char *_memcpy(char *dest, char *src, unsigned int n);
int _isalpha(int c);
int _atoi(char *s);
void free_tokens(char **tokens);

#endif
