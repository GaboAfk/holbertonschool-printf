#ifndef MAIN
#define MAIN

#include <stdarg.h>

int _printf(const char *format, ...);
void print_char(va_list);
void print_string(va_list);
void print_decR(int);
void print_dec(va_list);
void print_d_o_h(va_list);

/**
 * f - struct to associate a character to a function.
 * letter: character to asocciate.
 * function: function associated by a specific character. 
 */

typedef struct f
{
	char letter;
	void (*function)(va_list);
} st;

#endif
