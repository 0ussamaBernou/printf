#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_d(int n);
int print_s(char *str);
int print_b(unsigned int n);

#endif /* ifndef MAIN_H  */
