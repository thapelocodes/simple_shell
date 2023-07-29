#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>

/* for read/write buffers */
#define RD_BUF_SIZE 1024
#define WR_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for myitoa() */
#define CONVLC	1
#define CONVU	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * enum mystatus - singly linked list
 * @n_uno: as -1
 * @uno: as 1
 * @dos: as 2
 * @nada: as 0
 * @true_status: as 0
 * @false_status: points to false
 * @error_status: points to false
 * @code_success: points to true
 */

enum mystatus
{
	n_uno = -1,
	uno = 1,
	dos = 2,
	nada = 0,
	true_status = 1,
	false_status = 0,
	error_status = 1,
	code_success = 0
};


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct shellinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */

typedef struct shellinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;



#define SHELL_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct bltn - contains a bltn string and related function
 *@type: the bltn command flag
 *@func: the function
 */

typedef struct bltn
{
	char *type;
	int (*func)(info_t *);
} bltn_table;


/* filename_shell.c */
int hsh(info_t *, char **);
int find_bltn(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* filename_hndlcmd.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* shell.c */
int loophsh(char **);

/* filename_myerrors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* filename_mystring.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *startw(const char *, const char *);
char *_strcat(char *, char *);

/* filename_mystring1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* filename_myexits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* filename_mystrtok.c */
char **mystrtok(char *, char *);
char **mystrtok2(char *, char);

/* filename_myrealloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* filename_mymem.c */
int bfree(void **);

/* filename_mode.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* filename_myerrors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *myitoa(long int, int, int);
void rmcmt(char *);

/* filename_bltncmd.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* filename_bltncmd1.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/*filename_mygetline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* filename_myinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* filename_myenviron.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int fill_el(info_t *);

/* filename_mygetenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* filename_hist.c */
char *gethistf(info_t *info);
int wr_history(info_t *info);
int rd_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* filename_list_t.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delnodei(list_t **, unsigned int);
void free_list(list_t **);

/* filename_list_t1.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_startw(list_t *, char *, char);
ssize_t getnodei(list_t *, list_t *);

/* filename_myvars.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif
