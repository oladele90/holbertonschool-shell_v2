#include "shell.h"

/**
 * main - opens shell and runs basic commands
 * @ac : argument count
 * @av : argument vector
 *Return: 0 on success
 */

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	/*list_t *h = NULL;*/
	 /*
	  *PATH = get_path(name);
	  * printf("got path string: %s \n", PATH);
	  *h = make_p_list(PATH, h);
	  */

	char *l_s;/*, *PATH, *name = "PATH="*/
	char **split_toks;
	int stdin_fd = dup(STDIN_FILENO);

	while (1)
	{
		l_s = _getline(stdin_fd);
		split_toks = _split_toks(l_s);
		if (split_toks[0] != NULL)
			_execute(split_toks);
		free(split_toks);
		free(l_s);
		l_s = NULL;
	}
}
