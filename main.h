#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define BUFF_SIZE 1024

/* FUNTION PROTOTYPES */

int _printf(const char *format, ...);
int char_func(va_list case, char buffer[]);
int str_func(va_list case, char buffer[]);
int percentage_func(va_list case, char buffer[]);
int num_func(va_list case, buffer[]);
int binary_func(va_list case, buffer[]);
void buffer_print(char buffer[], int *index_buffer); /*using in printf file*/



#endif
