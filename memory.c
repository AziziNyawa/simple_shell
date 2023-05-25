#include "main.h"

/* File: memory.c
*Authors: Azizi Nyawa
* Ronald
*/

/**
 * bfree - frees a pointer and NULLs
 * @ptr: address of the pointer
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
