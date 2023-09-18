#include "main.h"
/**
 * get_w - get width.
 * @format:string to format
 * @x:list of argu
 * @arr:list of argu
 * Return:get width fun
 * developed by soria
 */

int get_w(const char *format, int *x, va_list arr)
{
	int cc;
	int s_width = 0;

	for (cc = *x + 1 ; format[cc] != '\0' ; cc++)
	{
		if (is_fun_digit(format[cc]))
		{
			s_width *= 10;
			s_width += format[cc] - '0';
		}
		else if (format[cc] == '*')
		{
			cc++, s_width = va_arg(arr, int);
			break;
		}
		else
			break;
	}
	*x = cc - 1;

	return (s_width);
}
