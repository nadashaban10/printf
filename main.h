#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define BUFF_SIZE 1024

/* FUNTION PROTOTYPES */

int _printf(const char *format, ...);
int char_func(va_list cases, char buffer[]);
int str_func(va_list cases, char buffer[]);
int percentage_func(va_list cases, char buffer[]);
int num_func(va_list cases, buffer[]);
int binary_func(va_list cases, buffer[]);
void buffer_print(char buffer[], int *index_buffer); /*using in printf file*/
<<<<<<< HEAD
int write_digit(int is_negative, int index, char buffer[], int f, int w, int p, int s);

int write_numb(int index, char buffer[], int f, int w, int p, int len, char pading, char ext_c);
=======
int print_i(va_list cases, char buffer[], int f, int w, int p, int s);
int write_digit(int is_negative, int index, char buffer[],
		int f, int w, int p, int s);
int write_numb(int index, char buffer[], int f, int w,
		int p, int len, char pading, char ext_c);
long int convert_size_digit(long int number, int size);
>>>>>>> 22b23aa0ce803f4401af74c125410808323a569a
#endif
