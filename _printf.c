/*
 * File: _printf.c
 * Auth: Gabriel Morffe, Pablo Espinola and Micke Lucas.
 */

#include "main.h"
#include <stdlib.h>

/**
 * _printf - function that produces output according to a format.
 * format: string with diferents formats.
 * Return: 0 (Success), errors diferents numbers (exit).Falta completar estoXD
 */
int _printf(const char *format, ...)
{
	va_list txt;
	int i = 0, j;

	st flags[] = {
		{'%', format_func},
		{'\\', format_cancel},
	/*	{'#', format_cancel},*/
		{'\0', NULL}
	};

	st lts[] =  {
		{'c', print_char},
		{'s', print_sting},
		{'d', print_int},
		{'i', print_int}, /* va_args(txt); */
		{'\0', NULL}
	};

	va_start(txt, format);
	
	while (format && format[i])		/*mientras format existe y contiene algo*/
	{
		j = 0;
		while (flags[j].letter != '\0')
		{
			if (flags[j].letter == format[i])
			{
				if (format[i+1])	
				{
					flags[j].function(txt);

				}
			}
			j++;
		}
		i++;
	}


int format_cancel(char *s, int pos)
{
	st backf[] =  {
		{'\\', print_char}, /*print a backslash*/
		{'\"', print_sting},/*print a " */
		{'\'', print_int}, /*print a ' */
		{'%', print_int},
		{'n', print_int},
		{'\0', NULL}
	};


}

	return (0);
}
