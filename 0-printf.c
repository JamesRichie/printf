#include "main.h"
#include <stdarg.h>

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int x, print = 0, print_char = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buff_ind++] = format[x];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/*write(1, &format[x], 1);*/
			print_char++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &x);
			width = get_width(format, &x, list);
			precision = get_precision(format, &x, list);
			size = get_size(format, &x);
			x++;
			print = handle_print(format, &x, list, buffer,
					flags, width, precision, size);
			
			if (print == -1)
				return (-1);
			print_char += print;
		}
	}
	print_buffer(buffer, &buff_ind);

	va_end(list);
	return (print_char);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of char
 * @buff_ind: Index at whichto add next char, represents the length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
