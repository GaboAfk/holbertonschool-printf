#ifndef MAIN
#define MAIN

#include <stdarg.h>

int _printf(const char *format, ...);

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
