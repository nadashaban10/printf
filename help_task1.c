#include "main.h"
/**
 * convert_size_digit - functio to make digit in fixed size
 * @number:number to convert
 * @size:size that want to be
 * Return:fixed size
 * develop by soria
 */

long int convert_size_digit(long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((short)number);

	return ((int)number);
}

/**
 *convert_size_digit_unsigned - casting numbers and specify
 *@number: number will cast
 *@size_digit: the indicition type to cast
 *Return: casted number
 */
long int convert_size_digit_unsigned(unsigned long int number, int size_digit)
{
	if (size_digit == S_LONG)
		return (number);
	else if (size_digit == S_SHORT)
		return ((unsigned short)number);
	return ((unsigned int)number);
}
