#include "shell.h"

/**
 * main - opens shell and runs basic commands
 * @ac : argument count
 * @av : argument vector
 *Return: 0 on success
 */
char *prewd = NULL;

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
    char *line;
    char **argarr;
    int builtin_flag;

    while (1)
    {
        builtin_flag = 0;
        line = _getline();
        argarr = _split_toks(line, " \n");
        builtin_flag = handle_builtins(argarr);
        if ((argarr[0] != NULL) && (builtin_flag != 1))
            _execute(argarr);
        free(argarr);
        free(line);
        line = NULL;
    }
        
}
