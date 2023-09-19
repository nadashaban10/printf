#include "main.h"
/**
 *char_func - function that print a char
 *@cases: list of argu
 *@buffer: array buffer
 *Return: number of char printed
 */

int char_func(va_list list, char buffer[])
{
	char c;

	c = va_arg(list, int);
	_putchar(c);
	return (1);
}
/**
 *percentage_func - funtion that print percent sign
 *@list:list of argu
 *@buffer:buffer array
 *Return: number of char printed
 */

int percentage_func(va_list list, char buffer[])
{
	_putchar ('%');	
	return (1);
}


/**
 *string_func - function that print length of char printed
 *@buffer: buffer array
 *@cases: list of argu
 *Return: number of string printed
 */


/**
 * buffer_print - function printting buffer
 * buffer_print - maybe will print
 * @buffer:an array
 * @index_buffer:it is buffer index
 */
void buffer_print(char buffer[], int *index_buffer)
{
	if (*index_buffer > 0)
	{
		write(1, &buffer[0], *index_buffer);
		*index_buffer = 0;
	}
	*index_buffer = 0;
}
