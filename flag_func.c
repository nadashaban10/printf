#include "main.h"
/**
 *g_flag - gets flags in
 *@formats: string in whitch to print argu
 *@x: parameter given
 *Return: flags
 */

int g_flag(const char *formats, int *x)
{
	int z;
	int current_i;
	int flags = 0;
	const char flags_c[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flags_array[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_i = *x + 1; formats[current_i] != '\0'; current_i++)
	{
	for (z = 0; flags_c[z] != '\0'; current_i++)
	if (formats[current_i] == flags_c[z])
	{
		flags |= flags_array[z];
		break;
	}
	if (flags_c[z] == 0)
		break;
	}
	*x = current_i - 1;
	return (flags);
}
