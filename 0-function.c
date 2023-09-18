#include "main.h"
/**
 *char_func - function that print a char
 *@cases: list of argu
 *@buffer: array buffer
 *Return: number of char printed
 */


int char_func(va_list cases, char buffer[])
{
	char c;

	c = va_arg(cases, int);
	return (write_char_(c, buffer));
}

/**
 *percentage_func - funtion that print percent sign
 *@cases:list of argu
 *@buffer:buffer array
 *Return: number of char printed
 */

int percentage_func(va_list cases, char buffer[])
{
	
	return (write(1, "%%", 1));
}


/**
*string_func - function that print length of char printed
*@buffer: buffer array
*@cases: list of argu
*Return: number of char printed
*/

int string_func(va_list cases, char buffer[])
{
int leng;
char *str;

leng = 0;
str = va_arg(cases, char *);

while (str[leng] != '\0')
	leng++;

return (write(1, str, leng));
}
