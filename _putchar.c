#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c, int *buff_ind)
{
	printf("%c", c);
	return (write(1, c, *buff_ind));
}

/**
 * _puts - prints a string with newline
 * @str: the string to print
 *
 * Return:( str-a)
 */
void _puts(char *buffer, int *buff_ind)
{
	int i = 0;

	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}

