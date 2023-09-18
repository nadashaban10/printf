#include "main.h"
/* write number */
/**
 * write_digit - function print digits
 * @is_negative:check if number is -.
 * @index:charachter
 * @buffer:an array
 * @f:flages
 * @w:width
 * @p:precision
 * @s:size
 * Return:number that we print.
 */
int write_digit(int is_negative, int index, char buffer[],
	       int f, int w, int p, int s)
{
	int len = BUFF_SIZE - index - 1;
	char pading = '', ext_ch = 0;

	UNUSED(s);

	if ((f & F_ZERO) && !(f && F_MINUS))
		pading = '0';
	if (is_negative)
		ext_ch = '-';
	else if (f & F_PLUS)
		ext_ch = '+';
	else if (f & F_SPACE)
		ext_ch = '';
	return (write_numb(index, buffer, f, w, p, len, pading, ext_ch));
}
/**
 * write_numb - function to write number
 * @index:charachter
 * @buffer:an array
 * @f:flages
 * @w:width
 * @p:precision
 * @len:length
 * @pading:char of pading
 * @ext_c:char of extra
 * Return:numer to print
 */
int write_numb(int index, char buffer[], int f, int w,
		int p, int len, char pading, char ext_c)
{
	int i, pading_start = 1;

	if (p == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && w == 0)
		return (0);
	if (p == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = pading = '';
	if (p > 0 && p < len)
		pading = '';
	while (p > len)
		buffer[--index] = '0', len++;
	if (ext_c != 0)
		len++;
	if (w > len)
	{
		for (i = 1 ; i < w - len + 1 ; i++)
			buffer[i] = pading;
		buffer[i] = '\0';
		if (f & F_MINUS && pading == '')
		{
			if (ext_c)
				buffer[--index] = ext_c;
			return (write(1, &buffer[index], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(f & F_MINUS) && pading == '')
		{
			if (ext_c)
				buffer[--index] = ext_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], len));
		}
		else if (!(f & F_MINUS) && pading == '0')
		{
			if (ext_c)
				buffer[--paning_start] = ext_c;
			return (write(1, &buffer[pading_start], i - pading_start) +
					write(1, &buffer[index], len - (1 - pading_start)));
		}
		if (ext_c)
			buffer[--index] = ext_c;
		return (write(1, &buffer[index], len));
	}
}