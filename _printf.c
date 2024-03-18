/*
 * File: _printf.c
 * Auth: Gabriel Morffe, Pablo Espinola and Micke Lucas.
 */

#include "main.h"
#include <stdlib.h>
#include <unistd.h>

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
		{'c', print_char},
		{'s', print_string},
		{'d', print_dec},
		{'i', print_dec},
		{'\0', NULL}
	};

	va_start(txt, format);

	if (!format)
		return (-1);

	while (format && format[i])
	{
		if (format[i] == '%')	/* Carlos% */
		{
			i++;
			if (format[i] != '%')
			{
				j = 0;
				while (lts[j].letter != '\0')
				{
					if (format[i] == lts[j].letter)
					{
						res = lts[j].function(txt);
						if (res != 0)
							return (res);
						else
						{
							i++;
							break;
						}
					}
					j++;
				}
				if (lts[j].letter == '\0')
					return (-1);
			}
		}
		write(1, &format[i], sizeof(char));
		i++;
		count++;
	}
	return (count);
}
