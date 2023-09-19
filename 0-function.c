#include "main.h"
/**
 *char_func - function that print a char
 *@cases: list of argu
 *@buffer: array buffer
 *@flag: get num of flags
 *@s_width: calculate width
 *@precision: precision specify
 *@s_size: size specefires
 *Return: number of char printed
 */


int char_func(va_list cases, char buffer[], int flag,
		int s_width, int precision, int s_size)
{
	char c;

	c = va_arg(cases, int);

	return (write_char_(c, buffer, flag, s_width, precision, s_size));
}

/**
 *percentage_func - funtion that print percent sign
 *@cases:list of argu
 *@buffer:buffer array
 *@flag: get num of flags
 *@s_width: calculate width
 *@precision: precision specify
 *@s_size: size specefires
 *Return: number of char printed
 */

int percentage_func(va_list cases, char buffer[],
		int flag, int s_width, int precision, int s_size)
{
	UNUSED(cases);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(s_width);
	UNUSED(precision);
	UNUSED(s_size);
	return (write(1, "%%", 1));
}


/**
*string_func - function that print length of char printed
*@buffer: buffer array
*@cases: list of argu
 *@flag: get num of flags
 *@s_width: calculate width
 *@precision: precision specify
 *@s_size: size specefires
*Return: number of string printed
*/

int string_func(va_list cases, char buffer[],
		int flag, int s_width, int precision, int s_size)
{
int leng, index;
char *string;

leng = 0;
string = va_arg(cases, char *);
UNUSED(buffer);
UNUSED(flag);
UNUSED(s_width);
UNUSED(precision);
UNUSED(s_size);
if (string == NULL)
{
	string = "(nill)";
	if (precision >= 6)
	string = "      ";
}
while (string[leng] != '\0')
	leng++;
if (precision >= 0 && precision < leng)
	leng = precision;
	if (s_width > leng)
{
	if (flag & F_MINUS)
	{
	write(1, &string[0], leng);
	for (index = s_width - leng; index > 0; index--)
		write(1, " ", 1);
	return (s_width);
	}
	else
	{
	for (index = s_width - leng; index > 0; index--)
		write(1, " ", 1);
	write(1, &string[0], leng);
	return (s_width);
	}
}
	return (write(1, string, leng));
}
