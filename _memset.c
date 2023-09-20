#include "main.h"

/**
 * _memset - Set the memory pointed to by s to the value of c for n bytes
 * @s: Pointer to the memory to set
 * @c: Value to set
 * @n: Number of bytes to set
 *
 * Return: Pointer to the memory area s
 */

void *_memset(void *s, int c, size_t n)
{
	unsigned char *p = (unsigned char *)s;
	unsigned char value = (unsigned char)c;

	while (n-- > 0)
		*p++ = value;

	return (s);
}
