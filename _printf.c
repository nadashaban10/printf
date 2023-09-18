#include "main.h"

/**
 *buffer_print - funtion that print the array
 *@buffer:  buffer array
 *@index_buffer: index to calculate the buffer
 */

void buffer_print(char buffer[], int *index_buffer)
{
	if (*index_buffer > 0)
		write(1, &buffer[0], *index_buffer);
	*index_buffer = 0;  /*i think its zero to free the memory */


}

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
		}
		return (ind_printed_c);
	}
<<<<<<< HEAD
=======

>>>>>>> f4bdff1ab6602ea884e36f5d5a6ccb351b999f51
}
