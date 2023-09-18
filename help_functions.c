#include "main.h"
/**
 *is_print - evaluates char if its printable
 *@c: char input
 *Return: 1 if is printable, and 0 if else
 */
int is_print(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 *hexa_num - append ascii to hexadecimal
 *@buffer: array
 *@asc_code: ascii code values
 *@x: starting index
 *Return: (3)
 */
int hexa_num(char asc_code, char buffer[], int x)
{
	char to_code[] = "0123456789ABCDEF";

	if (asc_code < 0)
		asc_code = asc_code * -1;
	buffer[x++] = '\\';
	buffer[x++] = 'x';
	buffer[x++] = to_code[asc_code / 16];
	buffer[x++] = to_code[asc_code % 16];
	return (3);
}
