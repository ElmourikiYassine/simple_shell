#include "main.h"

/**
 * _strlen - Calculate the length of a string.
 * @s: The string to calculate the length of.
 * Return: The length of the string.
 */
int _strlen(const char *s)
{
	int count = 0;

	while (s[count] != '\0')
		count++;
	return (count);
}

/**
 * _strcmp - Compare two strings.
 * @s1: The first string.
 * @s2: The second string.
 * Return: 0 if s1 and s2 are equal, a positive value if s1 > s2, and
 * a negative value if s1 < s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strcpy - Copy a string.
 * @dest: The destination string.
 * @src: The source string to be copied.
 * Return: A pointer to the destination string.
 */
char *_strcpy(char *dest, const char *src)
{
	char *d = dest;

	while ((*dest++ = *src++))
		;
	return (d);
}

/**
 * _strstr - Locate a substring in a string.
 * @haystack: The string to search in.
 * @needle: The substring to search for.
 * Return: A pointer to the beginning of the substring, or NULL if not found.
 */
char *_strstr(const char *haystack, const char *needle)
{
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
	}
	return (NULL);
}

/**
 * _strchr - Locate a character in a string.
 * @s: Pointer to the string to search in.
 * @c: The character to search for.
 * Return: A pointer to the first occurrence of c in s, or NULL if not found.
 */
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

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

