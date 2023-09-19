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
	int flag;
	int s_width;
	int precision;
	int s_size;
	char buffer [BUFF_SIZE];


	if (format == NULL)
		return (-1);

	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[index_buffer++] = format[i];
			if (index_buffer == BUFF_SIZE)

				buffer_print(buffer, &index_buffer);
			ind_printed_c++;

				ind_printed_c++;
		}
		else
		{
			buffer_print(buffer, &index_buffer);
			flag = g_flag(format, &i);
			s_width = get_w(format, &i, list);
			precision = g_precision(format, &i, list);
			s_size = get_s(format, &i);
			i++;
			ind_printed = handle_fun_print(format, &i, list, buffer, flag, s_width,
					precision, s_size);
			if (ind_printed == -1)
				return (-1);
			ind_printed_c = ind_printed_c + ind_printed;
			i++;
			ind_printed = handle_fun_print(format, &i, list, buffer, flag, s_width, 
					precision, s_size);
			if (ind_printed == -1)
			{
				return (-1);
				ind_printed_c = ind_printed_c + ind_printed;

				i++;
				ind_printed = handle_fun_print(format, &i, list, buffer, flag, s_width, 
						precision, s_size);
					if (ind_printed == -1)
						return (-1);
					ind_printed_c = ind_printed_c + ind_printed;
			}	
		}
	
		buffer_print(buffer, &index_buffer);

		va_end(list);

	}

		return (ind_printed_c);
}
/**
 *
 *
 *
 *
 */

void buffer_print(char buffer, int &index_buffer)
{
	if (*index_buffer > 0)
		write(1, &buffer[0], *index_buffer);

	*index_buffer = 0;
}
