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
