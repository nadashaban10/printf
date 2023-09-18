#include "main.h"

/**
 *buffer_print - funtion that print the array
 *@buffer:  buffer array
 *@index_buffer: index to calculate the buffer
 */

void buffer_print(char buffer[], int *index_buffer);

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
	int ind_printed_c;
	va_list list;

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
				ind_printed_c++;
			}
			else
			{
				buffer_print(buffer, &index_buffer);
				va_end(list);
			}
		}
		return (ind_printed_c);
	}
}
