#include "main.h"
/**
 *g_precision - get percisions of string
 *@formats: string in argu
 *@x: list printed
 *@cases: list of argu
 *Return: precision
 */
int g_precision(const char *formats, int *x, va_list cases)
{
	int current_i = *x + 1;
	int precision = -1;

	if (formats[current_i] != '.')
		return (precision);
	precision = 0;
	for (current_i = current_i + 1; formats[current_i] != '\0'; current_i++)
	{
		if (is_fun_digit(formats[current_i]))
		{
			precision *= 10;
			precision += formats[current_i] - '0';
		}
		else if (formats[current_i] == '*')
		{
			current_i++;
			precision = va_arg(cases, int);
			break;
		}
		else
			break;
	}

	*x = current_i - 1;
	return (precision);
}
