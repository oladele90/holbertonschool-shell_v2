#ifndef _SHELL_H_
#define _SHELL_H_
#define READ_SIZE 5
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <pwd.h>


/*extern char **environ;*/

/**
 * struct list_s - singly linked list
 * @str: character string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 *
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

typedef struct commands 
{
    char *command;
    char *args[13];
    char *redirection_file;
    char *redirection;
    int pipe;
    struct CommandNode *next;
} CommandNode;

char *_memcpy(char *dest, char *src, unsigned int n);
void free_list(list_t *head);
size_t print_list(list_t *h);
list_t *make_p_list(char *path, list_t *h);
int _execute(char **args, char **envp_copy);
char **_split_toks(char *line, char *delim);
char *get_path(char *name);
list_t *add_node_end(list_t *head, const char *str);
char *_getline(char *line, char **envp_copy);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int _strcmp(char *s1, char *s2);
void change_to_home_directory(void);
uid_t get_uid(void);
char *_strdup(char *str, char *new_str);
int _strncmp(char* str1, char* str2, int index);
void update_env(char *new, char *var, char **envp_copy);
int handle_builtins(char **args, char **envp_copy);
void change_to_previous_directory(char **envp_copy);
int _strlen(char *s);
char *_getenv(char *pathy, char **envp_copy);
char *_strcpy(char *destination, char *source);
void add_full_path(char **envp_copy, char **argarr);
char *_strcat(char *dest, char *src);
/*list_t *add_node_end(list_t *head, const char *str);*/

#endif