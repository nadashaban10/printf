#include "main.h"
/**
 * handle_fun_print - print our argu
 * @forma:this is format
 * @cases:list of argu
 * @index:int
 * @buffer:an array
 * @f:flages
 * @w:width
 * @p:precision
 * @s:size
 * Return:one or two
 * developed by soria
 */
int handle_fun_print(const char *forma, int *index, va_list cases,
		char buffer[], int f, int w, int p, int s)
{
	int x, u_len = 0, p_char = -1;
	fomt_t fomt_types[] = {
		{'c', char_func}, {'s', string_func}, {'%', percentage_func},
		{'i', print_i}, {'d', print_i}
	};
	for (x = 0 ; fomt_types[x].fomt != '\0' ; x++)
		if (fomt[*index] == fomt_types[x].fomt)
			return (fomt_types[x].fun(cases, buffer, f, w, p, s));
	if (fomt_types[x].fomt == '\0')
	{
		if (fomt[*index] == '\0')
			return (-1);
		u_len += write(1, "%%", 1);
		if (fomt[*index - 1] == ' ')
			u_len += write(1, ' ', 1);
		else if (w)
		{
			--(*index);
			while (fomt[*index] != ' ' && fomt[*index] != '%')
				--(*index);
			if (fomt[*index] == ' ')
				--(*index);
			return (1);
		}
		u_len += write(1, &fomt[*index], 1);
		return (u_len);
	}
	return (p_char);
}
