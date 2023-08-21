#include "main.h"

/**
 * _puts - Prints string
 *
 * @c: String
 * Return:number of bye
 */
int _puts(char *c)
{
	int count = 0;

	if (c)
	{
		for (; c[count] != '\0'; count++)
		{
			_putchar(c[count]);
		}

	}
	return (count);
}
