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
int print_i(va_list cases, char buffer[], int f, int w, int p, int s);
int write_digit(int is_negative, int index, char buffer[],
		int f, int w, int p, int s);
int write_numb(int index, char buffer[], int f, int w,
		int p, int len, char pading, char ext_c);
long int convert_size_digit(long int number, int size);
#endif
