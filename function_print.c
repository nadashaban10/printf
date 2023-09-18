#include "main.h"
/**
 *
 *
 *
 */
void buffer_print(char buffer[], int *index_buffer);
{
if (*index_buffer > 0)
	write(1, &buffer[0], *index_buffer);
	*index_buffer = 0;  /*i think its zero to free the memory */

}
