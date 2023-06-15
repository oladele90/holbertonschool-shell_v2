#include "shell.h"

/**
 * _strcmp - compare 2 strings
 *@s1: ponter to string that should be compared
 *@s2: ponter to string that should be compared
 * Return: Always 0.
 */


int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i]) && (s2[i]))
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}