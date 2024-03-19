/*
 * File: _printf.c
 * Auth: Gabriel Morffe, Pablo Espinola and Micke Lucas.
 */

#include "main.h"

int print_dec(va_list var);

/**
 * _printf - function that produces output according to a format.
 * @format: string with diferents formats.
 * Return: 0 (Success), errors diferents numbers (exit).Falta completar estoXD
 */
int _printf(const char *format, ...)
{
	va_list txt;
	int i = 0, j, count = 0, res;

	st lts[] =  {
		{"c", print_char},
	/*	{'s', print_string},*/
/*		{'d', print_dec},*/
/*		{'i', print_dec},*/
		{NULL, NULL}
	};

	if (!format)
		return (-1);	/*puntero NULL -> error*/

	va_start(txt, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] != '%')
			{
				j = 0;
				while (lts[j].letter)
				{
					if (*lts[j].letter == format[i])
					{
						res = lts[j].function(txt);
						i++;
						break;
					}
				}
			}
		}
		write(1, &format[i], 1);
		i++;
		count++;
	}
	return (count);
}
