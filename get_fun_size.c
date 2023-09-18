#include "main.h"
/**
 * get_s - get size of argu
 * @format:string of format
 * @x:list of argu
 * Return:size.
 */

int get_s(const char *format, int *x)
{
	int cc = *x + 1;
	int s_size = 0;

	if (format[cc] == 'l')
		s_size = S_LONG;
	else if (format[cc] == 'h')
		s_size = S_SHORT;

	if (s_size == 0)
		*x = cc - 1;
	else
		*x = cc;

	return (s_size);
}
