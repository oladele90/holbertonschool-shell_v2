#include "shell.h"

char *_strcpy(char *destination, char *source) {
    char *original_destination = destination;

    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0'; // Append null character at the end

    return original_destination;
}

/**
 * _strcat - concatenate two strings
 *@dest: ponter to string that should be returned
 *@src: ponter to string to be appended to dest
 * Return: Always 0.
 */

char *_strcat(char *dest, char *src)
{
	int len1 = 0, len2 = 0, i;

	while (*(dest + len1))
	{
		len1++;
	}
	while (*(src + len2))
	{
		len2++;
	}
	for (i = 0; i <= len2; i++)
	{
		dest[len1++] = src[i];
	}
	return (dest);
}