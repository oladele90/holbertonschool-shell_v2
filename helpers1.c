#include "shell.h"

/**
 * _getline - grabs command from line in stdin
 *
 * Return: command
 */

char *_getline(void)
{
	char *line = NULL;
	size_t buflen = 0;

	if (isatty(STDIN_FILENO) == 1)
		printf("($) ");
	if (getline(&line, &buflen, stdin) < 0)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("\n");
		free(line);
		exit(0);
	}
	return (line);
}
/**
 * _split_toks - splits command line args into tokens
 * @line : line of arguments
 * Return: array of arguments
 */

char **_split_toks(char *line)
{
	int length = 0;
	int capacity = 16;
	char **tokens = malloc(capacity * sizeof(char *));
	char *delim = " \n";
	char *token = strtok(line, delim);

	while (token != NULL)
	{
		tokens[length] = token;
		length++;
		token = strtok(NULL, delim);
	}
	tokens[length] = NULL;
	return (tokens);
}

/**
 * _execute - creates child process and executes
 * @args : argument vector from command line
 */

void _execute(char **args) {
    extern char **environ;
    
    if (args[0] == NULL) {
        // Empty command, do nothing
        return;
    }

    if (_strcmp(args[0], "cd") == 0) {
        // Handle 'cd' command
        if (args[1] == NULL) {
            // No directory specified, change to home directory
            struct passwd *pw = getpwuid(getuid());
        if (pw == NULL) {
            // Failed to get user information
                perror("getpwuid");
        return;
        }
    
        if (chdir(pw->pw_dir) != 0) {
            // Failed to change directory
            perror("chdir");
    }
        } else {
            // Change to the specified directory
            if (chdir(args[1]) != 0) {
                perror("chdir");
            }
        } 
    }else if (_strcmp(args[0], "env") == 0) {
    // Handle 'env' command
        char **env = environ;
        while (*env != NULL) {
            printf("%s\n", *env);
            env++;
        }
    }
    else {
        // Execute external program
        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
            return;
        } else if (child_pid == 0) {
            // Child process
            execve(args[0], args, NULL);
            perror("execve");
            exit(1);
        } else {
            // Parent process
            wait(NULL);
        }
    }
}
