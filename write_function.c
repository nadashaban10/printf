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
	char pading = ' ', ext_c = 0;

	UNUSED(s);
	if ((f & F_ZERO) && !(f & F_MINUS))
		pading = '0';
	if (is_negative)
		ext_c = '-';
	else if (f & F_PLUS)
		ext_c = '+';
	else if (f & F_SPACE)
		ext_c = ' ';

	return (write_numb(index, buffer, f, w, p, len, pading, ext_c));
}
/**
 * write_numb - function to write number
 * @index:charachter
 * @buffer:an array
 * @f:flages
 * @w:width
 * @p:precision
 * @len:length
 * @pading:char
 * @ext_c:extra char
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
		else if (!(f & F_MINUS) && pading == ' ')
		{
			if (ext_c)
				buffer[--index] = ext_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], len));
		}
		else if (!(f & F_MINUS) && pading == '0')
		{
			if (ext_c)
				buffer[--pading_start] = ext_c;
			return (write(1, &buffer[pading_start], i - pading_start) +
					write(1, &buffer[index], len - (1 - pading_start)));
		}
		if (ext_c)
			buffer[--index] = ext_c;
		return (write(1, &buffer[index], len));
	}
}
/**
 * write_char_ - print char
 * @c:character
 * @buffer:an array
 * @f:flages
 * @w:width
 * @p:precision
 * @s:size
 * Return:a char
 */
int write_char_(char c, char buffer[], int f, int w, int p, int s)
{
	int x = 0;
	int pading = ' ';

	UNUSED(p);
	UNUSED(s);

	if (f & F_ZERO)
		pading = '0';

	buffer[x++] = c;
	buffer[x] = '\0';

	if (w > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (x = 0 ; x < w - 1 ; x++)
			buffer[BUFF_SIZE - x - 2] = pading;
		if (f & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - x - 1], w - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - x - 1], w - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
/**
 * write_unsnum - write unsigned number
 * @is_negative:check if number is negative
 * @index:when we start
 * @buffer:an array
 * @f:flages
 * @w:width
 * @p:precision
 * @s:size
 * Return:unsigned number
 * develop by soria
 */
int write_unsnum(int is_negative, int index, char buffer[],
		int f, int w, int p, int s)
{
	int len = BUFF_SIZE - index - 1, x = 0;
	char pading = ' ';

	UNUSED(is_negative);
	UNUSED(s);
	if (p == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0);
	if (p > 0 && p < len)
		pading = ' ';
	while (p > len)
		buffer[--index] = '0', len++;
	if ((f & F_ZERO) && !(f & F_MINUS))
		pading = '0';

	if (w > len)
	{
		for (x = 0 ; x < w - len ; x++)
			buffer[x] = pading;
		buffer[x] = '\0';

		if (f & F_MINUS)
			return (write(1, &buffer[index], len) + write(1, &buffer[0], x));
		else
			return (write(1, &buffer[0], x) + write(1, &buffer[index], len));
	}
	return (write(1, &buffer[index], len));
}
/**
 * write_point - write a pointer.
 * @buffer:an array
 * @index:when we start
 * @len:length
 * @w:width
 * @f:flages
 * @pading:pading char
 * @ext_c:extra char
 * @pading_start:when pading start
 * Return:a pointer like char
 * develop by soria
 */
int write_point(char buffer[], int index, int len, int w,
		int f, char pading, char ext_c, int pading_start)
{
	int x;

	if (w > len)
	{
		for (x = 3 ; x < w - len + 3 ; x++)
			buffer[x] = pading;
		buffer[x] = '\0';
		if (f & F_MINUS && pading == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (ext_c)
				buffer[--index] = ext_c;
			return (write(1, &buffer[index], len) + write(1, &buffer[3], x - 3));
		}
		else if (!(f & F_MINUS) && pading == '0')
		{
			if (ext_c)
				buffer[--pading_start] = ext_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pading_start], x - pading_start) +
					write(1, &buffer[index], len - (1 - pading_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (ext_c)
		buffer[--index] = ext_c;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}
