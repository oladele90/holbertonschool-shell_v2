#include "shell.h"

int handle_builtins(char **args)
{
    extern char **environ;

    if (_strcmp(args[0], "cd") == 0)
    {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));

        // Handle 'cd' command
        if (args[1] == NULL)
        {
            change_to_home_directory();
            prewd = cwd;
            printf("%s\n", prewd);
            return (1);
        }
        else if (_strcmp(args[1], "-") == 0)
        {
            change_to_previous_directory();
            prewd = cwd;
            printf("%s\n", prewd);
            return 1;
        }
        // Change to the specified directory
        else if (chdir(args[1]) != 0)
        {
            perror("chdir");
            return 1;
        }
        prewd = cwd;
        printf("%s\n", prewd);
        return 1;
    }
    else if (_strcmp(args[0], "env") == 0)
    {
        // Handle 'env' command
        char **env = environ;
        while (*env != NULL)
        {
            printf("%s\n", *env);
            env++;
        }
        return 1;
    }
    else if (_strcmp(args[0], "exit") == 0)
    {
        exit(0);
    }

    return 0;
}

void update_env(char *new, char *var)
{
    char *new_var;
    extern char **environ;

    // Create a new string with the format "PWD=new"
    size_t new_len = _strlen(var) + _strlen(new) + 1;
    new_var = malloc(new_len);
    sprintf(new_var, "%s%s", var, new);

    // Find the existing "PWD=" environment variable and update it
    for (int i = 0; environ[i] != NULL; i++) {
        if (strncmp(environ[i], var, _strlen(var)) == 0) {
            free(environ[i]);  // Free the old string
            environ[i] = new_var;  // Assign the new string
            return;
        }
    }
}

void change_to_previous_directory(void)
{
    if (prewd != NULL)
    {
        printf("%s\n", prewd);
        if (chdir(prewd) != 0)
        {
            perror("chdir");
            return;
        }
    }
    else
    {
        printf("No previous working directory available.\n");
    }
}








