#include "main.h"
/**
 *_printf - function that print anything
 *@format: constant input format
 *Return: ind_printed_c
 */
int _printf(const char *format, ...)
{
	int i;
	int index_buffer = 0;
	int ind_printed;
	int ind_printed_c = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[index_buffer++] = format[i];
			if (index_buffer == BUFF_SIZE)
			{
				buffer_print(buffer, &index_buffer);
				ind_printed_c += index_buffer;
			}
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				char c = va_arg(list, int);
				ind_printed_c += char_func(c, buffer, &index_buffer);
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(list, char *);
				ind_printed_c += string_func(str, buffer, &index_buffer);
			}
			else if (format[i] == '%')
			{
				ind_printed_c += percentage_func(buffer, &index);
			}
		}
	}
	buffer_print(buffer, &index_buffer);
	va_end(list);
	return (ind_printed_c);
}
