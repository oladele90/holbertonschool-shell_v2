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
            update_env(cwd, "OLDPWD", &environ);
            return (1);
        }
        else if (_strcmp(args[1], "-") == 0)
        {
            change_to_previous_directory();
            return (1);
        }
        // Change to the specified directory
        else if (chdir(args[1]) != 0)
        {
            perror("chdir");
            return 1;
        }
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

void update_env(char *new, char *var, char ***environ)
{
    char *new_var;
    //extern char **environ;
    char **env = *environ;

    // Create a new string with the format "PWD=new"
    size_t new_len = _strlen(var) + _strlen(new) + 2;
    new_var = malloc(new_len);
    sprintf(new_var, "%s=%s", var, new);

    // Find the existing "PWD=" environment variable and update it
    for (int i = 0; env[i] != NULL; i++) {
        if (strncmp(env[i], var, _strlen(var)) == 0) {
            if (env[i] != NULL)
            {
                free(env[i]);  // Free the old string
                env[i] = NULL;
            }
            env[i] = _strdup(new_var);  // Assign the new string
            free(new_var);
            return;
        }
    }
}

void change_to_previous_directory(void)
{
    char *previous_directory;

    previous_directory = _getenv("OLDPWD=");  // Get the value of the OLDPWD environment variable
    if (previous_directory != NULL)
    {
        if (chdir(previous_directory) == -1)
        {  // Change to the previous directory using chdir
            perror("chdir");
        }
    }
    else
    {
        printf("No previous directory available\n");
    }
}

char *_getenv(char *pathy)
{
    extern char **environ;
    int i = 0, pathlen;

    pathlen = _strlen(pathy);
    while (environ[i])
    {
        if (_strncmp(pathy, environ[i], pathlen) == 1)
            return (environ[i] + pathlen);
        i++;    
    }
    return (NULL);
}






