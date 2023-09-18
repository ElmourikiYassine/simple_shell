#include "main.h"

/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string to be appended to dest.
 * Return: A pointer to the resulting string dest.
 */
char *_strcat(char *dest, const char *src)
{
	char *d = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (d);
}

/**
 * _strdup - Duplicate a string in memory.
 * @str: The input string.
 * Return: A pointer to the duplicated string,
 * or NULL if memory allocation fails.
 */
char *_strdup(const char *str)
{
	int length;
	char *duplicate;

	if (str == NULL)
		return (NULL);
	length = _strlen(str);
	duplicate = (char *)malloc(length + 1);
	if (duplicate == NULL)
		return (NULL);
	_strcpy(duplicate, str);
	return (duplicate);
}

/**
 * _atoi - Convert a string to an integer.
 * @s: The string to convert.
 * Return: The integer value represented by the string,
 * or 0 if conversion fails.
 */

int _atoi(const char *s)
{
	int result = 0;
	int sign = 1;

	/* Handle leading white spaces */
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;

	/* Handle the sign */
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}

	/* Convert the string to an integer */
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}

	return (result * sign);
}
/**
 * _strpbrk - Locate the first occurrence of any character in a set.
 * @str: The string to search.
 * @accept: The set of characters to search for.
 * Return: A pointer to the first matching character,
 * or NULL if none are found.
 */
char *_strpbrk(const char *str, const char *accept)
{
	while (*str)
	{
		const char *ch = accept;

		while (*ch)
		{
			if (*ch == *str)
			{
				return ((char *)str);
			}
			ch++;
		}
		str++;
	}
	return (NULL);
}

/**
 * _strtok - Split a string into tokens.
 * @str: The string to be split.
 * @delim: The delimiter used to split the string.
 * Return: A pointer to the next token, or NULL if there are no more tokens.
 */
char *_strtok(char *str, const char *delim)
{
	static char *next_token;
	char *token_start;

	if (str != NULL)
		next_token = str;

	if (next_token == NULL || *next_token == '\0')
		return (NULL);

	while (*next_token && _strchr(delim, *next_token))
		next_token++;

	if (*next_token == '\0')
		return (NULL);

	token_start = next_token;

	while (*next_token && !_strchr(delim, *next_token))
		next_token++;

	if (*next_token)
	{
		*next_token = '\0';
		next_token++;
	}
	else
		next_token = NULL;

	return (token_start);
}

