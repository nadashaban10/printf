#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024
int _putchar(char c);
int char_func(va_list list, char buffer[]);
int percentage_func(va_list list, char buffer[]);
int _printf(const char *format, ...);
void buffer_print(char buffer[], int *index_buffer);




#endif
