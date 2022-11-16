#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* general functions */
void prompt_user(void);
void handle_signal(int);
char **get_string_tokens(char *);
void free_defined_buffer(char **);
int check_builtin(char **, char *);
int handle_builtin(char **, char *);
void print_env(void);
void exit_command(char **, char *);
char *find_path(void);
char *test_path(char **, char *);
char *append_path(char *, char *);
void execution(char *, char **);

/* string functions */
int _strcmp(char *, char *);
int _strlen(char *);
int _strncmp(char *, char *, int);
char *_strchr(char *, char);
char *_strdup(char *);

/* print functions */
int _putchar(char);
int _puts(char *);

/**
 * struct flags - keeps track of interactive mode
 * @interactive_mode: stores interactive mode state
 *
 * Description: same as above
 */
struct flags
{
	bool interactive_mode;
} flags;

/**
 * struct builtin - holds builtin functions to execute
 * @env: env builtin
 * @exit: exit builtin
 *
 * Description: same as above
 */
struct builtin
{
	char *env;
	char *exit;
} builtin;

/**
 * struct info - stores line info
 * @final_exit: final exit
 * @ln_count: line count
 *
 * Description: same as above
 */
struct info
{
	int final_exit;
	int ln_count;
} info;

#endif
