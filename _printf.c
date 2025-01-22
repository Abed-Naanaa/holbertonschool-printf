#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_char - Prints a single character
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
		str = "(null)";
	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}

/**
 * _printf - Produces output according to a format
 * @format: Format string containing characters and specifiers
 *
 * Return: The number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count += print_char(args);
			else if (*format == 's')
				count += print_string(args);
			else if (*format == '%')
				count += write(1, "%", 1);
			else
				return (-1);
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}
