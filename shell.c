#include "shell.h"

/**
 * main - opens shell and runs basic commands
 * @ac : argument count
 * @av : argument vector
 *Return: 0 on success
 */

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)), char **envp)
{
    char *line;
    char **argarr;
    int builtin_flag;
    static char **envp_copy = NULL;
    size_t env_count = 0;
    size_t copy_pos = 0;
    while (envp[env_count] != NULL)
    {
        env_count++;
    }
    envp_copy = malloc((env_count + 1) * sizeof(char *));
    for (copy_pos = 0; copy_pos < env_count; copy_pos++)
    {
        envp_copy[copy_pos] = _strdup(envp[copy_pos]);
    }
    envp_copy[copy_pos] = NULL;
    int i = 0;
    while (envp_copy[i] != NULL)
    {
        printf("%s\n", envp_copy[i]);
        i++;
    }
    while (1)
    {
        builtin_flag = 0;
        line = _getline();
        argarr = _split_toks(line, " \n");
        builtin_flag = handle_builtins(argarr, envp_copy);
        if ((argarr[0] != NULL) && (builtin_flag != 1))
            _execute(argarr);
        free(argarr);
        free(line);
        line = NULL;
    }
}
