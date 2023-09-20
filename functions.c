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

/**
 *printInt - print integer
 *@num: input
 *Return: value
 */
int printInt(int num)
{
	int x = 0;
	int z = num;
	int rev = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	if (num < 0)
	{
		_putchar('-');
		x++;
		z = -z;
	}
	while (z > 0)
	{
		rev = rev * 10 + z % 10;
		z /= 10;
	}
	while (rev > 0)
	{
		_putchar(rev % 10 + '0');
		rev /= 10;
		x++;
	}
	return (x);
}
