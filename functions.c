#include "main.h"
/**
 *printChar - print char
 *@args: argument
 *Return: value
 */
int printChar(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 *printString - print string
 *@str: argument
 *Return: value
 */

int printString(const char *str)
{
	int i = 0;

	if (str)
	{
		while (*str)
		{
			_putchar(*str);
			str++;
			i++;
		}
	}
	else
	{
		const char *nullStr = "(null)";

		while (*nullStr)
		{
			_putchar(*nullStr);
			nullStr++;
			i++;
		}
	}

	return (i);
}

/**
 *printStringSpecifier - print str
 *@args: argument
 *Return: value
 */
int printStringSpecifier(va_list args)
{
	char *str = va_arg(args, char *);

	return (printString(str));
}

/**
 *printPercent - print percent
 *Return: (1)
 */
int printPercent(void)
{
	_putchar('%');
	return (1);
}
