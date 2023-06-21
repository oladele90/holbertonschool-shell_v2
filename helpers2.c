#include "shell.h"

int handle_builtins(char **args, char **envp_copy)
{
    int i = 0;

    if (_strcmp(args[0], "cd") == 0)
    {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        char newcwd[1024];
        // Handle 'cd' command
        if (args[1] == NULL)
        {
            change_to_home_directory();
            update_env(cwd, "OLDPWD", envp_copy);
            return (1);
        }
        else if (_strcmp(args[1], "-") == 0)
        {
            change_to_previous_directory(envp_copy);
            update_env(cwd, "OLDPWD", envp_copy);
            return (1);
        }
        // Change to the specified directory
        else if (chdir(args[1]) != 0)
        {
            perror("chdir");
            return 1;
        }
        getcwd(newcwd, sizeof(newcwd));
        if (_strcmp(cwd, newcwd) == 0)
            update_env(cwd, "OLDPWD", envp_copy);

        return 1;
    }
    else if (_strcmp(args[0], "env") == 0)
    {
        int j;
        // Handle 'env' command
        while (envp_copy[i] != NULL)
        {
            printf("%s\n", envp_copy[i]);
            i++;
        }
        for (j = 0; envp_copy[j] != NULL; j++)
            {
                free(envp_copy[j]);
                envp_copy[j] = NULL;
            }
        free(envp_copy);
        return 1;
    }
    else if ((_strcmp(args[0], "exit") == 0) || args[0][0] == EOF)
    {
        int j;
        if(envp_copy)
        {
            for (j = 0; envp_copy[j] != NULL; j++)
            {
                free(envp_copy[j]);
                envp_copy[j] = NULL;
            }
            for (j = 0; args[j] != NULL; j++)
                free(args[j]);

            free(envp_copy);
            free(args);
        }
        exit(0);
    }

    return 0;
}

void update_env(char *new, char *var, char **envp_copy)
{

    // Create a new string with the format "PWD=new"
    char *new_var;
    size_t new_len = _strlen(var) + _strlen(new) + 2;
    new_var = malloc(new_len);
    sprintf(new_var, "%s=%s", var, new);

    // Find the existing "PWD=" environment variable and update it
    for (int i = 0; envp_copy[i] != NULL; i++) {
        if (_strncmp(envp_copy[i], var, _strlen(var)) == 0) {
            if (envp_copy[i] != NULL)
            {
                free(envp_copy[i]);  // Free the old string
                envp_copy[i] = NULL;
            }
            envp_copy[i] = _strdup(new_var, envp_copy[i]);  // Assign the new string
            free(new_var);
            return;
        }
    }
}

void change_to_previous_directory(char **envp_copy)
{
    char *previous_directory;

    previous_directory = _getenv("OLDPWD=", envp_copy);  // Get the value of the OLDPWD environment variable
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

char *_getenv(char *pathy, char **envp_copy)
{
    int i = 0, pathlen;

    pathlen = _strlen(pathy);
    while (envp_copy[i])
    {
        if (_strncmp(pathy, envp_copy[i], pathlen) == 1)
            return (envp_copy[i] + pathlen);
        i++;    
    }
    return (NULL);
}
