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

	if (!s1 || !s2)
		return (0);
	while ((s1[i]) && (s2[i]))
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (1);
	}
	return (0);
}

/**
 * _strncmp - compares strings up to n chars
 * @str1: first string
 * @str2: second string
 * @index: number of characters
 * Return: 0
 */
int _strncmp(char *str1, char *str2, int index)
{
	int i = 0;

	while (str1[i] && str2[i] && (i < index))
	{
		if (str1[i] == str2[i])
		{
			i++;
			continue;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

char *_strdup(char *str, char *new_str)
{
	int i = 0;
	int index = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		i++;
		index++;
	}
	index++;

	new_str = malloc(index * sizeof(char));
	if (new_str == NULL)
	{
		return (NULL);
	}

	for (i = 0 ; i < index ; i++)
	{
		new_str[i] = str[i];
	}

	return (new_str);
}

/**
 *_strlen - string to be counted
 *@s: character in string
 * Return: Always 0.
 */

int _strlen(char *s)
{
	int counter = 0;

	while (*s != '\0')
	{
		counter++;
		s++;
	}
	return (counter);
}

/**
 * _memcpy - copy n bytes from src to dest
 * @src: the address of memory to print
 * @n: the size of the memory to print
 * @dest:memory to copy to
 * Return: dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}