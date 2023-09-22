#include "main.h"
/**
 *_printf - function that print anything
 *@format: constant input format
 *Return: ind_printed_c
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == 'c')
				count += printChar(args);
			else if (*format == 's')
				count += printStringSpecifier(args);
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				count += printInt(num);
			}
			else if (*format == '%')
			{
				count += printPercent();
			}
			else if (*format == 'b')
				count += printbinary(args);
		}
		format++;
	}
	va_end(args);

	return (count);
}
