#include "main.h"

/**
 * _realloc - Reallocate memory for a pointer with a new size
 * @ptr: Pointer to the memory to reallocate
 * @size: New size of the memory
 *
 * Return: Pointer to the reallocated memory
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	size_t copy_size;
	char *d;
	const char *s;

	if (size == 0)
	{
		free(ptr);
		return NULL;
	}

	if (ptr == NULL)
		return malloc(size);

	new_ptr = malloc(size);

	if (new_ptr == NULL)
		return NULL;

	copy_size = size;

	if (copy_size > sizeof(ptr))
		copy_size = sizeof(ptr);

	d = (char *)new_ptr;
	s = (const char *)ptr;

	while (copy_size--)
		*d++ = *s++;

	free(ptr);

	return (new_ptr);
}
