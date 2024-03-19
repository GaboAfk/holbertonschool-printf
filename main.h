#ifndef MAIN
#define MAIN

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
int print_char(va_list var);
int print_string(va_list var);
int print_dec(va_list var);
int print_base(va_list var);
int error(va_list var);
/**
 * f - struct to associate a character to a function.
 * letter: character to asocciate.
 * function: function associated by a specific character. 
 */

typedef struct f
{
	char *letter;
	int (*function)(va_list);
} st;

#endif
