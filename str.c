#include "main.h"

/* File: str.c
*Authors: Azizi Nyawa
* Ronald
*/
/**
 * _strlen - returns the len of a str
 * @s: the str whose len to check
 *
 * Return: int length of str
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparing of two strangs.
 * @s1: the first strang encounted
 * @s2: the second strang encounted
 *
 * Return: negative if s1 < s2 and positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks the needle starts with the haystack
 * @haystack: str to search
 * @needle: the substring to be found
 *
 * Return: address of next character of haystack or the NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two str
 * @dest: the destination buffer to be connected
 * @src: the source buffer of the str
 *
 * Return: pointer to dest buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
