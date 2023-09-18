#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x)(void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 3
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/* FUNTION PROTOTYPES */

int _printf(const char *format, ...);

int percentage_func(va_list cases, char buffer[], int flag, int s_width, int precision, int s_size);
int char_func(va_list cases, char buffer[], int flag, int s_width, int precision, int s_size);
int string_func(va_list cases, char buffer[], int flag, int s_width, int precision, int s_size);


int is_print(char c);
int hexa_num(char asc_code, char buffer[], int x);

int num_func(va_list cases, char buffer[]);
int binary_func(va_list cases, char buffer[]);
void buffer_print(char buffer[], int *index_buffer); /*using in printf file*/
int write_digit(int is_negative, int index, char buffer[], int f, int w, int p, int s);
int write_char_(char c, char buffer[], int f, int w, int p, int s);
int write_numb(int index, char buffer[], int f, int w, int p, int len, char pading, char ext_c);
int print_i(va_list cases, char buffer[], int f, int w, int p, int s);

long int convert_size_digit(long int number, int size);
int is_fun_digit(char x);
int get_w(const char *format, int *x, va_list arr);
int get_s(const char *format, int *x);
#endif
