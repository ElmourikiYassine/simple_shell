#include "main.h"
/**
 * _strlen - Concatenates src to dest.
 * @s: The maximum number of bytes to be copied from src.
 * Return: A pointer to the resulting string dest.
 */
int _strlen(char *s)
{
	int count, inc;

	inc = 0;
	for (count = 0; s[count] != '\0'; count++)
		inc++;
	return (inc);
}

/**
 * _strcmp - Concatenates src to dest.
 * @s1: The maximum number of bytes to be copied from src.
 * @s2: The maximum number of bytes to be copied from src.
 * Return: A pointer to the resulting string dest.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, diff = 0;

	while (1)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			break;
		else if (s1[i] == '\0')
		{
			diff = s2[i];
			break;
		}
		else if (s2[i] == '\0')
		{
			diff = s1[i];
			break;
		}
		else if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			break;
		}
		else
			i++;
	}
	return (diff);
}

/**
 * _strcpy - <--TODO-->
 * @dest: <--TODO-->
 * @src: <--TODO-->
 * Return: <--TODO-->
 */
char *_strcpy(char *dest, char *src)
{
	int inc = 0;

	while (*(src + inc) != '\0')
	{
		*(dest + inc) = *(src + inc);
		inc++;
	}
	*(dest + inc) = '\0';
	return (dest);
}

/**
 * _strstr - locate a substring
 * @haystack: the string that will search in
 * @needle: the string we search for
 * Return:	A pointer to the beginning of the substring
 * or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (!needle[j])
			return (&haystack[i]);
	}
	return (NULL);
}

/**
 * _strchr - locate a character in a string
 * @s: pointer to the string to search in
 * @c: char to search for
 * Return: A pointer to the characters or NULL
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}

	if (*s == c)
	{
		return (s);
	}

	return (NULL);
}

/**
 * _strcat - Concatenates src to dest.
 * @dest: The destination string.
 * @src: The source string to be appended tp dest.
 * Return: A pointer to the resulting string dest.
 */

char *_strcat(char *dest, char *src)
{
	char *dest_end = dest;

	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_end);
}

/**
 * _strdup - this is function to return a pointer to allocated space in memory.
 * @str: the input strings
 * Return: The pointer to the duplicated String
 */

char *_strdup(char *str)
{
	unsigned int length = 0;
	unsigned int i = 0;
	char *duplicate;

	if (str == NULL)
		return (NULL);

	while (str[length] != '\0')
		length++;

	duplicate = malloc((length + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];

	return (duplicate);
}
