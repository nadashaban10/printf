#include "main.h"

/**
 *
 *
 *
 *
 */
int _printf(const char *format, ...)
{
int i;
int ind_printed;
int ind_printed_c;
va_list list;

if (format == NULL)
	return (-1);

va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
	if (format[i] != '%')
	{
		buffer[index_buffer] = format[i];
		if (index_buffer == BUFF_SIZE)
		{
		buffer_print(buffer, &index_buffer);
		ind_printed_c++;
		}
		else 
		{
		buffer_print(buffer, &index_buffer);
		va_end(list);
		}
		return (ind_printed_c)
	}
}
