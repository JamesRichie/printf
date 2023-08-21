#include "main.h"

/**
 * _printf - Prints an input
 * @format: Input to be printed
 *
 * Return: Output
 */
_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
			format++;

		if (*format == 'd')
		{
			int num = va_arg(args, int);
			int bits = sizeof(num) * 8;

			for (int i = bits - 1; i >= 0; i--)
			{
				_printf("%d", (num >> i) & 1);
			}
		}
		else
		{
			_putchar(*format);
		}
	}
	else
	{
		_putchar(*format);
	}
	va_end(args);
}
