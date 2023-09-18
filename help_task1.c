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
