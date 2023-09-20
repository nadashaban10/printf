#include "main.h"
/**
 * printbinary - print binary num
 * num:unsigned int
 * Return:int number
 */
int printbinary(unsigned int num)
{
	unsigned int x, i, sum = 0;
	unsigned int b[32];
	int j = 0;

	x = 2147483648;
	b[0] = num / x;

	for (i = 1 ; i < 32 ; i++)
	{
		x /= 2;
		b[i] = (num / x) % 2;
	}

	for (i = 0 ; i < 32 ; i++)
	{
		sum = sum + b[i];
		if (sum || i == 31)
		{
			char p = '0' + b[i];

			write(1, &p, 1);
			j++;
		}
	}
	return (j);
}
