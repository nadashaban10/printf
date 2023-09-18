#include "main.h"
/**
 * print_i - function to print d and i format
 * @cases:our number
 * @buffer:buffer array.
 * @f:this a flage
 * @w:width
 * @p:precision
 * @s:size
 * Return:how to print d or i
 */
int print_i(va_list cases, char buffer[], int f, int w, int p, int s)
{
	int x = BUFF_SIZE - 2;
	int is_neg = 0;/* is negative variable */
	long int n = va_arg(cases, long int);
	unsigned long int number;

	n = convert_size_number(n, s);

	if (n == 0)
		buffer[x--] = '\0';
	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)n;
	if (n < 0)
	{
		number = (unsigned long int)((-1) * n);
		is_neg = 1;
	}
	while (n > 0)
	{
		buffer[x--] = (number % 10) + '0';
		number / 10;
	}
	x++;
	return (write_digit(is_neg, x, buffer, f, w, p, s));
}
