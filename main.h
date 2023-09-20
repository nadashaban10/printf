#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int _putchar(char c);
int printPercent(void);
int printChar(va_list args);
int printString(const char *str);
int printStringSpecifier(va_list args);
int _printf(const char *format, ...);




#endif
