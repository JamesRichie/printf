#include "main.h"

/**
 * _printf - Prints to stdout
 * @format: Format specifier
 *
 * Return: No of bytes printed
 */

int _printf(const char *format, ...)
{
	unsigned int x, string_count, count = 0, binary;

	va_list args;

	va_start(args, format);

	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] != '%')
			_putchar(format[x]);

		else if (format[x] == '%' && format[x + 1] == 'c')
		{
			_putchar(va_arg(args, int));
			x++;

		}
		else if (format[x + 1] == 's')
		{
			string_count = _puts(va_arg(args, char *));
			x++;
			count += (string_count - 1);

		}
		else if (format[x + 1] == '%')
		{
			_putchar('%');
		}
		else if (format[x] == 'b')
		{
			binary = print_binary( unsigned int n);
			return (binary);
		}
		count += 1;
	}
	return (count);
}
