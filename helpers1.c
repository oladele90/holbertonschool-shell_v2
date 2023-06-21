#include "shell.h"

/**
 * _getline - grabs command from line in stdin
 *
 * Return: command
 */

char *_getline(char *line, char **envp_copy)
{
	size_t buflen = 0;

	if (isatty(STDIN_FILENO) == 1)
		printf("($) ");
	if (getline(&line, &buflen, stdin) < 0)
	{
        int j = 0;
		if (isatty(STDIN_FILENO) == 1)
			printf("\n");
        for (j = 0; envp_copy[j] != NULL; j++)
            {
                free(envp_copy[j]);
                envp_copy[j] = NULL;
            }
        free(envp_copy);
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

char **_split_toks(char *line, char *delim)
{
	int length = 0;
	int capacity = 16;
	char **tokens = malloc(capacity * sizeof(char *));
	char *token = strtok(line, delim);

	while (token != NULL)
	{
        if (token != NULL)
        {
    		tokens[length] = token;
	    	length++;
	    	token = strtok(NULL, delim);
        }
	}
	tokens[length] = NULL;
	return (tokens);
}

/**
 * _execute - creates child process and executes
 * @args : argument vector from command line
 */

int _execute(char **args) 
{
    // Execute external program
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        return (-1);
    } else if (child_pid == 0) {
        // Child process
        execve(args[0], args, NULL);
        perror("execve");
        exit(1);
    } else {
        // Parent process
        wait(NULL);
    }
    return (0);
}


void change_to_home_directory(void)
{
    uid_t uid = get_uid();
    struct passwd *pw = getpwuid(uid);
    if (pw == NULL) {
        // Failed to get user information
        perror("getpwuid");
        return;
    }
    
    if (chdir(pw->pw_dir) != 0) {
        // Failed to change directory
        perror("chdir");
    }
}

uid_t get_uid(void)
{
    const char *self_path = "/proc/self";
    struct stat st;

    if (stat(self_path, &st) == -1) {
        perror("stat");
        return -1;
    }

    return st.st_uid;
}
